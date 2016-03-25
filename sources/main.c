#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					endian;
	int					width = 1280;
	int					height = 720;
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
	win_ptr = mlx_new_window(mlx_ptr, width, height, "FDF" );
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 200, 200);
	mlx_loop(mlx_ptr);
	return (0);
}
