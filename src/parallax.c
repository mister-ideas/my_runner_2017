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

int init_m1(parallax_t *parallax)
{
	parallax->m1_t = sfTexture_createFromFile(M1_PATH, NULL);
	if (!parallax->m1_t)
		return (1);
	parallax->m1_s = sfSprite_create();
	sfSprite_setTexture(parallax->m1_s, parallax->m1_t, sfTrue);
	parallax->m1_p.x = 0;
	parallax->m1_p.y = 140;
	sfSprite_setPosition(parallax->m1_s, parallax->m1_p);
	parallax->m1_m.x = 1;
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
	parallax->m2_p.y = 280;
	sfSprite_setPosition(parallax->m2_s, parallax->m2_p);
	parallax->m2_m.x = 2;
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
	parallax->m3_p.y = 560;
	sfSprite_setPosition(parallax->m3_s, parallax->m3_p);
	parallax->m3_m.x = 3;
	return (0);
}

int init_parallax(parallax_t *parallax)
{
	if (init_m1(parallax) ==  1)
		return (1);
	if (init_m2(parallax) == 1)
		return (1);
	if (init_m3(parallax) == 1)
		return (1);
	return (0);
}
