/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** tools.c
*/

#include "my_runner.h"

sfRenderWindow *window_create(unsigned int width, unsigned int height)
{
	sfRenderWindow *window;
	sfVideoMode video_mode = {width, height, 32};

	window = sfRenderWindow_create(video_mode, "Runner!", sfClose, NULL);
	return (window);
}

void set_score_text(char score[], runner_t *runner)
{
	sfText_setString(runner->score_text, score);
	sfText_setFont(runner->score_text, runner->font);
	sfText_setCharacterSize(runner->score_text, 60);
	sfText_setPosition(runner->score_text, runner->score_text_p);
}

void convert_score(char str[], int num)
{
	int i;
	int rem;
	int len = 0;
	int n;

	n = num;
	while (n) {
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++) {
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

void game_free(runner_t *runner, parallax_t *parallax, objects_t *objects)
{
	sfTexture_destroy(parallax->back_t);
	sfTexture_destroy(parallax->m1_t);
	sfTexture_destroy(parallax->m2_t);
	sfTexture_destroy(parallax->m3_t);
	sfTexture_destroy(parallax->road_t);
	sfTexture_destroy(objects->char_t);
	sfTexture_destroy(objects->obst1_t);
	sfTexture_destroy(objects->obst2_t);
	sfSprite_destroy(parallax->back_s);
	sfSprite_destroy(parallax->m1_s);
	sfSprite_destroy(parallax->m2_s);
	sfSprite_destroy(parallax->m3_s);
	sfSprite_destroy(parallax->road_s);
	sfSprite_destroy(objects->char_s);
	sfSprite_destroy(objects->obst1_s);
	sfSprite_destroy(objects->obst2_s);
	sfMusic_destroy(runner->m_back);
	sfMusic_destroy(runner->m_jump);
	sfRenderWindow_destroy(runner->window);
}
