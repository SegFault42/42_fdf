#include "./includes/fdf.h"

int	count_y(int *fd)
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
	int i;
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (image->img_color & 0xFF00000) >> 24;
	color2 = (image->img_color & 0xFF00000) >> 16;
	color3 = (image->img_color & 0xFF00000) >> 8;

	image->data[image->y * image->sizeline + image->x * image->bpp / 8 ] = color1;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 1] = color2;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 2] = color3;
	image->data[image->y * image->sizeline + image->x * image->bpp / 8 + 3] = 0x00;
}

void	print_point(int *fd, t_pixel_to_image *image)
{
	int		point_y;

	point_y = count_y(fd);
	while (point_y)
	{
		while (image->y % 20)
			image->y++;
		ft_pixel_put_to_image(image);
		point_y--;
		image->y++;
	}
}
