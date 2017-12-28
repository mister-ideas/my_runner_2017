/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.h
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

typedef struct runner {
	sfRenderWindow *window;
	sfEvent event;
} runner_t;

typedef struct object {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f *pos;
	sfVector2f *move;
	sfIntRect *rect;
} object_t;

void destroy_obj(object_t *object);

object_t *new_obj(char *path, sfVector2f pos, sfVector2f move, sfIntRect rect);

#endif
