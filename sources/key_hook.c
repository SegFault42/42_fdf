/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/13 20:46:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		impr_img(void *param, t_pti *img, t_p *p, int gap, int level, int iso, int or_x, int or_y)
{
		((t_context *)param)->pti->img_color = mlx_get_color_value(((t_context *)param)->mlx_ptr, GREEN);
		print_p(((t_context *)param)->coord, ((t_context *)param)->pti, gap, level, iso, or_x, or_y);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
}

void	clear_image(void *param, t_pti *img, t_p *p)
{
		int i = 0;
		int j = 0;
		char *data;

		data = mlx_get_data_addr(((t_context *)param)->img_ptr, &img->bpp, &img->sizeline, &img->endian);
		while (i < (HEIGHT * img->sizeline))
		{
			data[i + 2] = 59;
			data[i + 1] = 59;
			data[i + 0] = 59;
			data[i + 3] = 0;
			i+=4;
		}
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
}

int		key_hook(int keycode, void *param, t_pti *img, t_p *p)
{
	int static	gap = 20;
	int static	level = 20;
	int static	iso = 2;
	int static	or_x = WIDTH / 2;
	int static	or_y = HEIGHT / 3;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);
		mlx_destroy_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_SPACE)
		clear_image(param, img, p);
	if (keycode == KEY_F12)
		clear_image(param, img, p);
	if (keycode == KEY_R)
	{
		clear_image(param, img, p);
		gap = 20;
		level = 20;
		iso = 2;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_EQUAL && gap >= 0)
	{
		level = gap;
		clear_image(param, img, p);
		gap++;
		level++;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_MIN && gap > 0)
	{
		level = gap;
		clear_image(param, img, p);
		gap--;
		level--;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_P)
	{
		clear_image(param, img, p);
		level++;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_O)
	{
		clear_image(param, img, p);
		level--;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_T && iso >= 1)
	{
		clear_image(param, img, p);
		iso+=1;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_G && iso > 1)
	{
		if (iso == 2)
			level = 3;
		clear_image(param, img, p);
		iso-=1;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_1)
	{
		clear_image(param, img, p);
		iso = 50000;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_2)
	{
		clear_image(param, img, p);
		iso = 1;
		level = 3;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(param, img, p);
		or_x-= 10;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(param, img, p);
		or_x+= 10;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_UP)
	{
		clear_image(param, img, p);
		or_y-= 10;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(param, img, p);
		or_y+= 10;
		impr_img(param, img, p, gap, level, iso, or_x, or_y);
		menu(((t_context *)param));
	}
	return (0);
}
