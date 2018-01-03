/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

int init_parallax(parallax_t *parallax)
{
	if (init_back(parallax) == 1)
		return (1);
	if (init_m1(parallax) ==  1)
		return (1);
	if (init_m2(parallax) == 1)
		return (1);
	if (init_m3(parallax) == 1)
		return (1);
	if (init_road(parallax) == 1)
		return (1);
	return (0);
}

int game_init(runner_t *runner, parallax_t *parallax)
{
	if (init_parallax(parallax) == 1)
		return (1);
	sfRenderWindow_setMouseCursorVisible(runner->window, sfFalse);
	sfRenderWindow_setFramerateLimit(runner->window, 60);
	return (0);
}
