/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** init.c
*/

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
	if (init_clock(objects) == 1)
		return (1);
	if (init_character(objects) == 1)
		return (1);
	if (init_obstacle1(objects) == 1)
		return (1);
	if (init_obstacle2(objects) == 1)
		return (1);
	return (0);
}

int init_misc(objects_t *objects, runner_t *runner)
{
	runner->m_back = sfMusic_createFromFile(M_BACK_PATH);
	if (!runner->m_back)
		return (1);
	sfMusic_setLoop(runner->m_back, sfTrue);
	sfMusic_play(runner->m_back);
	runner->m_jump = sfMusic_createFromFile(M_JUMP_PATH);
	if (!runner->m_jump)
		return (1);
	objects->first_floor_p.x = 900;
	objects->first_floor_p.y = 930;
	objects->second_floor_p.x = 900;
	objects->second_floor_p.y = 860;
	runner->score = 0;
	runner->score_text_p.x = 1780;
	runner->score_text_p.y = 25;
	runner->font = sfFont_createFromFile(FONT_PATH);
	if (!runner->font)
		return (1);
	return (0);
}

int game_init(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	if (init_parallax(parallax) == 1)
		return (1);
	if (init_objects(objects) == 1)
		return (1);
	if (init_misc(objects, runner) == 1)
		return (1);
	runner->score_text = sfText_create();
	runner->clock1 = sfClock_create();
	runner->clock2 = sfClock_create();
	runner->clock3 = sfClock_create();
	sfRenderWindow_setMouseCursorVisible(runner->window, sfFalse);
	sfRenderWindow_setFramerateLimit(runner->window, 60);
	return (0);
}
