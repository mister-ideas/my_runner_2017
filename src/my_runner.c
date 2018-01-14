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
	check_collision(runner, objects->char_p, objects->obst1_p);
	check_collision(runner, objects->char_p, objects->obst2_p);
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
	clocks(runner, objects);
	window_display(runner, parallax, objects);
}

int check_map(runner_t *runner, char **av)
{
	FILE* file = NULL;
	size_t buff_size = 100;

	file = fopen(av[1], "r");
	if (!file)
		return (1);
	runner->first_floor = malloc(sizeof(char) * 100);
	runner->second_floor = malloc(sizeof(char) * 100);
	getline(&runner->second_floor, &buff_size, file);
	getline(&runner->first_floor, &buff_size, file);
	fclose(file);
	return (0);
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
	if (check_map(&runner, av) == 1)
		return (84);
	while (sfRenderWindow_isOpen(runner.window))
		game_loop(&runner, &parallax, &objects);
	game_free(&runner, &parallax, &objects);
	return (0);
}
