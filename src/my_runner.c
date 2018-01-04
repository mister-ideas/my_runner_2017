/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

void game_loop(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	check_events(runner, parallax, objects);
	sfSprite_move(parallax->back_s, parallax->back_m);
	sfSprite_move(parallax->m1_s, parallax->m1_m);
	sfSprite_move(parallax->m2_s, parallax->m2_m);
	sfSprite_move(parallax->m3_s, parallax->m3_m);
	sfSprite_move(parallax->road_s, parallax->road_m);
	sfSprite_move(objects->char_s, objects->char_m);
	sfSprite_setTextureRect(objects->char_s, objects->char_rect);
	runner->time = sfClock_getElapsedTime(runner->clock);
	runner->seconds = runner->time.microseconds / 1000000.0;
	if (runner->seconds > 0.06) {
		if (objects->char_rect.left > 420)
			objects->char_rect.left -= 82;
		else
			objects->char_rect.left = 830;
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
