/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:31:59 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 17:47:10 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	first_case(t_bres *b, t_pti *img, t_p *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dx)
	{
		if (p1->x < WIDTH && p1->y < HEIGHT)
		{
			if (p1->x >= 0 && p1->y >= 0)
				ft_pixel_put_to_image(img, p1);
		}
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

void	second_case(t_bres *b, t_pti *img, t_p *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dy)
	{
		if (p1->x < WIDTH && p1->y < HEIGHT)
		{
			if (p1->x >= 0 && p1->y >= 0)
				ft_pixel_put_to_image(img, p1);
		}
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

void	draw_line(t_pti *img, t_p *p1, t_p *p2)
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

void	draw_x(t_coord *c, t_pti *img, t_bonus b)
{
	t_p		p1;
	t_p		p2;
	t_xy	xy;

	xy.x = 0;
	xy.y = 0;
	p1.x = ((xy.x * b.gap) - (xy.y * b.gap)) + b.or_x - b.gap;
	p1.y = (((xy.x * b.gap) + (xy.y * b.gap)) / b.iso + b.or_y
			+ b.gap / b.iso) - (c->map[xy.y][xy.x] * b.level);
	while (xy.y < c->y_point)
	{
		while (xy.x < c->x_point)
		{
			split_draw(&p2, &xy, &b, *c);
			draw_line(img, &p1, &p2);
			split_draw_x_2(&p1, &p2, &xy);
		}
		xy.x = 0;
		p1.x = ((xy.x * b.gap) - (xy.y * b.gap)) + b.or_x - b.gap;
		((xy.y + 1) < c->y_point) ? p1.y = ((xy.x * b.gap) + (xy.y * b.gap)) / b
.iso + b.or_y + b.gap / b.iso - (c->map[xy.y + 1][xy.x] * b.level) :
	(p1.y = ((xy.x * b.gap) + (xy.y * b.gap)) / b.iso + b.or_y + b.gap / b.iso);
		xy.y++;
	}
}

void	draw_y(t_coord *c, t_pti *img, t_bonus b)
{
	t_p		p1;
	t_p		p2;
	t_xy	xy;

	xy.x = 0;
	xy.y = 0;
	p1.x = ((xy.x * b.gap) - (xy.y * b.gap)) + b.or_x - b.gap;
	p1.y = (((xy.x * b.gap) + (xy.y * b.gap)) / b.iso + b.or_y +
			b.gap / b.iso) - (c->map[xy.y][xy.x] * b.level);
	while (xy.x < c->x_point)
	{
		while (xy.y < c->y_point)
		{
			split_draw(&p2, &xy, &b, *c);
			draw_line(img, &p1, &p2);
			split_draw_y_2(&p1, &p2, &xy);
		}
		xy.y = 0;
		xy.x++;
		p1.x = ((xy.x * b.gap) - (xy.y * b.gap)) + b.or_x - b.gap;
		((xy.y + 1) < c->y_point) ? p1.y = ((xy.x * b.gap) + (xy.y * b.gap)) / b
.iso + b.or_y + b.gap / b.iso - (c->map[xy.y + 1][xy.x] * b.level) :
	(p1.y = ((xy.x * b.gap) + (xy.y * b.gap)) / b.iso + b.or_y + b.gap / b.iso);
	}
}
