#include "../includes/fdf.h"

int	count_y(void)
{
	int		fd;
	char	*line;
	int		j;
	int		y;

	while (get_next_line(fd, &line) == 1)
	{
		y++;
		printf("%d\n", y);
	}
	return (y);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	int x;
	int y;
	int y2 = count_y();
	int	width = 1280;
	int height = 720;
	int	color = 0xFFFFFF;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "fdf");
	y = 0;
	x = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putendl("Impossible d'ouvrir le fichier !");
			return (-1);
		}
		while (y <= y2)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
			printf("%d\n", y2);
		}
		mlx_clear_window(mlx, win);
		mlx_loop(mlx);
	}
}
