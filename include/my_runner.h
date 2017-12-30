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
	sfVector2f back_m;
	sfSprite *mid_s;
	sfTexture *mid_t;
	sfVector2f mid_p;
	sfVector2f mid_m;
	sfSprite *top_s;
	sfTexture *top_t;
	sfVector2f top_p;
	sfVector2f top_m;
} parallax_t;

void check_events(runner_t *runner);
void window_display(runner_t *runner, parallax_t *parallax);
void game_free(runner_t *runner, parallax_t *parallax);

int init_back(parallax_t *parallax, const char* path);
int init_mid(parallax_t *parallax, const char* path);
int init_top(parallax_t *parallax, const char* path);
int init_parallax(parallax_t *parallax);

sfRenderWindow *window_create(unsigned int width, unsigned int height);

#endif
