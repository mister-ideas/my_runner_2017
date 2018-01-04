/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
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

int init_objects(objects_t *objects)
{
	if (init_character(objects) == 1)
		return (1);
	return (0);
}

int init_music(runner_t *runner)
{
	runner->m_back = sfMusic_createFromFile(M_BACK_PATH);
	if (!runner->m_back)
		return (1);
	sfMusic_setLoop(runner->m_back, sfTrue);
	sfMusic_play(runner->m_back);
	return (0);
}

int game_init(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	if (init_parallax(parallax) == 1)
		return (1);
	if (init_objects(objects) == 1)
		return (1);
	if (init_music(runner) == 1)
		return (1);
	runner->clock = sfClock_create();
	sfRenderWindow_setMouseCursorVisible(runner->window, sfFalse);
	sfRenderWindow_setFramerateLimit(runner->window, 60);
	return (0);
}
