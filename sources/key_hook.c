/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/11 15:09:43 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	int static	gap = 10;

	t_context *lol;

	/*menu(lol)*/
	if (keycode == KEY_NUM_MINUS)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		scale(((t_context *)param)->coord, 0.5, 0.5);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == KEY_NUM_PLUS)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		scale(((t_context *)param)->coord, 2, 2);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		translate(((t_context *)param)->coord, -10, 0);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == KEY_RIGHT)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		translate(((t_context *)param)->coord, 10, 0);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		translate(((t_context *)param)->coord, 0, -10);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		translate(((t_context *)param)->coord, 0, 10);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}


	/* if (keycode == KEY_NUM_MINUS) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	scale(((t_context *)param)->coord, 0.5, 0.5); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	/* if (keycode == KEY_NUM_PLUS) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	scale(((t_context *)param)->coord, 2, 2); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	/* if (keycode == KEY_LEFT) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	translate(((t_context *)param)->coord, -10, 0); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	/* if (keycode == KEY_RIGHT) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	translate(((t_context *)param)->coord, 10, 0); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	/* if (keycode == KEY_UP) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	translate(((t_context *)param)->coord, 0, -10); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	/* if (keycode == KEY_DOWN) */
	/* { */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* 	((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED); */
	/* 	translate(((t_context *)param)->coord, 0, 10); */
	/* 	draw_verteces(((t_context *)param)->coord, ((t_context *)param)->pti); */
	/* 	mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0); */
	/* } */
	if (keycode == 53) // quit
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (gap == 0)
		gap = 1;
	if (keycode == 15)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap = 10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == 49) // clear
	{
		mlx_clear_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
	}
	return (0);
}
