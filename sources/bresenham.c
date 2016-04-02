/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:36:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/30 15:38:18 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_segment_x(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	int	dx;
	int	dy;
	int	e;

	e = abs(x2 - x1);
	dx = abs(e * 2);
	dy = abs((y2 - y1) * 2);
	img->x = x1;
	img->y = y1;
	while (img->x <= x2)
	{
		ft_pixel_put_to_image(img);
		img->x++;
		if ((e = e - dy) <= 0)
		{
			img->y++;
			e = e + dx;
		}
	}
}

void	print_segment_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	int dx, dy;
	int e;

	e = abs(2 - y1);
	dy = abs(e * 2);
	dx = abs((x2 - x1) * 2);
	img->x = x1;
	img->y = y1;
	while (img->y != y2)
	{
		ft_pixel_put_to_image(img);
		if (img->y > y2)
			img->y--;
		else
			img->y++;
		if ((e -= dx) <= 0)
		{
			img->x++;
			e += dy;
		}
	}
	ft_pixel_put_to_image(img);
}

void	draw_x_or_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img)
{
	int	dx;
	int	dy;

	dx = abs(x2 - x1) * 2;
	dy = abs(y2 - y1) * 2;
	if (x1 > x2)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	if (dx > dy)
		print_segment_x(x1, y1, x2, y2, img);
	else
		print_segment_y(x1, y1, x2, y2, img);

}
