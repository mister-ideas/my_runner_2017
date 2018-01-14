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
	sfRenderWindow_drawSprite(runner->window, objects->clock_s, NULL);
	sfRenderWindow_drawText(runner->window, runner->score_text, NULL);
	sfRenderWindow_drawSprite(runner->window, objects->obst1_s, NULL);
	sfRenderWindow_drawSprite(runner->window, objects->obst2_s, NULL);
	sfRenderWindow_drawSprite(runner->window, objects->char_s, NULL);
	if (runner->status == 1)
		sfRenderWindow_drawSprite(runner->window, runner->win_s, NULL);
	if (runner->status == 2)
		sfRenderWindow_drawSprite(runner->window, runner->over_s, NULL);
	sfRenderWindow_display(runner->window);
}

void game_over(parallax_t *parallax, objects_t *objects)
{
	sfSprite_setColor(parallax->back_s, sfRed);
	sfSprite_setColor(parallax->m1_s, sfRed);
	sfSprite_setColor(parallax->m2_s, sfRed);
	sfSprite_setColor(parallax->m3_s, sfRed);
	sfSprite_setColor(parallax->road_s, sfRed);
	sfSprite_setColor(objects->char_s, sfRed);
	sfSprite_setColor(objects->obst1_s, sfTransparent);
	sfSprite_setColor(objects->obst2_s, sfTransparent);
	parallax->back_m.x = 0;
	parallax->m1_m.x = 0;
	parallax->m2_m.x = 0;
	parallax->m3_m.x = 0;
	parallax->road_m.x = 0;
	objects->char_m.y = 0;
}

void win(parallax_t *parallax, objects_t *objects)
{
	sfSprite_setColor(parallax->back_s, sfGreen);
	sfSprite_setColor(parallax->m1_s, sfGreen);
	sfSprite_setColor(parallax->m2_s, sfGreen);
	sfSprite_setColor(parallax->m3_s, sfGreen);
	sfSprite_setColor(parallax->road_s, sfGreen);
	sfSprite_setColor(objects->char_s, sfGreen);
	sfSprite_setColor(objects->obst1_s, sfTransparent);
	sfSprite_setColor(objects->obst2_s, sfTransparent);
	parallax->back_m.x = 0;
	parallax->m1_m.x = 0;
	parallax->m2_m.x = 0;
	parallax->m3_m.x = 0;
	parallax->road_m.x = 0;
	objects->char_m.y = 0;
}

void closed_text(void)
{
	my_putstr("====================\n");
	my_putstr("You left the game!");
	my_putchar('\n');
	my_putstr("====================\n");
}

void help_text(void)
{
	my_putstr("======================\n");
	my_putstr("	Runner\n");
	my_putstr("======================\n\n");
	my_putstr("USAGE\n");
	my_putstr("	./my_runner map.legend\n\n");
	my_putstr("OPTIONS\n");
	my_putstr("	-h	Print usage and exit.\n\n");
	my_putstr("Don't forget to read the 'README' file for more info!\n");
}
