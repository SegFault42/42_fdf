/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:03:01 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/02 14:43:08 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					fd;
	t_pixel_to_image	im;
	t_coord				coord;

	im.x = 0;
	im.y = 0;
	check_arguments(&argc, (&(*argv)), &fd);
	count_coord(&fd, &coord);
	RC;
	stock_coord(&fd, &argc, (&(*argv)), &coord);
	/*mlx_ptr = mlx_init();*/
	/*img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);*/
	/*im.data = mlx_get_data_addr(img_ptr, &im.bpp, &im.sizeline, &im.endian);*/
	/*im.img_color = mlx_get_color_value(mlx_ptr, WHITE);*/
	/*print_point(&fd, &im);*/
	/*win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FDF");*/
	/*mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);*/
	/*mlx_loop(mlx_ptr);*/
	return (0);
}
