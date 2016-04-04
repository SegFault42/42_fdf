/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/30 19:38:12 by rabougue         ###   ########.fr       */
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

void	print_point(t_coord *coord, t_pixel_to_image *img)
{
	char	**split_x;
	int		zoom;
	t_point	point;
	t_point	point_iso;

	zoom = 20;
	point.x = 0;
	point.y = 0;
	while (coord->map[point.y])
	{
		split_x = ft_strsplit(coord->map[point.y], ' ');
		while (split_x[point.x])
		{
			point_iso.x = ((point.x* zoom) - (point.y * zoom));
			point_iso.y = ((point.x* zoom) + (point.y * zoom)) / 2;
			/*if (point.x + 1 <= tab_len(split_x))*/
				/*[>draw_x_or_y(point_iso.x, point_iso.y, ((point.x + 1) * zoom - (point.y * zoom)) + 500, ((point.x + 1) * zoom) + (point.y * zoom) + 500, img);<]*/
				/*draw_x_or_y(point_iso.x, point_iso.y, point.x, point.x, img);*/
			/*if (point.y + 1 <= coord->y_point)*/
				/*[>draw_x_or_y(point_iso.x, point_iso.y, (point.x * zoom - ((point.y + 1) * zoom)) + 500, (point.x * zoom) + ((point.y + 1) * zoom) + 500, img);<]*/
				/*draw_x_or_y(point_iso.x, point_iso.y, point.x + 500, point.x + 500, img);*/
			ft_pixel_put_to_image(img, &point_iso);
			point.x++;
		}
		tab_free(split_x);
		point.x = 0;
		point.y++;
	}
}
