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

int init_back(parallax_t *parallax)
{
	parallax->back_t = sfTexture_createFromFile(BACK_PATH, NULL);
	if (!parallax->back_t)
		return (1);
	parallax->back_s = sfSprite_create();
	sfSprite_setTexture(parallax->back_s, parallax->back_t, sfTrue);
	parallax->back_p.x = 0;
	parallax->back_p.y = 0;
	sfSprite_setPosition(parallax->back_s, parallax->back_p);
	parallax->back_m.x = -1;
	return (0);
}

int init_m1(parallax_t *parallax)
{
	parallax->m1_t = sfTexture_createFromFile(M1_PATH, NULL);
	if (!parallax->m1_t)
		return (1);
	parallax->m1_s = sfSprite_create();
	sfSprite_setTexture(parallax->m1_s, parallax->m1_t, sfTrue);
	parallax->m1_p.x = 0;
	parallax->m1_p.y = 20;
	sfSprite_setPosition(parallax->m1_s, parallax->m1_p);
	parallax->m1_m.x = -2;
	return (0);
}

int init_m2(parallax_t *parallax)
{
	parallax->m2_t = sfTexture_createFromFile(M2_PATH, NULL);
	if (!parallax->m2_t)
		return (1);
	parallax->m2_s = sfSprite_create();
	sfSprite_setTexture(parallax->m2_s, parallax->m2_t, sfTrue);
	parallax->m2_p.x = 0;
	parallax->m2_p.y = 120;
	sfSprite_setPosition(parallax->m2_s, parallax->m2_p);
	parallax->m2_m.x = -4;
	return (0);
}

int init_m3(parallax_t *parallax)
{
	parallax->m3_t = sfTexture_createFromFile(M3_PATH, NULL);
	if (!parallax->m3_t)
		return (1);
	parallax->m3_s = sfSprite_create();
	sfSprite_setTexture(parallax->m3_s, parallax->m3_t, sfTrue);
	parallax->m3_p.x = 0;
	parallax->m3_p.y = 480;
	sfSprite_setPosition(parallax->m3_s, parallax->m3_p);
	parallax->m3_m.x = -6;
	return (0);
}

int init_road(parallax_t *parallax)
{
	parallax->road_t = sfTexture_createFromFile(ROAD_PATH, NULL);
	if (!parallax->road_t)
		return (1);
	parallax->road_s = sfSprite_create();
	sfSprite_setTexture(parallax->road_s, parallax->road_t, sfTrue);
	parallax->road_p.x = 0;
	parallax->road_p.y = 760;
	sfSprite_setPosition(parallax->road_s, parallax->road_p);
	parallax->road_m.x = -12;
	return (0);
}
