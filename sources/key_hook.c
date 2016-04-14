/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/14 14:37:20 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	impr_img(void *pa, t_pti *img, t_p *p, t_bonus *bonus)
{
	((t_c *)pa)->pti->img_color = mlx_get_color_value(((t_c *)pa)->mlx_ptr,
GREEN);
	print_p(((t_c *)pa)->coord, ((t_c *)pa)->pti, *bonus);
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
	t_bonus		bonus;

	bonus.gap = 20;
	bonus.level = 20;
	bonus.iso = 2;
	bonus.or_x = WIDTH / 2;
	bonus.or_y = HEIGHT / 3;
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
		bonus.gap = 20;
		bonus.level = 20;
		bonus.iso = 2;
		bonus.or_x = 640;
		bonus.iso = 240;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_EQUAL && bonus.gap >= 0)
	{
		bonus.level = bonus.gap;
		clear_image(pa, img, p);
		bonus.gap++;
		bonus.level++;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_MIN && bonus.gap > 0)
	{
		bonus.level = bonus.gap;
		clear_image(pa, img, p);
		bonus.gap--;
		bonus.level--;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_P)
	{
		clear_image(pa, img, p);
		bonus.level++;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_O)
	{
		clear_image(pa, img, p);
		bonus.level--;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_T && bonus.iso >= 1)
	{
		clear_image(pa, img, p);
		bonus.iso += 1;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_G && bonus.iso > 1)
	{
		if (bonus.iso == 2)
			bonus.level = 3;
		clear_image(pa, img, p);
		bonus.iso -= 1;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_1)
	{
		clear_image(pa, img, p);
		bonus.iso = 50000;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_2)
	{
		clear_image(pa, img, p);
		bonus.iso = 1;
		bonus.level = 3;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_LEFT)
	{
		clear_image(pa, img, p);
		bonus.or_x -= 10;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(pa, img, p);
		bonus.or_x += 10;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_UP)
	{
		clear_image(pa, img, p);
		bonus.or_y -= 10;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(pa, img, p);
		bonus.or_y += 10;
		impr_img(pa, img, p, &bonus);
		menu(((t_c *)pa));
	}
	return (0);
}
