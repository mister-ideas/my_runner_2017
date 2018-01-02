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
	sfRenderWindow_drawSprite(runner->window, parallax->m1_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->m2_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->m3_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->road_s, NULL);
	sfRenderWindow_display(runner->window);
}

void game_free(runner_t *runner, parallax_t *parallax)
{
	sfTexture_destroy(parallax->back_t);
	sfTexture_destroy(parallax->m1_t);
	sfTexture_destroy(parallax->m2_t);
	sfTexture_destroy(parallax->m3_t);
	sfTexture_destroy(parallax->road_t);
	sfSprite_destroy(parallax->back_s);
	sfSprite_destroy(parallax->m1_s);
	sfSprite_destroy(parallax->m2_s);
	sfSprite_destroy(parallax->m3_s);
	sfSprite_destroy(parallax->road_s);
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
	sfRenderWindow_setMouseCursorVisible(runner.window, sfFalse);
	sfRenderWindow_setFramerateLimit(runner.window, 60);
	while (sfRenderWindow_isOpen(runner.window)) {
		check_events(&runner, &parallax);
		sfSprite_move(parallax.back_s, parallax.back_m);
		sfSprite_move(parallax.m1_s, parallax.m1_m);
		sfSprite_move(parallax.m2_s, parallax.m2_m);
		sfSprite_move(parallax.m3_s, parallax.m3_m);
		sfSprite_move(parallax.road_s, parallax.road_m);
		window_display(&runner, &parallax);
	}
	game_free(&runner, &parallax);
	return (0);
}
