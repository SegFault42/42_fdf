/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:34:16 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/14 21:40:10 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int keycode, void *pa, t_pti *img, t_p *p)
{
	if (keycode == KEY_EQUAL && ((t_c *)pa)->bonus->gap >= 0)
	{
		((t_c *)pa)->bonus->level = ((t_c *)pa)->bonus->gap;
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->gap++;
		((t_c *)pa)->bonus->level++;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_MIN && ((t_c *)pa)->bonus->gap > 0)
	{
		((t_c *)pa)->bonus->level = ((t_c *)pa)->bonus->gap;
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->gap--;
		((t_c *)pa)->bonus->level--;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
}

void	level(int keycode, void *pa, t_pti *img, t_p *p)
{
	if (keycode == KEY_P)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->level++;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_O)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->level--;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
}

void	other(int keycode, void *pa, t_pti *img, t_p *p)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->img_ptr);
		mlx_destroy_window(((t_c *)pa)->mlx_ptr, ((t_c *)pa)->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_SPACE)
		clear_image(pa, img, p);
	if (keycode == KEY_R)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->gap = 20;
		((t_c *)pa)->bonus->level = 20;
		((t_c *)pa)->bonus->iso = 2;
		((t_c *)pa)->bonus->or_x = WIDTH / 2;
		((t_c *)pa)->bonus->or_y = HEIGHT / 2;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
}

void	rotation(int keycode, void *pa, t_pti *img, t_p *p)
{
	if (keycode == KEY_T && ((t_c *)pa)->bonus->iso >= 1)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->iso += 1;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_G && ((t_c *)pa)->bonus->iso > 1)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->iso -= 1;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
}

void	view(int keycode, void *pa, t_pti *img, t_p *p)
{
	if (keycode == KEY_1)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->iso = 50000;
		((t_c *)pa)->bonus->or_x = WIDTH / 2;
		((t_c *)pa)->bonus->or_y = HEIGHT / 2;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
	if (keycode == KEY_2)
	{
		clear_image(pa, img, p);
		((t_c *)pa)->bonus->iso = 1;
		((t_c *)pa)->bonus->or_x = WIDTH / 2;
		((t_c *)pa)->bonus->or_y = HEIGHT / 3;
		impr_img(pa, img, p, ((t_c *)pa)->bonus);
		menu(((t_c *)pa));
	}
}
