/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** objects.c
*/

#include "my_runner.h"

int init_clock(objects_t *objects)
{
	objects->clock_t = sfTexture_createFromFile(CLOCK_PATH, NULL);
	if (!objects->clock_t)
		return (1);
	objects->clock_s = sfSprite_create();
	sfSprite_setTexture(objects->clock_s, objects->clock_t, sfTrue);
	objects->clock_p.x = 1700;
	objects->clock_p.y = 20;
	objects->clock_m.x = 0;
	sfSprite_setPosition(objects->clock_s, objects->clock_p);
	return (0);
}

int init_character(objects_t *objects)
{
	objects->char_r.top = 0;
	objects->char_r.left = 0;
	objects->char_r.width = 74;
	objects->char_r.height = 70;
	objects->char_t = sfTexture_createFromFile(CHAR_PATH, NULL);
	if (!objects->char_t)
		return (1);
	objects->char_s = sfSprite_create();
	sfSprite_setTexture(objects->char_s, objects->char_t, sfTrue);
	objects->char_p.x = 180;
	objects->char_p.y = 920;
	objects->char_m.x = 0;
	sfSprite_setPosition(objects->char_s, objects->char_p);
	return (0);
}

int init_obstacle1(objects_t *objects)
{
	objects->obst1_r.top = 0;
	objects->obst1_r.left = 0;
	objects->obst1_r.width = 70;
	objects->obst1_r.height = 70;
	objects->obst1_t = sfTexture_createFromFile(OBST1_PATH, NULL);
	if (!objects->obst1_t)
		return (1);
	objects->obst1_s = sfSprite_create();
	sfSprite_setTexture(objects->obst1_s, objects->obst1_t, sfTrue);
	objects->obst1_m.x = -8;
	return (0);
}

int init_obstacle2(objects_t *objects)
{
	objects->obst2_r.top = 0;
	objects->obst2_r.left = 0;
	objects->obst2_r.width = 70;
	objects->obst2_r.height = 70;
	objects->obst2_t = sfTexture_createFromFile(OBST2_PATH, NULL);
	if (!objects->obst2_t)
		return (1);
	objects->obst2_s = sfSprite_create();
	sfSprite_setTexture(objects->obst2_s, objects->obst2_t, sfTrue);
	objects->obst2_m.x = -8;
	return (0);
}
