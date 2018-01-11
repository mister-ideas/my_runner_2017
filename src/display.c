/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** display.c
*/

#include "my_runner.h"

void window_display(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	sfRenderWindow_clear(runner->window, sfBlack);
	sfRenderWindow_drawSprite(runner->window, parallax->back_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->m1_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->m2_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->m3_s, NULL);
	sfRenderWindow_drawSprite(runner->window, parallax->road_s, NULL);
	sfRenderWindow_drawSprite(runner->window, objects->obst_s, NULL);
	sfRenderWindow_drawSprite(runner->window, objects->char_s, NULL);
	sfRenderWindow_display(runner->window);
}
