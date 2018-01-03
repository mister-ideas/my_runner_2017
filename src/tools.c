/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** tools.c
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
