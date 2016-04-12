/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/12 23:44:38 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_image(void *param, t_pixel_to_image *img, t_point *p)
{
		int i = 0;
		int j = 0;
		char *data;
	
		data = mlx_get_data_addr(((t_context *)param)->img_ptr, &img->bpp, &img->sizeline, &img->endian);
		while (i < (HEIGHT * img->sizeline))
		{
			data[i + 2] = 59; // R
			data[i + 1] = 59; // G
			data[i + 0] = 59; // B
			data[i + 3] = 0; // O
			i+=4;
		}
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
}

int	key_hook(int keycode, void *param, t_pixel_to_image *img, t_point *p)
{
	int static	gap = 20;
	int static	level = 20;
	int static	iso = 2;
	int static	origin_x = WIDTH / 2;
	int static	origin_y = HEIGHT / 3;

	/*if (gap == 0 )*/
	/*{*/
		/*gap = 1;*/
		/*level = 1;*/
	/*}*/
	/*if (iso <= 3)*/
	/*{*/
		/*iso = 4;*/
	/*}*/
	if (keycode == KEY_ESC) // quit
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_SPACE) // clear image
		clear_image(param, img, p);
	if (keycode == KEY_R) // reset
	{
		clear_image(param, img, p);
		gap = 20;
		level = 20;
		iso = 2;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_EQUAL && gap >= 0) // zoom in
	{
		level = gap;
		clear_image(param, img, p);
		/*gap *= 1.05;*/
		gap++;
		level++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_MIN && gap > 0) // zoom out
	{
		level = gap;
		clear_image(param, img, p);
		/*gap /= 1.05;*/
		gap--;
		level--;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_NUM_PLUS) // level plus
	{
		clear_image(param, img, p);
		level++;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_NUM_MINUS) // level min
	{
		clear_image(param, img, p);
		level--;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_T && iso >= 1) //iso ++
	{
		clear_image(param, img, p);
		iso+=1;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_G && iso > 1) //iso--
	{
		if (iso == 2)
			level = 3;
		printf("%d\n", iso);
		clear_image(param, img, p);
		iso-=1;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_1) // vue de face
	{
		clear_image(param, img, p);
		iso = 50000;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_2) // vue de dessus
	{
		clear_image(param, img, p);
		iso = 1;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_LEFT) // deplacement gauche
	{
		clear_image(param, img, p);
		origin_x-=10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_RIGHT) // deplacement droite
	{
		clear_image(param, img, p);
		origin_x+=10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_UP) // deplacement haut
	{
		clear_image(param, img, p);
		origin_y-=10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	if (keycode == KEY_DOWN) // deplacement bas
	{
		clear_image(param, img, p);
		origin_y+=10;
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, origin_x, origin_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
		menu(((t_context *)param));
	}
	return (0);
}
