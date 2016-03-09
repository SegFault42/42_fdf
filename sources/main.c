#include "../includes/fdf.h"

int	count_y(void)
{
	int		fd;
	char	*line;
	int		j;
	int		y;

	j = 1;
	while (get_next_line(fd, &line) == j)
		y++;
	return (y);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	int x;
	int y;
	int	width = 1280;
	int height = 720;
	int	color = 0xFFFFFF;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putendl("Impossible d'ouvrir le fichier !");
			return (-1);
		}
	}
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "fdf");
	x = 100;
		while (y <= count_y())
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		color += 1;
	/*mlx_clear_window(mlx, win);*/
	mlx_loop(mlx);
}
