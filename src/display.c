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
	sfRenderWindow_drawSprite(runner->window, objects->char_s, NULL);
	sfRenderWindow_display(runner->window);
}

void finished_text(runner_t *runner)
{
	my_putstr("====================\n");
	my_putstr("Final score: ");
	my_put_nbr(runner->score);
	my_putchar('\n');
	my_putstr("====================\n");
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
