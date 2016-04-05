/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:03:01 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/05 18:35:08 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* void mouse_hook (int button, int x, int y, void *context, t_pixel_to_image *img) */
/* { */
/* 	t_context *c; */
/*  */
/* 	c = (t_context *)context; */
/* 	if (button == 1) */
/* 	{ */
/* 		draw_x_or_y(WIDTH / 2, HEIGHT / 2, x, y, img); */
/* 		expose_hook(c); */
/* 	} */
/* } */

int	main(int argc, char **argv)
{
	t_context			c;
	int					fd;
	t_pixel_to_image	im;
	t_coord				coord;
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;
	t_point	p5;
	t_point	p6;
	/* t_point	p7; */
	/* t_point	p8; */

	p1.x = WIDTH / 2;
	p1.y = HEIGHT / 2;
	p2.x = p1.x + 200;
	p2.y = p1.y;
	p3.x = p2.x - 100;
	p3.y = p1.y;
	p4.x = p3.x;
   	p4.y = p1.y - 100;
	p5.x = p4.x;
   	p5.y = p4.y;	
	p6.x = p4.x;
   	p6.y = p5.y + 200;	
	

	check_arguments(&argc, (&(*argv)), &fd);
	stock_coord(argv[1], &coord);
	c.mlx_ptr = mlx_init();
	c.img_ptr = mlx_new_image(c.mlx_ptr, WIDTH, HEIGHT);
	im.data = mlx_get_data_addr(c.img_ptr, &im.bpp, &im.sizeline, &im.endian);
	im.img_color = mlx_get_color_value(c.mlx_ptr, WHITE);
	//print_point(&coord, &im);
	draw_line(&im, &p1, &p2);
	draw_line(&im, &p3, &p4);
	draw_line(&im, &p5, &p6);
	c.win_ptr = mlx_new_window(c.mlx_ptr, WIDTH, HEIGHT, "FDF");
	//mlx_mouse_hook(c.win_ptr, mouse_hook, &c);
	mlx_put_image_to_window(c.mlx_ptr, c.win_ptr, c.img_ptr, 0, 0);
	mlx_loop(c.mlx_ptr);
	return (0);
}
