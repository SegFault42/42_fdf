/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/05 23:54:51 by cattouma         ###   ########.fr       */
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
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x99;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x99;
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

void	draw_x(t_coord *coord, t_pixel_to_image *img, int gap)
{
	int x;
	int y;
	t_point	p1;
	t_point	p2;
	//char **split_x;

	x = 0;
	y = 0;
	p1.x = ORIGIN_X;
	p1.y = ORIGIN_Y;
	while (y <= coord->y_point)
	{
		//split_x = ft_strsplit(coord->map[y], ' ');
		while (x < coord->x_point)
		{
			p2.x = p1.x + gap;
			p2.y = p1.y;
			//printf("x1: %d y1: %d, x2: %d y2: %d\n", p1.x, p1.y, p2.x, p2.y);
			draw_line(img, &p1, &p2);
			x++;
			p1.x = p2.x;;
		}
		x = 0;
		y++;
		p1.y = p2.y + gap;
		p1.x = ORIGIN_X;
	}
}

void	draw_y(t_coord *coord, t_pixel_to_image *img, int gap)
{
	int x;
	int y;
	t_point	p1;
	t_point	p2;
	char **split_x;

	x = 0;
	y = 0;
	p1.x = ORIGIN_X;
	p1.y = ORIGIN_Y;
	//printf
	printf("x max: %d y max: %d", coord->x_point, coord->y_point);
	while(x <= coord->x_point)
	{
		while (y < coord->y_point)
		{
			p2.x = p1.x;
			p2.y = ORIGIN_Y + gap * coord->y_point;
			draw_line(img, &p1, &p2);
			p1.y = p2.y;
			y++;
		}
		y = 0;
		p1.x = p2.x + gap;
		p1.y = ORIGIN_Y;
		x++;
	}
}

void	print_point(t_coord *coord, t_pixel_to_image *img)
{
	int gap;

	gap = 20;
	draw_x(coord, img, gap);
	draw_y(coord, img, gap);
}




/* point_iso.x = ((point.x* zoom) - (point.y * zoom)) + ORIGIN_X; */
/* point_iso.y = (((point.x* zoom) + (point.y * zoom)) / 2) + ORIGIN_Y  - (ft_atoi(split_x[point.x]) * 10); */
/* p2.x = ((point.x + 1) * zoom) - (point.y * zoom) + ORIGIN_X; */
/* p2.y = (((point.x + 1) * zoom) + (point.y * zoom) / 2) + ORIGIN_Y - (ft_atoi(split_x[point.x + 1]) * 10); */
