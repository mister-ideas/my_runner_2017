/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** events.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

void check_window(runner_t *runner)
{
	while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
		if (runner->event.type == sfEvtClosed
		|| (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeyEscape))
			sfRenderWindow_close(runner->window);
	}
}

void check_layers(parallax_t *parallax)
{
	parallax->back_p = sfSprite_getPosition(parallax->back_s);
	parallax->m1_p = sfSprite_getPosition(parallax->m1_s);
	parallax->m2_p = sfSprite_getPosition(parallax->m2_s);
	parallax->m3_p = sfSprite_getPosition(parallax->m3_s);
	if (parallax->back_p.x < -1920)
		parallax->back_p.x = 0;
	sfSprite_setPosition(parallax->back_s, parallax->back_p);
	if (parallax->m1_p.x < -1920)
		parallax->m1_p.x = 0;
	sfSprite_setPosition(parallax->m1_s, parallax->m1_p);
	if (parallax->m2_p.x < -1920)
		parallax->m2_p.x = 0;
	sfSprite_setPosition(parallax->m2_s, parallax->m2_p);
	if (parallax->m3_p.x < -1920)
		parallax->m3_p.x = 0;
	sfSprite_setPosition(parallax->m3_s, parallax->m3_p);
}

void check_events(runner_t *runner, parallax_t *parallax)
{
	check_window(runner);
	check_layers(parallax);
}
