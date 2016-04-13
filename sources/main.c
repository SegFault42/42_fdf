/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:03:01 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/13 17:19:26 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_context			c;
	t_pixel_to_image	im;
	t_coord				coord;
	int					gap;
	int					level;
	int					fd;
	int					iso;
	int					origin_x;
	int					origin_y;
	int					width;
	int					height;
	void				*lil;

	gap = 20;
	level = 20;
	iso = 2;
	origin_x = WIDTH / 2;
	origin_y = HEIGHT / 3;
	check_arguments(&argc, (&(*argv)), &fd);
	stock_coord(argv[1], &coord);
	c.coord = &coord;
	c.mlx_ptr = mlx_init();
	c.img_ptr = mlx_new_image(c.mlx_ptr, WIDTH, HEIGHT);
	im.data = mlx_get_data_addr(c.img_ptr, &im.bpp, &im.sizeline, &im.endian);
	im.img_color = mlx_get_color_value(c.mlx_ptr, GREEN);
	c.pti = &im;
	c.win_ptr = mlx_new_window(c.mlx_ptr, WIDTH, HEIGHT, "FDF");
	lil = mlx_xpm_file_to_image(c.mlx_ptr, "pics/fsdfs.xpm", &width, &height);
	mlx_put_image_to_window(c.mlx_ptr, c.win_ptr, lil, 0, 0);
	mlx_hook(c.win_ptr, 2, 3, key_hook, (void*)&c);
	mlx_loop(c.mlx_ptr);
	return (0);
}
