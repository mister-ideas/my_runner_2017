/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** objects.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

int init_character(objects_t *objects)
{
	objects->char_rect.top = 0;
	objects->char_rect.left = 330;
	objects->char_rect.width = 86;
	objects->char_rect.height = 86;
	objects->char_t = sfTexture_createFromFile(CHAR_PATH, NULL);
	if (!objects->char_t)
		return (1);
	objects->char_s = sfSprite_create();
	sfSprite_setTexture(objects->char_s, objects->char_t, sfTrue);
	objects->char_p.x = 180;
	objects->char_p.y = 920;
	sfSprite_setPosition(objects->char_s, objects->char_p);
	return (0);
}
