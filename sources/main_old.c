#include "../includes/fdf.h"

#define blue 0x23c5e3
#define white 0xFFFFFF
#define red 0xFF1616

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

int	main(int argc, char **argv)
{
	/*void	*mlx;*/
	/*void	*win;*/
	int		fd;
	int		width = 1280;
	int		height = 720;

	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		x = 400;
	int		y	= 0;

	check_arguments(&argc, (&(*argv)));
	/*mlx = mlx_init();*/
	/*win = mlx_new_window(mlx, width, height, "fdf");*/
	/*tracing_horizontal(&fd, mlx, win);*/
	/*mlx_clear_window(mlx, win);*/
	/*img_ptr = mlx_new_image(mlx_ptr, width, height);*/
	/*data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);*/
	/*win_ptr = mlx_new_window(mlx_ptr, width, height, "fdf");*/
	/*mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y++);*/
	/*mlx_loop(mlx_ptr);*/
}
