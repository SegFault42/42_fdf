/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/09 23:31:31 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	int static	gap = 10;

	t_context *lol;

	/*menu(lol)*/
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
	if (keycode == 24 || keycode == 257 || keycode == 69) // zoom in
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == 27 || keycode == 78) // zoom out
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap--;
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
