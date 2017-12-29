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
	sfVector2f pos;
	sfVector2f move;
	sfIntRect rect;
} runner_t;

typedef struct object {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f *pos;
	sfVector2f *move;
	sfIntRect *rect;
} object_t;

void check_events(runner_t *runner);
void destroy_obj(object_t *object);

sfRenderWindow *window_create(unsigned int width, unsigned int height);
object_t *new_obj(char *path, sfVector2f pos, sfVector2f move, sfIntRect rect);

#endif
