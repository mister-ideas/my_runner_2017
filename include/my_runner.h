/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my_runner.h
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "my.h"

#define BACK_PATH "ressources/img/back.jpg"
#define M1_PATH "ressources/img/m1.png"
#define M2_PATH "ressources/img/m2.png"
#define M3_PATH "ressources/img/m3.png"
#define ROAD_PATH "ressources/img/road.png"
#define CHAR_PATH "ressources/img/character.png"
#define OBST_PATH "ressources/img/obstacle.png"

#define M_BACK_PATH "ressources/music/back.wav"
#define M_JUMP_PATH "ressources/music/jump.wav"
#define M_LOSE_PATH "ressources/music/lose.wav"

typedef struct runner {
	sfRenderWindow *window;
	sfEvent event;
	sfMusic *m_back;
	sfMusic *m_jump;
	sfClock *clock;
	sfTime time;
	float seconds;
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

typedef struct objects {
	sfSprite *char_s;
	sfSprite *obst_s;
	sfTexture *char_t;
	sfTexture *obst_t;
	sfVector2f char_p;
	sfVector2f obst_p;
	sfVector2f char_m;
	sfVector2f obst_m;
	sfIntRect char_r;
	sfIntRect obst_r;
} objects_t;

/* my_runner.c */

void game_loop(runner_t *runner, parallax_t *parallax, objects_t *objects);
void check_events(runner_t *runner, parallax_t *parallax, objects_t *objects);

/* init.c */

int init_parallax(parallax_t *parallax);
int init_objects(objects_t *objects);
int init_music(runner_t *runner);
int game_init(runner_t *runner, parallax_t *parallax, objects_t *objects);

/* parallax.c */

int init_back(parallax_t *parallax);
int init_m1(parallax_t *parallax);
int init_m2(parallax_t *parallax);
int init_m3(parallax_t *parallax);
int init_road(parallax_t *parallax);

/* objects.c */

int init_character(objects_t *objects);
int init_obstacle(objects_t *objects);

/* events.c */

void check_keys(runner_t *runner, objects_t *objects);
void check_layers(parallax_t *parallax);
void check_objects(objects_t *objects);

/* display.c */

void window_display(runner_t *runner, parallax_t *parallax, objects_t *objects);

/* tools.c */

sfRenderWindow *window_create(unsigned int width, unsigned int height);
void game_free(runner_t *runner, parallax_t *parallax, objects_t *objects);

#endif
