/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

void game_loop(runner_t *runner, parallax_t *parallax)
{
	check_events(runner, parallax);
	sfSprite_move(parallax->back_s, parallax->back_m);
	sfSprite_move(parallax->m1_s, parallax->m1_m);
	sfSprite_move(parallax->m2_s, parallax->m2_m);
	sfSprite_move(parallax->m3_s, parallax->m3_m);
	sfSprite_move(parallax->road_s, parallax->road_m);
	window_display(runner, parallax);
}

int main(int ac, char **av)
{
	runner_t runner;
	parallax_t parallax;

	runner.window = window_create(1920, 1080);
	if (!runner.window)
		return (84);
	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (0);
	if (game_init(&runner, &parallax) == 1)
		return (84);
	while (sfRenderWindow_isOpen(runner.window))
		game_loop(&runner, &parallax);
	game_free(&runner, &parallax);
	return (0);
}
