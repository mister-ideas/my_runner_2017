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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
#define OBST1_PATH "ressources/img/obstacle1.png"
#define OBST2_PATH "ressources/img/obstacle2.png"
#define CLOCK_PATH "ressources/img/clock.png"
#define GAME_OVER_PATH "ressources/img/game_over.png"
#define WIN_PATH "ressources/img/win.png"

#define M_BACK_PATH "ressources/music/back.ogg"
#define M_JUMP_PATH "ressources/music/jump.wav"
#define M_LOSE_PATH "ressources/music/lose.wav"
#define FONT_PATH "ressources/font/XpressiveRegular.ttf"

typedef struct runner {
	int status;
	char *first_floor;
	char *second_floor;
	sfRenderWindow *window;
	sfEvent event;
	sfMusic *m_back;
	sfMusic *m_jump;
	sfMusic *m_lose;
	int score;
	sfFont *font;
	sfText *score_text;
	sfTexture *over_t;
	sfTexture *win_t;
	sfSprite *over_s;
	sfSprite *win_s;
	sfVector2f score_text_p;
	sfClock *clock1;
	sfClock *clock2;
	sfClock *clock3;
	sfTime time1;
	sfTime time2;
	sfTime time3;
	float seconds1;
	float seconds2;
	float seconds3;
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
	sfSprite *obst1_s;
	sfSprite *obst2_s;
	sfSprite *clock_s;
	sfTexture *char_t;
	sfTexture *obst1_t;
	sfTexture *obst2_t;
	sfTexture *clock_t;
	sfVector2f first_floor_p;
	sfVector2f second_floor_p;
	sfVector2f char_p;
	sfVector2f obst1_p;
	sfVector2f obst2_p;
	sfVector2f clock_p;
	sfVector2f char_m;
	sfVector2f obst1_m;
	sfVector2f obst2_m;
	sfVector2f clock_m;
	sfIntRect char_r;
	sfIntRect obst1_r;
	sfIntRect obst2_r;
	sfIntRect inter;
} objects_t;

/* my_runner.c */

void check_status(runner_t *runner, parallax_t *parallax, objects_t *objects);
void check_events(runner_t *runner, parallax_t *parallax, objects_t *objects);
void game_loop(runner_t *runner, parallax_t *parallax, objects_t *objects);
int check_map(runner_t *runner, char **av);

/* clocks.c */

void score_clock(runner_t *runner);
void character_clock(runner_t *runner, objects_t *objects);
void obstacles_clock(runner_t *runner, objects_t *objects);
void clocks(runner_t *runner, objects_t *objects);

/* init.c */

int init_parallax(parallax_t *parallax);
int init_objects(objects_t *objects);
int init_misc(objects_t *objects, runner_t *runner);
int init_end(runner_t *runner);
int game_init(runner_t *runner, parallax_t *parallax, objects_t *objects);

/* parallax.c */

int init_back(parallax_t *parallax);
int init_m1(parallax_t *parallax);
int init_m2(parallax_t *parallax);
int init_m3(parallax_t *parallax);
int init_road(parallax_t *parallax);

/* objects.c */

int init_clock(objects_t *objects);
int init_character(objects_t *objects);
int init_obstacle1(objects_t *objects);
int init_obstacle2(objects_t *objects);

/* events.c */

void check_keys(runner_t *runner, objects_t *objects);
void check_layers(parallax_t *parallax);
void check_position(objects_t *objects);
void check_collision(runner_t *runner, sfVector2f char_p, sfVector2f obst_p);
void check_chars(runner_t *runner);

/* read_map.c */

void obst1_obst2(runner_t *runner, objects_t *objects, int pos);
void obst2_obst1(runner_t *runner, objects_t *objects, int pos);
void obst1_void(runner_t *runner, objects_t *objects, int pos);
void obst2_void(runner_t *runner, objects_t *objects, int pos);
void read_map(runner_t *runner, objects_t *objects);

/* display.c */

void window_display(runner_t *runner, parallax_t *parallax, objects_t *objects);
void game_over(parallax_t *parallax, objects_t *objects);
void win(parallax_t *parallax, objects_t *objects);
void help_text(void);
void closed_text(void);

/* tools.c */

sfRenderWindow *window_create(unsigned int width, unsigned int height);
void set_score_text(char score[], runner_t *runner);
void convert_score(char str[], int num);
void misc_free(runner_t *runner, objects_t *objects);
void game_free(runner_t *runner, parallax_t *parallax, objects_t *objects);

#endif
