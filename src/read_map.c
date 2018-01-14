/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** read_map.c
*/

#include "my_runner.h"

void obst1_obst2(runner_t *runner, objects_t *objects, int pos)
{
	if (runner->first_floor[pos] == '1'
	&& runner->second_floor[pos] == '2') {
		sfSprite_setPosition(objects->obst1_s, objects->first_floor_p);
		sfSprite_setPosition(objects->obst2_s, objects->second_floor_p);
		objects->obst1_m.x = -8;
		objects->obst2_m.x = -8;
	}
}

void obst2_obst1(runner_t *runner, objects_t *objects, int pos)
{
	if (runner->first_floor[pos] == '2'
	&& runner->second_floor[pos] == '1') {
		sfSprite_setPosition(objects->obst2_s, objects->first_floor_p);
		sfSprite_setPosition(objects->obst1_s, objects->second_floor_p);
		objects->obst2_m.x = -8;
		objects->obst1_m.x = -8;
	}
}

void obst1_void(runner_t *runner, objects_t *objects, int pos)
{
	if (runner->first_floor[pos] == '1'
	&& runner->second_floor[pos] == '0') {
		sfSprite_setPosition(objects->obst1_s, objects->first_floor_p);
		objects->obst1_m.x = -8;
		objects->obst2_m.x = 0;
	}
}

void obst2_void(runner_t *runner, objects_t *objects, int pos)
{
	if (runner->first_floor[pos] == '2'
	&& runner->second_floor[pos] == '0') {
		sfSprite_setPosition(objects->obst2_s, objects->first_floor_p);
		objects->obst2_m.x = -8;
		objects->obst1_m.x = 0;
	}
}

void read_map(runner_t *runner, objects_t *objects)
{
	static int pos = 0;

	if ((objects->obst1_p.x < -70 || objects->obst2_p.x < -70)
	|| (objects->obst1_p.x == 1920 && objects->obst2_p.x == 1920)) {
		obst1_obst2(runner, objects, pos);
		obst2_obst1(runner, objects, pos);
		obst1_void(runner, objects, pos);
		obst2_void(runner, objects, pos);
		pos++;
	}
}
