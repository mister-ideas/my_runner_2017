/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.h
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#define BACK_PATH "ressources/img/back.jpg"
#define M1_PATH "ressources/img/m1.png"
#define M2_PATH "ressources/img/m2.png"
#define M3_PATH "ressources/img/m3.png"
#define ROAD_PATH "ressources/img/road.png"

typedef struct runner {
	sfRenderWindow *window;
	sfEvent event;
} runner_t;

typedef struct parallax {
	sfSprite *back_s;
	sfSprite *m1_s;
	sfSprite *m2_s;
	sfSprite *m3_s;
	sfSprite *road_s;
	sfTexture *back_t;
	sfTexture *m1_t;
	sfTexture *m2_t;
	sfTexture *m3_t;
	sfTexture *road_t;
	sfVector2f back_p;
	sfVector2f m1_p;
	sfVector2f m2_p;
	sfVector2f m3_p;
	sfVector2f road_p;
	sfVector2f back_m;
	sfVector2f m1_m;
	sfVector2f m2_m;
	sfVector2f m3_m;
	sfVector2f road_m;
} parallax_t;

void check_events(runner_t *runner, parallax_t *parallax);
void window_display(runner_t *runner, parallax_t *parallax);
void game_free(runner_t *runner, parallax_t *parallax);

int init_parallax(parallax_t *parallax);

sfRenderWindow *window_create(unsigned int width, unsigned int height);

#endif
