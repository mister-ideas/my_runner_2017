/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** clocks.c
*/

#include "my_runner.h"

void score_clock(runner_t *runner)
{
	runner->time3 = sfClock_getElapsedTime(runner->clock3);
	runner->seconds3 = runner->time3.microseconds / 1000000.0;
	if (runner->seconds3 > 1) {
		runner->score++;
		sfClock_restart(runner->clock3);
	}
}

void character_clock(runner_t *runner, objects_t *objects)
{
	runner->time1 = sfClock_getElapsedTime(runner->clock1);
	runner->seconds1 = runner->time1.microseconds / 1000000.0;
	if (runner->seconds1 > 0.04) {
		if (objects->char_r.left > 250)
			objects->char_r.left -= 82;
		else
			objects->char_r.left = 830;
		sfClock_restart(runner->clock1);
	}
}

void obstacles_clock(runner_t *runner, objects_t *objects)
{
	runner->time2 = sfClock_getElapsedTime(runner->clock2);
	runner->seconds2 = runner->time2.microseconds / 1000000.0;
	if (runner->seconds2 > 0.5) {
		if (objects->obst1_r.left < 70)
			objects->obst1_r.left += 70;
		else
			objects->obst1_r.left = 0;
		if (objects->obst2_r.left < 70)
			objects->obst2_r.left += 70;
		else
			objects->obst2_r.left = 0;
		sfClock_restart(runner->clock2);
	}
}

void clocks(runner_t *runner, objects_t *objects)
{
	score_clock(runner);
	character_clock(runner, objects);
	obstacles_clock(runner, objects);
}
