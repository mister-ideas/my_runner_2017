/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** objects.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

object_t *new_obj(const char *path, sfVector2f pos, sfIntRect rect)
{
	object_t *object = malloc(sizeof(object));

	object->texture = sfTexture_createFromFile(path, NULL);
	if (!object->texture)
		return (NULL);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setTextureRect(object->sprite, rect);
	sfSprite_setPosition(object->sprite, pos);
	return (object);
}

void destroy_obj(object_t *object)
{
	sfTexture_destroy(object->texture);
	sfSprite_destroy(object->sprite);
	free(object);
}
