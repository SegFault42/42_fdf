/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 22:41:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	impr_img(void *pa, t_bonus *bonus)
{
	((t_c *)pa)->pti->img_color = mlx_get_color_value(((t_c *)pa)->mlx_ptr,
GREEN);
	print_p(((t_c *)pa)->coord, ((t_c *)pa)->pti, *bonus);
	mlx_put_image_to_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr,
((t_c *)pa)->img_ptr, 0, 0);
	menu(((t_c *)pa));
}

void	clear_image(void *pa, t_pti *img)
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
		data[i + 2] = 58;
		data[i + 1] = 58;
		data[i + 0] = 58;
		data[i + 3] = 0;
		i += 4;
	}
	mlx_put_image_to_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr,
((t_c *)pa)->img_ptr, 0, 0);
}

void	move(int keycode, void *pa, t_pti *img)
{
	if (keycode == KEY_LEFT)
	{
		clear_image(pa, img);
		((t_c *)pa)->bonus->or_x -= 10;
		impr_img(pa, ((t_c *)pa)->bonus);
	}
	if (keycode == KEY_RIGHT)
	{
		clear_image(pa, img);
		((t_c *)pa)->bonus->or_x += 10;
		impr_img(pa, ((t_c *)pa)->bonus);
	}
	if (keycode == KEY_UP)
	{
		clear_image(pa, img);
		((t_c *)pa)->bonus->or_y -= 10;
		impr_img(pa, ((t_c *)pa)->bonus);
	}
	if (keycode == KEY_DOWN)
	{
		clear_image(pa, img);
		((t_c *)pa)->bonus->or_y += 10;
		impr_img(pa, ((t_c *)pa)->bonus);
	}
}

int		key_hook(int keycode, void *pa, t_pti *img)
{
	static t_bonus	bonus = {20, 20, 2, WIDTH / 2, HEIGHT / 3};

	((t_c *)pa)->bonus = &bonus;
	move(keycode, pa, img);
	zoom(keycode, pa, img);
	level(keycode, pa, img);
	other(keycode, pa, img);
	rotation(keycode, pa, img);
	view(keycode, pa, img);
	return (0);
}
