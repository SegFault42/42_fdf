#include "./includes/fdf.h"

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

void	ft_pixel_put_to_image(t_pixel_to_image *image)
{
	int				i;
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = (image->img_color & 0xFF00000) >> 24;
	color2 = (image->img_color & 0xFF00000) >> 16;
	color3 = (image->img_color & 0xFF00000) >> 8;

	image->data[image->y * image->sizeline + image->x * image->bpp / 8 ] = color1;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 1] = color2;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 2] = color3;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 3] = 0x00;
}

/*void	print_point(int *fd, t_pixel_to_image *image)*/
/*{*/
/*int		point_y;*/
/*int		point_x;*/

/*point_y = count_y(fd);*/
/*[>while (point_y)<]*/
/*[>{<]*/
/*point_x = count_x(fd);*/
/*while (point_x)*/
/*{*/
/*while (image->x % 20)*/
/*image->x++;*/
/*ft_pixel_put_to_image(image);*/
/*point_x--;*/
/*image->x++;*/
/*}*/
/*[>point_y--;<]*/
/*[>image->y++;<]*/
/*[>while (image->y % 20)<]*/
/*[>image->y++;<]*/
/*[>}<]*/
/*}*/

void	print_point(int *fd, t_pixel_to_image *image)
{
	int	point_y;
	int	point_x;
	int	save_point_x;

	point_x = count_x(fd);
	point_y = count_y(fd);
	save_point_x = point_x;
	while (point_y)
	{
		image->x = 0;
		point_x = save_point_x;
		image->y++;
		while (image->y % 20)
			image->y++;
		/*ft_pixel_put_to_image(image);*/
		point_y--;
		image->y++;
		while (point_x)
		{
			while (image->x % 20)
			{
				image->x++;
			}
			ft_pixel_put_to_image(image);
			point_x--;
			image->x++;
		}
	}
}
