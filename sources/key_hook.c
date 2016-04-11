/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/11 23:42:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	int static	gap = 1;
	int static	level = 1;
	int static	iso = 2;

	if (gap <= 0 )
	{
		gap = 1;
		level = 1;
	}
	if (iso <= 1)
	{
		iso = 2;
	}
	if (keycode == KEY_ESC) // quit
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_R) // reset
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap = 1;
		level = 1;
		iso = 2;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_EQUAL) // zoom in
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap++;
		level++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_MIN) // zoom out
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		gap--;
		level--;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_NUM_PLUS) // level plus
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		level++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_NUM_MINUS) // level min
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		level--;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	/*if (keycode == KEY_T) iso*/
	/*{*/
		/*((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);*/
		/*print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);*/
		/*mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);*/
		/*iso+=1;*/
		/*((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);*/
		/*print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);*/
		/*mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);*/
		/*menu(((t_context *)param));*/
	/*}*/
	/*if (keycode == KEY_G) iso*/
	/*{*/
		/*((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);*/
		/*print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);*/
		/*mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);*/
		/*iso-=1;*/
		/*((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);*/
		/*print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);*/
		/*mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);*/
		/*menu(((t_context *)param));*/
	/*}*/
	if (keycode == KEY_1) // vue de face
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		iso = 50000;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_2) // vue de dessus
	{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, BLACK);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		iso = 1;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, RED);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	return (0);
}
