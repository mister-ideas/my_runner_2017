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

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Runner!", sfClose, NULL);
	return (window);
}

void window_display(runner_t *runner, parallax_t *parallax)
{
	sfRenderWindow_clear(runner->window, sfBlack);
	sfRenderWindow_drawSprite(runner->window, parallax->back_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->mid_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->top_s, NULL);
	sfRenderWindow_display(runner->window);
}

void game_free(runner_t *runner, parallax_t *parallax)
{
	sfTexture_destroy(parallax->back_t);
	sfTexture_destroy(parallax->mid_t);
	sfTexture_destroy(parallax->top_t);
	sfSprite_destroy(parallax->back_s);
	sfSprite_destroy(parallax->mid_s);
	sfSprite_destroy(parallax->top_s);
	sfRenderWindow_destroy(runner->window);
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
	if (init_parallax(&parallax) == 1)
		return (84);
	while (sfRenderWindow_isOpen(runner.window)) {
		check_events(&runner);
		window_display(&runner, &parallax);
	}
	game_free(&runner, &parallax);
	return (0);
}
