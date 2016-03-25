/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/25 20:01:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define WIDTH 500
# define HEIGHT 500

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
int					count_y(int *fd);
int					count_x(int *fd);
void				print_point(int *fd, t_pixel_to_image *image/*, void *img_ptr*/);
void				ft_pixel_put_to_image(t_pixel_to_image *image);

#endif
