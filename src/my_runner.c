/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Runner!", sfClose, NULL);
	return (window);
}

object_t *new_obj(char *path, sfVector2f pos, sfVector2f move, sfIntRect rect)
{
	object_t *object = malloc(sizeof(object));

	object->texture = sfTexture_createFromFile(path, NULL);
	if (!object->texture)
		return (NULL);
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setTextureRect(object->sprite, rect);
	sfSprite_setPosition(object->sprite, pos);
	sfSprite_move(object->sprite, move);
	return (object);
}

void destroy_obj(object_t *object)
{
	sfTexture_destroy(object->texture);
	sfSprite_destroy(object->sprite);
	free(object);
}

void check_events(runner_t *runner)
{
	while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
		if (runner->event.type == sfEvtClosed
		|| (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeyEscape))
			sfRenderWindow_close(runner->window);
	}
}

int main(int ac, char **av)
{
	runner_t runner;

	runner.window = window_create(1920, 1080);
	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (1);
	while (sfRenderWindow_isOpen(runner.window)) {
		check_events(&runner);
		sfRenderWindow_clear(runner.window, sfBlack);
		sfRenderWindow_display(runner.window);
	}
	return (0);
}
