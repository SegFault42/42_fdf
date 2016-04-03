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

void	ft_pixel_put_to_image(t_pixel_to_image *img)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 2] = r;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 1] = g;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 0] = b;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 2] = b;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 1] = g;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 0] = r;
		img->data[img->y * img->sizeline + img->x * img->bpp / 8 + 3] = 0x00;
	}
}

/*voidprint_point(int *fd, t_pixel_to_image *image)	*/
/*{*/
/*intpoint_y;*/
/*intpoint_x;*/
/*intsave_point_x;*/

/*point_x = count_x(fd);*/
/*point_y = count_y(fd);*/
/*save_point_x = point_x;*/
/*while (point_y >= 0)*/
/*{*/
/*while (point_x)*/
/*{*/
/*while (image->x % 10)*/
/*image->x++;*/
/*printf("x: %d\n", image->x);*/
/*image->x = image->x - image->y;*/
/*printf("x2: %d y2: %d\n", image->x, image->y);*/
/*ft_pixel_put_to_image(image);*/
/*point_x--;*/
/*image->x++;*/
/*}*/
/*image->x = 0;*/
/*point_x = save_point_x;*/
/*image->y++;*/
/*while (image->y % 10)*/
/*image->y++;*/
/*printf("y: %d\n", image->y);*/
/*image->y = image->y + image->x;*/
/*point_y--;*/
/*}*/
/*}*/

void	print_point(t_coord *coord, t_pixel_to_image *image)
{
	int		x;
	int		y;
	char	**split_x;
	int		zoom;

	zoom = 10;
	x = 0;
	y = 0;
	while (coord->map[y])
	{
		split_x = ft_strsplit(coord->map[y], ' ');
		while (split_x[x])
		{
			image->x = ((x * zoom) - (y * zoom)) + 650;
			image->y = ((x * zoom) + (y * zoom)) / 2 + 100;
			ft_pixel_put_to_image(image);
			x++;
		}
		tab_free(split_x);
		x = 0;
		y++;
	}
}
