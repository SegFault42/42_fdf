/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/29 18:22:04 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_x(int *fd)
{
	char	*line;
	char	**ret;
	int		i;

	i = 0;
	get_next_line(*fd, &line);
	ret = ft_strsplit(line, ' ');
	while (ret[i])
		i++;
	return (i);
}

int		count_y(int *fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((get_next_line(*fd, &line)) > 0)
		i++;
	return (i);
}

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

void	print_point(int *fd, t_pixel_to_image *image)
{
	int i;
	int j;
	int	point_y;
	int	point_x;

	i = 0;
	j = 0;
	point_x = count_x(fd);
	point_y = count_y(fd);
	while (j < point_y)
	{
		while (i < point_x)
		{
			image->x = (i * 20) - (j * 20) + 500;
			image->y = (i * 20) + (j * 20) + 500;
			if (i + 1 <= point_x)
				draw_x_or_y(image->x, image->y, ((i + 1) * 20) - (j * 20) + 500
				, ((i + 1) * 20) + (j * 20) + 500, image);
			if (j + 1 <= point_y)
				draw_x_or_y(image->x, image->y, (i * 20) - ((j + 1) * 20) + 500
				, (i * 20) + ((j + 1) * 20) + 500, image);
			i++;
		}
		i = 0;
		j++;
	}
}
