/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:02:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/26 22:31:04 by rabougue         ###   ########.fr       */
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

/*void	print_point(int *fd, t_pixel_to_image *image)*/
/*{*/
	/*int	point_y;*/
	/*int	point_x;*/
	/*int	save_point_x;*/

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


void	print_point(int *fd, t_pixel_to_image *image)
{
	int	point_y;
	int	point_x;
	int i;
	int j;

	point_x = count_x(fd);
	point_y = count_y(fd);
	i = 0;
	j = 0;
	while (j <= point_y)
	{
		while (i < point_x)
		{
			image->x = (i * 20) - (j * 20) + 500;
			image->y = (i * 20) + (j * 20) + 500;
			printf("i = %d x2: %d y2: %d\n",i , image->x, image->y);
			ft_pixel_put_to_image(image);
			i++;
		}
		i = 0;
		j++;
		printf("y: %d\n", image->y);
	}
}
