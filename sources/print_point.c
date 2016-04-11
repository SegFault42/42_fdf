/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/09 22:27:42 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put_to_image(t_pixel_to_image *img, t_point *p)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int i;

	i = p->y * img->sizeline + p->x * img->bpp / 8;
	if (i < 0 || i > img->sizeline * HEIGHT || p->x > WIDTH || p->x < 0)
		return;
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

void	print_point(t_coord *coord, t_pixel_to_image *img, int gap)
{
	join_x(coord, img);
	/* int v = 0; */
	/* int w = 1; */
	/* while (v < coord->total_points) */
	/* { */
	/* 	printf("%d, %d ", coord->verteces[v]->x, coord->verteces[v]->y); */
	/* 	if (w == coord->x_point) */
	/* 	{ */
	/* 		printf("\n"); */
	/* 		w = 0; */
	/* 	} */
	/* 	w++; */
	/* 	v++; */
	/* } */
	/* exit(3); */
}
