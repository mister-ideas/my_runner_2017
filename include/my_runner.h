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

typedef struct parallax {
	sfSprite *back_s;
	sfTexture *back_t;
	sfVector2f back_p;
	sfSprite *mid_s;
	sfTexture *mid_t;
	sfVector2f mid_p;
	sfSprite *top_s;
	sfTexture *top_t;
	sfVector2f top_p;
} parallax_t;

void check_events(runner_t *runner);

sfRenderWindow *window_create(unsigned int width, unsigned int height);

#endif
