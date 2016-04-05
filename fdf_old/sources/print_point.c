/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/05 17:21:52 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put_to_image(t_pixel_to_image *img, t_point *p)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
}

void    draw_line(t_pixel_to_image *img, t_point *p1, t_point *p2)
{
	int dx;
	int dy;
	int e;
	int x_incr;
	int y_incr;
	int i;
	int c_dx;
	int c_dy; 
	int ex;
	int ey; 


	ex = abs(p2->x - p1->x);
	ey = abs(p2->y - p1->y);
	dx = ex * 2;
	dy = ey * 2;
	c_dx = ex;
	c_dy = ey;
	i = 0;
	x_incr = 1;
	y_incr = 1;

	if (p1->x > p2->x)
		x_incr = -1;
	if (p1->y > p2->y)
		y_incr = -1;
	if (c_dx > c_dy)
	{
		while (i <= c_dx)
		{
			ft_pixel_put_to_image(img, p1);
			i++;
			p1->x += x_incr;
			ex -= dy;
			if (ex < 0)
			{
				p1->y += y_incr;
				ex += dx;
			}
		}
	}
	if (c_dx < c_dy)
	{
		while (i <= c_dy)
		{
			ft_pixel_put_to_image(img, p1);
			i++;
			p1->y += y_incr;
			ey -= dx;
			if (ey < 0)
			{
				p1->x += x_incr;;
				ey += dy;
			}
		}
	}
}

void	print_point(t_coord *coord, t_pixel_to_image *img)
{
	char	**split_x;
	int		zoom;
	t_point	point;
	t_point	point_iso;
	t_point	p2;

	zoom = 0;
	point.x = 0;
	point.y = 0;
	while (coord->map[point.y])
	{
		split_x = ft_strsplit(coord->map[point.y], ' ');
		while (split_x[point.x] && split_x[point.x + 1])
		{
			point_iso.x = ((point.x* zoom) - (point.y * zoom)) + ORIGIN_X;
			point_iso.y = (((point.x* zoom) + (point.y * zoom)) / 2) + ORIGIN_Y  - (ft_atoi(split_x[point.x]) * 10);
			p2.x = ((point.x + 1) * zoom) - (point.y * zoom) + ORIGIN_X;
			p2.y = (((point.x + 1) * zoom) + (point.y * zoom) / 2) + ORIGIN_Y - (ft_atoi(split_x[point.x + 1]) * 10);
			if (point_iso.x > p2.x)
			{
				ft_swap(&point_iso.x, &p2.x);
				ft_swap(&point_iso.y, &p2.y);
			}
			if (point.x + 1 <= tab_len(split_x))
				draw_x_or_y(point_iso.x, point_iso.y, p2.x,  p2.y, img);
			if (point.y + 1 <= coord->y_point)
				draw_x_or_y(point_iso.x, point_iso.y, p2.x,  p2.y, img);
			ft_pixel_put_to_image(img, &point_iso);
			point.x++;
		}
		tab_free(split_x);
		point.x = 0;
		point.y++;
	}
}
