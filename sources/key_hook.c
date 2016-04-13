/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/13 22:28:08 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	impr_img(void *pa, t_pti *img, t_p *p, t_bonus *bonus)
{
	((t_c *)pa)->pti->img_color = mlx_get_color_value(((t_c *)pa)->mlx_ptr,
GREEN);
	print_p(((t_c *)pa)->coord, ((t_c *)pa)->pti, bonus->gap, bonus->level,
bonus->iso, bonus->or_x, bonus->or_y);
	mlx_put_image_to_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr,
((t_c *)pa)->img_ptr, 0, 0);
}

void	clear_image(void *pa, t_pti *img, t_p *p)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	j = 0;
	data = mlx_get_data_addr(((t_c *)pa)->img_ptr, &img->bpp, &img->sizeline,
&img->endian);
	while (i < (HEIGHT * img->sizeline))
	{
		data[i + 2] = 59;
		data[i + 1] = 59;
		data[i + 0] = 59;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr,
((t_c *)pa)->img_ptr, 0, 0);
}

int		key_hook(int keycode, void *pa, t_pti *img, t_p *p)
{

	int static	gap = 20;
	int static	level = 20;
	int static	iso = 2;
	int static	or_x = WIDTH / 2;
	int static	or_y = HEIGHT / 3;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->img_ptr);
		mlx_destroy_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_SPACE)
		clear_image(pa, img, p);
	if (keycode == KEY_F12)
		clear_image(pa, img, p);
	if (keycode == KEY_R)
	{
		clear_image(pa, img, p);
		gap = 20;
		level = 20;
		iso = 2;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_EQUAL && gap >= 0)
	{
		level = gap;
		clear_image(pa, img, p);
		gap++;
		level++;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_MIN && gap > 0)
	{
		level = gap;
		clear_image(pa, img, p);
		gap--;
		level--;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_P)
	{
		clear_image(pa, img, p);
		level++;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_O)
	{
		clear_image(pa, img, p);
		level--;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_T && iso >= 1)
	{
		clear_image(pa, img, p);
		iso += 1;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_G && iso > 1)
	{
		if (iso == 2)
			level = 3;
		clear_image(pa, img, p);
		iso -= 1;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_1)
	{
		clear_image(pa, img, p);
		iso = 50000;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_2)
	{
		clear_image(pa, img, p);
		iso = 1;
		level = 3;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(pa, img, p);
		or_x -= 10;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(pa, img, p);
		or_x += 10;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_UP)
	{
		clear_image(pa, img, p);
		or_y -= 10;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(pa, img, p);
		or_y += 10;
		impr_img(pa, img, p, gap, level, iso, or_x, or_y);
		menu(((t_c *)pa));
	}
	return (0);
}
