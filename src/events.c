/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** events.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_runner.h"

void check_events(runner_t *runner)
{
	while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
		if (runner->event.type == sfEvtClosed
		|| (runner->event.type == sfEvtKeyPressed
		&& runner->event.key.code == sfKeyEscape))
			sfRenderWindow_close(runner->window);
	}
}
