/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:31:59 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/09 19:21:57 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	first_case(t_bres *b, t_pixel_to_image *img, t_point *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dx)
	{
		ft_pixel_put_to_image(img, p1);
		i++;
		p1->x += b->x_incr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			p1->y += b->y_incr;
			b->ex += b->dx;
		}
	}
}

void	second_case(t_bres *b, t_pixel_to_image *img, t_point *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dy)
	{
		ft_pixel_put_to_image(img, p1);
		i++;
		p1->y += b->y_incr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			p1->x += b->x_incr;
			b->ey += b->dy;
		}
	}
}

void	draw_line(t_pixel_to_image *img, t_point *p1, t_point *p2)
{
	t_bres	b;

	b.ex = abs(p2->x - p1->x);
	b.ey = abs(p2->y - p1->y);
	b.dx = b.ex * 2;
	b.dy = b.ey * 2;
	b.c_dx = b.ex;
	b.c_dy = b.ey;
	b.x_incr = 1;
	b.y_incr = 1;
	if (p1->x > p2->x)
		b.x_incr = -1;
	if (p1->y > p2->y)
		b.y_incr = -1;
	if (b.c_dx >= b.c_dy)
		first_case(&b, img, p1);
	else if (b.c_dx <= b.c_dy)
		second_case(&b, img, p1);
}

void	draw_x(t_coord *coord, t_pixel_to_image *img, int gap)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	x = 0;
	y = 0;
	p1.x = ((x * gap) - (y * gap)) + ORIGIN_X - gap;
	p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2;
	while (y < coord->y_point)
	{
		while (x < coord->x_point)
		{
			p2.x = ((x * gap) - (y * gap)) + ORIGIN_X;
			p2.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y - (coord->map[y][x] * 10);
			draw_line(img, &p1, &p2);
			x++;
			p1.x = p2.x;
			p1.y = p2.y;
		}
		x = 0;
		p1.x = ((x * gap) - (y * gap)) + ORIGIN_X - gap;
		if ((y + 1) < coord->y_point)
			p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2 - (coord->map[y + 1][x] * 10);
		else
			p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2;
		y++;
	}
}

void	draw_y(t_coord *coord, t_pixel_to_image *img, int gap)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	x = 0;
	y = 0;
	p1.x = ((x * gap) - (y * gap)) + ORIGIN_X - gap;
	p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2;
	while (x < coord->x_point)
	{
		while (y < coord->y_point)
		{
			p2.x = ((x * gap) - (y * gap)) + ORIGIN_X;
			p2.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y - (coord->map[y][x] * 10);
			draw_line(img, &p1, &p2);
			y++;
			p1.x = p2.x;
			p1.y = p2.y;
		}
		y = 0;
		x++;
		p1.x = ((x * gap) - (y * gap)) + ORIGIN_X - gap;
		if ((y + 1) < coord->y_point)
			p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2 - (coord->map[y + 1][x] * 10);
		else
			p1.y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y + gap / 2;
	}
}
