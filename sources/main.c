#include "../includes/fdf.h"
#include <unistd.h>


int	count_y(int *fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((get_next_line(*fd, &line)) > 0)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	int		x;
	int		y;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("Impossible d'ouvrir le fichier.");
		return (-1);
	}
	y = (count_y(&fd) * 10);
	int	width = 1280;
	int	height = 720;
	int	color = 0xFFFFFF;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "fdf");
	x = 0;
	while (y)
	{
		mlx_pixel_put(mlx, win, x, y, color);
		y--;
	}
	/*mlx_clear_window(mlx, win);*/
	mlx_loop(mlx);
}
