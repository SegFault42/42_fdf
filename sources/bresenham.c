/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:31:59 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/11 17:21:06 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void matrix_mult(int mi[3][3], t_point *p)
{
	int i;
	int j;
	int newp[2];

	i = 0;
	j = 0;
	while (i < 2)
	{
		newp[i] = (mi[i][0] * p->x) + (mi[i][1] * p->y) + (mi[i][2] * 1);
		i++;
	}
	p->x = newp[0];
	p->y = newp[1];
}

void matrix_mult_scale(int mi[3][3], t_point *p, float x_axis, float y_axis)
{
	int		i;
	int		j;
	float	newp[2];
	t_point	tmp;

	i = 0;
	j = 0;
	tmp.x = (p->x + (-x_axis)) + x_axis;
	tmp.y = (p->y + (-y_axis)) + y_axis;
	while (i < 2)
	{
		newp[i] = (mi[i][0] * tmp.x) + (mi[i][1] * tmp.y) + (mi[i][2] * 1);
		i++;
	}
	p->x = (int )newp[0];
	p->y = (int )newp[1];
}

void	translate(t_coord *coord, int x_axis, int y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = 1; 
	matrix[0][1] = 0; 
	matrix[0][2] = x_axis; 
	matrix[1][0] = 0; 
	matrix[1][1] = 1; 
	matrix[1][2] = y_axis; 
	matrix[2][0] = 0; 
	matrix[2][1] = 0; 
	matrix[2][2] = 1; 
	v = 0;
	while (v < coord->total_points)
	{
		matrix_mult(matrix, coord->verteces[v]);
		v++;
	}
}

void	scale(t_coord *coord, float x_axis, float y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = x_axis; 
	matrix[0][1] = 0; 
	matrix[0][2] = 0; 
	matrix[1][0] = 0; 
	matrix[1][1] = y_axis; 
	matrix[1][2] = 0; 
	matrix[2][0] = 0; 
	matrix[2][1] = 0; 
	matrix[2][2] = 1; 
	v = 0;
	while (v < coord->total_points)
	{
		matrix_mult_scale(matrix, coord->verteces[v], x_axis, y_axis);
		v++;
	}
}

void	rotate(t_coord *coord, int angle)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = cos(angle); 
	matrix[0][1] = -(sin(angle))+ 0.5; 
	matrix[0][2] = 0; 
	matrix[1][0] = sin(angle)+ 0.5; 
	matrix[1][1] = cos(angle)+ 0.5; 
	matrix[1][2] = 0; 
	matrix[2][0] = 0; 
	matrix[2][1] = 0; 
	matrix[2][2] = 1; 
	v = 0;
	while (v < coord->total_points)
	{
		matrix_mult(matrix, coord->verteces[v]);
		v++;
	}

}

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

void	draw_line(t_pixel_to_image *img, t_point p1, t_point p2)
{
	t_bres	b;

	b.ex = abs(p2.x - p1.x);
	b.ey = abs(p2.y - p1.y);
	b.dx = b.ex * 2;
	b.dy = b.ey * 2;
	b.c_dx = b.ex;
	b.c_dy = b.ey;
	b.x_incr = 1;
	b.y_incr = 1;
	if (p1.x > p2.x)
		b.x_incr = -1;
	if (p1.y > p2.y)
		b.y_incr = -1;
	if (b.c_dx >= b.c_dy)
		first_case(&b, img, &p1);
	else if (b.c_dx <= b.c_dy)
		second_case(&b, img, &p1);
}

void	draw_verteces(t_coord *coord, t_pixel_to_image *img)
{
	int v;

	v = 0;
	while (v < coord->total_points)
	{
		ft_pixel_put_to_image(img, coord->verteces[v]);
		v++;
	}
}
void	join_x(t_coord *coord, t_pixel_to_image *img)
{
	int v;
	int x;
	int y;

	v = 0;
	x = 0;
	y = 0;
	while (y < coord->y_point - 1)
	{
		while (x < coord->x_point)
		{
			draw_line(img, *(coord->verteces[v]), *(coord->verteces[v + coord->x_point]));
			v++;
			x++;
		}
		x = 0;
		y++;
	}
	v = 0;
	x = 0;
	y = 0;
	while (y < coord->y_point)
	{
		while (x < coord->x_point - 1)
		{
			draw_line(img, *(coord->verteces[v]), *(coord->verteces[v + 1]));
			v++;
			x++;
		}
		x = 0;
		y++;
		v++;
	}
}
