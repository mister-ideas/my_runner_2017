/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.c
*/

#include "my_runner.h"

void check_events(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	check_keys(runner, objects);
	check_layers(parallax);
	check_position(objects);
	check_collision(objects);
}

void clock(runner_t *runner, objects_t *objects)
{
	runner->time1 = sfClock_getElapsedTime(runner->clock1);
	runner->seconds1 = runner->time1.microseconds / 1000000.0;
	if (runner->seconds1 > 0.04) {
		if (objects->char_r.left > 250)
			objects->char_r.left -= 82;
		else
			objects->char_r.left = 830;
		sfClock_restart(runner->clock1);
	}
	runner->time2 = sfClock_getElapsedTime(runner->clock2);
	runner->seconds2 = runner->time2.microseconds / 1000000.0;
	if (runner->seconds2 > 0.5) {
		if (objects->obst1_r.left < 70)
			objects->obst1_r.left += 70;
		else
			objects->obst1_r.left = 0;
		if (objects->obst2_r.left < 70)
			objects->obst2_r.left += 70;
		else
			objects->obst2_r.left = 0;
		sfClock_restart(runner->clock2);
	}
	runner->time3 = sfClock_getElapsedTime(runner->clock3);
	runner->seconds3 = runner->time3.microseconds / 1000000.0;
	if (runner->seconds3 > 1) {
		runner->score++;
		sfClock_restart(runner->clock3);
	}
}

void game_loop(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	char score[12];

	check_events(runner, parallax, objects);
	convert_score(score, runner->score);
	set_score_text(score, runner);
	sfSprite_move(parallax->back_s, parallax->back_m);
	sfSprite_move(parallax->m1_s, parallax->m1_m);
	sfSprite_move(parallax->m2_s, parallax->m2_m);
	sfSprite_move(parallax->m3_s, parallax->m3_m);
	sfSprite_move(parallax->road_s, parallax->road_m);
	sfSprite_move(objects->char_s, objects->char_m);
	sfSprite_move(objects->obst1_s, objects->obst1_m);
	sfSprite_move(objects->obst2_s, objects->obst2_m);
	sfSprite_setTextureRect(objects->char_s, objects->char_r);
	sfSprite_setTextureRect(objects->obst1_s, objects->obst1_r);
	sfSprite_setTextureRect(objects->obst2_s, objects->obst2_r);
	clock(runner, objects);
	window_display(runner, parallax, objects);
}

int main(int ac, char **av)
{
	runner_t runner;
	parallax_t parallax;
	objects_t objects;

	runner.window = window_create(1920, 1080);
	if (!runner.window)
		return (84);
	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h') {
		help_text();
		return (0);
	}
	if (game_init(&runner, &parallax, &objects) == 1)
		return (84);
	while (sfRenderWindow_isOpen(runner.window))
		game_loop(&runner, &parallax, &objects);
	game_free(&runner, &parallax, &objects);
	return (0);
}
