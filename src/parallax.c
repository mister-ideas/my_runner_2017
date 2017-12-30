/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** parallax.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

int init_back(parallax_t *parallax, const char* path)
{
	parallax->back_t = sfTexture_createFromFile(path, NULL);
	if (!parallax->back_t)
		return (1);
	parallax->back_s = sfSprite_create();
	sfSprite_setTexture(parallax->back_s, parallax->back_t, sfTrue);
	parallax->back_p.x = 0;
	parallax->back_p.y = 140;
	sfSprite_setPosition(parallax->back_s, parallax->back_p);
	parallax->back_m.x = 1;
	return (0);
}

int init_mid(parallax_t *parallax, const char* path)
{
	parallax->mid_t = sfTexture_createFromFile(path, NULL);
	if (!parallax->mid_t)
		return (1);
	parallax->mid_s = sfSprite_create();
	sfSprite_setTexture(parallax->mid_s, parallax->mid_t, sfTrue);
	parallax->mid_p.x = 0;
	parallax->mid_p.y = 280;
	sfSprite_setPosition(parallax->mid_s, parallax->mid_p);
	parallax->mid_m.x = 2;
	sfSprite_move(parallax->back_s, parallax->back_m);
	return (0);
}

int init_top(parallax_t *parallax, const char* path)
{
	parallax->top_t = sfTexture_createFromFile(path, NULL);
	if (!parallax->top_t)
		return (1);
	parallax->top_s = sfSprite_create();
	sfSprite_setTexture(parallax->top_s, parallax->top_t, sfTrue);
	parallax->top_p.x = 0;
	parallax->top_p.y = 560;
	sfSprite_setPosition(parallax->top_s, parallax->top_p);
	parallax->top_m.x = 3;
	sfSprite_move(parallax->back_s, parallax->back_m);
	return (0);
}

int init_parallax(parallax_t *parallax)
{
	if (init_back(parallax, "ressources/img/background.png") ==  1)
		return (1);
	if (init_mid(parallax, "ressources/img/midground.png") == 1)
		return (1);
	if (init_top(parallax, "ressources/img/foreground.png") == 1)
		return (1);
	return (0);
}
