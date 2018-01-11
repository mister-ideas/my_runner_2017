/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** objects.c
*/

#include "my_runner.h"

int init_character(objects_t *objects)
{
	objects->char_r.top = 0;
	objects->char_r.left = 0;
	objects->char_r.width = 86;
	objects->char_r.height = 86;
	objects->char_t = sfTexture_createFromFile(CHAR_PATH, NULL);
	if (!objects->char_t)
		return (1);
	objects->char_s = sfSprite_create();
	sfSprite_setTexture(objects->char_s, objects->char_t, sfTrue);
	objects->char_p.x = 180;
	objects->char_p.y = 930;
	objects->char_m.x = 0;
	sfSprite_setPosition(objects->char_s, objects->char_p);
	return (0);
}

int init_obstacle(objects_t *objects)
{
	objects->obst_r.top = 0;
	objects->obst_r.left = 0;
	objects->obst_r.width = 100;
	objects->obst_r.height = 104;
	objects->obst_t = sfTexture_createFromFile(OBST_PATH, NULL);
	if (!objects->obst_t)
		return (1);
	objects->obst_s = sfSprite_create();
	sfSprite_setTexture(objects->obst_s, objects->obst_t, sfTrue);
	objects->obst_p.x = 1920;
	objects->obst_p.y = 925;
	objects->obst_m.x = -8;
	sfSprite_setPosition(objects->obst_s, objects->obst_p);
	return (0);
}
