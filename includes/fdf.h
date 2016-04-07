/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/07 19:34:20 by rabougue         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

# define ORIGIN_X (WIDTH / 3)
# define ORIGIN_Y (HEIGHT / 8)

typedef	struct			s_bres
{
	int					dx;
	int					dy;
	int					e;
	int					x_incr;
	int					y_incr;
	int					c_dx;
	int					c_dy;
	int					ex;
	int					ey;
}						t_bres;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_coord
{
	int					x_point;
	int					y_point;
	int					**map;
}						t_coord;

typedef struct			s_context
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
}						t_context;

typedef struct			s_pixel_to_image
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_pixel_to_image;

void					draw_line(t_pixel_to_image *img, t_point *p1, t_point *p2);
int						check_arguments(int *argc, char **argv, int *fd);
void					open_map(int *argc, char **argv, int *fd);
int						count_y(int *fd);
int						count_x(int *fd);
void					print_point(t_coord *coord, t_pixel_to_image *img);
void					ft_pixel_put_to_image(t_pixel_to_image *image, t_point *p);
void					draw_x_or_y(int x1, int y1, int x2, int y2, t_pixel_to_image *img);
void					count_coord(int *fd, t_coord *coord);
void					stock_coord(char *file_name, t_coord *coord);
void					init_coord(char *file_name, t_coord *coord);
void					count_line_in_file(char *file_name, t_coord *coord);
void					check_ret_gnl(int *fd, char *line);
void 					draw_x(t_coord *coord, t_pixel_to_image *img, int gap);
void					draw_y(t_coord *coord, t_pixel_to_image *img, int gap);
void					second_case(t_bres *b, t_pixel_to_image *img, t_point *p1);
void					first_case(t_bres *b, t_pixel_to_image *img, t_point *p1);



#endif
