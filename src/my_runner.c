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

int main(int ac, char **av)
{
	runner_t runner;

	runner.window = window_create(1920, 1080);
	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (1);
	while (sfRenderWindow_isOpen(runner.window)) {
		check_events(&runner);
		sfRenderWindow_clear(runner.window, sfBlack);
		sfRenderWindow_display(runner.window);
	}
	return (0);
}
