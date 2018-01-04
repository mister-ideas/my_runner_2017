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

void check_keys(runner_t *runner, objects_t *objects)
{
	while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
		if (runner->event.type == sfEvtClosed
		|| (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeyEscape))
			sfRenderWindow_close(runner->window);
		if (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeySpace
		&& objects->char_p.y == 930)
			objects->char_m.y = -8;
	}
}

void check_layers(parallax_t *parallax)
{
	parallax->back_p = sfSprite_getPosition(parallax->back_s);
	parallax->m1_p = sfSprite_getPosition(parallax->m1_s);
	parallax->m2_p = sfSprite_getPosition(parallax->m2_s);
	parallax->m3_p = sfSprite_getPosition(parallax->m3_s);
	parallax->road_p = sfSprite_getPosition(parallax->road_s);
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
	if (parallax->road_p.x < -1920)
		parallax->road_p.x = 0;
	sfSprite_setPosition(parallax->road_s, parallax->road_p);
}

void check_character(objects_t *objects)
{
	objects->char_p = sfSprite_getPosition(objects->char_s);
	if (objects->char_p.y < 730)
		objects->char_m.y = 4;
	if (objects->char_p.y > 930) {
		objects->char_m.y = 0;
		objects->char_p.y = 930;
		sfSprite_setPosition(objects->char_s, objects->char_p);
	}
}

void check_events(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	check_keys(runner, objects);
	check_layers(parallax);
	check_character(objects);
}
