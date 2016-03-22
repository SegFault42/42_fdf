#include "./includes/fdf.h"

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

int	main(int argc, char **argv)
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					endian;
	int					width = 500;
	int					height = 500;
	int					fd;
	t_pixel_to_image	image;

	image.x = 0;
	image.y = 0;
	check_arguments(&argc, (&(*argv)), &fd);
	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	image.data = mlx_get_data_addr(img_ptr, &image.bpp, &image.sizeline, &endian);
	image.img_color = mlx_get_color_value(mlx_ptr, red);
	print_point(&fd, &image);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "FDF c'est chaud en faite" );
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_loop(mlx_ptr);
	return (0);
}
