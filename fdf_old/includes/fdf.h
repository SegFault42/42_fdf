/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/02 14:43:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

# define HEIGHT 500
# define WIDTH 700

typedef struct		s_coord
{
	int				x_point;
	int				y_point;
	int				z_point;
	int				x_temp;
	int				**map;
}					t_coord;

typedef struct		s_pixel_to_image
{
	unsigned long	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
	int				x;
	int				y;
}					t_pixel_to_image;

int					check_arguments(int *argc, char **argv, int *fd);
void				open_map(int *argc, char **argv, int *fd);
int					count_y(int *fd);
int					count_x(int *fd);
void				print_point(int *fd, t_pixel_to_image *image);
void				ft_pixel_put_to_image(t_pixel_to_image *image);
void				draw_x_or_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img);
void				count_coord(int *fd, t_coord *coord);
void				stock_coord(int *fd, int *argc, char **argv, t_coord *coord);


#endif
