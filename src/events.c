/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** events.c
*/

#include "my_runner.h"

void check_keys(runner_t *runner, objects_t *objects)
{
	while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
		if (runner->event.type == sfEvtClosed
		|| (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeyEscape)) {
			sfRenderWindow_close(runner->window);
			closed_text();
		}
		if (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeySpace
		&& objects->char_p.y == 920) {
			objects->char_m.y = -6;
			sfMusic_play(runner->m_jump);
		}
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

void check_position(objects_t *objects)
{
	objects->char_p = sfSprite_getPosition(objects->char_s);
	objects->obst1_p = sfSprite_getPosition(objects->obst1_s);
	objects->obst2_p = sfSprite_getPosition(objects->obst2_s);
	if (objects->char_p.y < 780)
		objects->char_m.y = 6;
	if (objects->char_p.y > 920) {
		objects->char_m.y = 0;
		objects->char_p.y = 920;
		sfSprite_setPosition(objects->char_s, objects->char_p);
	}
	//if (objects->obst1_p.x < -70) {
	//objects->obst1_p.x = 1920;
	//sfSprite_setPosition(objects->obst1_s, objects->obst1_p);
	//}
//if (objects->obst2_p.x < -70) {
//objects->obst2_p.x = 1920;
//sfSprite_setPosition(objects->obst2_s, objects->obst2_p);
//}
}

void check_collision(objects_t *objects)
{
	if (((objects->char_p.x + 74 > objects->obst1_p.x
	&& objects->char_p.x + 74 < objects->obst1_p.x + 70)
	&& (objects->char_p.y + 70 > objects->obst1_p.y
	&& objects->char_p.y + 70 < objects->obst1_p.y + 70))
	|| ((objects->char_p.x > objects->obst1_p.x
	&& objects->char_p.x < objects->obst1_p.x + 70)
	&& (objects->char_p.y + 70 > objects->obst1_p.y
	&& objects->char_p.y + 70 < objects->obst1_p.y + 70)
	&& (objects->char_p.y < 920)))
		objects->obst1_m.x = 0;
	if (((objects->char_p.x + 74 > objects->obst2_p.x
	&& objects->char_p.x + 74 < objects->obst2_p.x + 70)
	&& (objects->char_p.y + 70 > objects->obst2_p.y
	&& objects->char_p.y + 70 < objects->obst2_p.y + 70))
	|| ((objects->char_p.x > objects->obst2_p.x
	&& objects->char_p.x < objects->obst2_p.x + 70)
	&& (objects->char_p.y + 70 > objects->obst2_p.y
	&& objects->char_p.y + 70 < objects->obst2_p.y + 70)
	&& (objects->char_p.y < 920)))
		objects->obst2_m.x = 0;
}
