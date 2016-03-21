#include "./includes/fdf.h"


static int	count_y(int *fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((get_next_line(*fd, &line)) > 0)
		i++;
	return (i);
}

static int	count_x(int *fd)
{
	char *line;
	char **var;
	int i = 0;
	int j = 0;

	while ((get_next_line(*fd, &line)) > 0)
	{
		var = ft_strsplit(line, ' ');
	}
	return (i);
}


static void	tracing_horizontal(int *fd, void *mlx, void *win)
{
	int	y_pos;
	int	cmp_y;
	int	x;
	int color = red;

	y_pos = 0;
	cmp_y = (count_y(&(*fd)) * 30);
	while (cmp_y > 0)
	{
		x = 0;
		if (cmp_y % 30 == 0)
		{
			while (x < 600)
			{
				mlx_pixel_put(mlx, win, x, y_pos, color);
				x++;
			}
		}
		y_pos++;
		cmp_y--;
	}
}

void	ft_pixel_put_to_image(unsigned long img_color, char *data, int sizeline, int bpp, int x, int y)
{
	int i;
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (img_color & 0xFF00000) >> 24;
	color2 = (img_color & 0xFF00000) >> 16;
	color3 = (img_color & 0xFF00000) >> 8;

	data[y * sizeline + x * bpp / 8 ] = color1;
	data[y * sizeline + x * bpp / 8 + 1] = color2;
	data[y * sizeline + x * bpp / 8 + 2] = color3;
	data[y * sizeline + x * bpp / 8 + 3] = 0x00; // opacite
}

int	main(int argc, char **argv)
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned long	img_color;
	int				x;
	int				y;
	int				width = 500;
	int				height = 500;
	int				fd;
	int				point_y;

	x = 100;
	y = 0;
	check_arguments(&argc, (&(*argv)), &fd);
	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);
	img_color = mlx_get_color_value(mlx_ptr, red);
	point_y = count_y(&fd);
	while (point_y)
	{
		while (y % 20)
			y++;
		ft_pixel_put_to_image(img_color, data, sizeline, bpp, x, y);
		point_y--;
		y++;
	}
	/*while (y < 200)*/
	/*{*/
		/*ft_pixel_put_to_image(img_color, data, sizeline, bpp, x++, y);*/
		/*if (x == 200)*/
		/*{*/
			/*y++;*/
			/*x = 100;*/
		/*}*/
	/*}*/
	win_ptr = mlx_new_window(mlx_ptr, width, height, "FDF c'est chaud en faite" );
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
