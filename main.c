#include "./includes/fdf.h"

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

	while ((get_next_line(*fd, &line)) > 0)
	{
		var = ft_strsplit(line, ' ');
		while (var[i])
			i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	/*void	*mlx;*/
	/*void	*win;*/
	int		fd;
	/*int		x;*/
	/*int		y_pos;*/
	/*int cmp;*/

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("Impossible d'ouvrir le fichier.");
		return (-1);
	}
	count_x(&fd);
	/*y_pos = 200;*/
	/*int	width = 1280;*/
	/*int	height = 720;*/
	/*int	color = red;*/
	/*cmp = (count_y(&fd) * 10);*/
	/*mlx = mlx_init();*/
	/*win = mlx_new_window(mlx, width, height, "fdf");*/
	/*while (cmp > 0)*/
	/*{*/
	/*x = 0;*/
	/*mlx_pixel_put(mlx, win, x, y_pos, color);*/
	/*if (cmp % 10 == 0)*/
	/*{*/
	/*while (x < 600)*/
	/*{*/
	/*mlx_pixel_put(mlx, win, x, y_pos, color);*/
	/*x++;*/
	/*}*/
	/*}*/
	/*y_pos++;*/
	/*cmp--;*/
	/*}*/
	/*[>mlx_clear_window(mlx, win);<]*/
	/*mlx_loop(mlx);*/
}
