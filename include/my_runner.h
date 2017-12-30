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

void check_events(runner_t *runner);

sfRenderWindow *window_create(unsigned int width, unsigned int height);

#endif
