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
	check_objects(objects);
}

void game_loop(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	check_events(runner, parallax, objects);
	sfSprite_move(parallax->back_s, parallax->back_m);
	sfSprite_move(parallax->m1_s, parallax->m1_m);
	sfSprite_move(parallax->m2_s, parallax->m2_m);
	sfSprite_move(parallax->m3_s, parallax->m3_m);
	sfSprite_move(parallax->road_s, parallax->road_m);
	sfSprite_move(objects->char_s, objects->char_m);
	sfSprite_move(objects->obst_s, objects->obst_m);
	sfSprite_setTextureRect(objects->char_s, objects->char_r);
	sfSprite_setTextureRect(objects->obst_s, objects->obst_r);
	runner->time = sfClock_getElapsedTime(runner->clock);
	runner->seconds = runner->time.microseconds / 1000000.0;
	if (runner->seconds > 0.05) {
		if (objects->char_r.left < 920)
			objects->char_r.left += 84;
		else
			objects->char_r.left = 0;
		if (objects->obst_r.left < 300)
			objects->obst_r.left += 100;
		else
			objects->obst_r.left = 0;
		sfClock_restart(runner->clock);
	}
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
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (0);
	if (game_init(&runner, &parallax, &objects) == 1)
		return (84);
	while (sfRenderWindow_isOpen(runner.window))
		game_loop(&runner, &parallax, &objects);
	game_free(&runner, &parallax, &objects);
	return (0);
}
