/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/10 15:36:43 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	int static	gap = 10;

	if (gap <= 0)
		gap = 1;
	if (keycode == KEY_ESCAP) // quit
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_R)
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap = 10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_EQUAL) // zoom in
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_MIN) // zoom out
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap--;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_SPACE) // clear
	{
		mlx_clear_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
	}
	return (0);
}
