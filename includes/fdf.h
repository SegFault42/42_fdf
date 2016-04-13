/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/13 21:31:21 by rabougue         ###   ########.fr       */
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
# include "./keyboard.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define PURPLE 0x993299
# define DARK_GREY 0x3b3b3b

# define WIDTH 1280
# define HEIGHT 720

# define ORIGIN_X (WIDTH / 2)
# define ORIGIN_Y (HEIGHT / 3)

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

typedef struct			s_p
{
	int					x;
	int					y;
}						t_p;

typedef struct			s_coord
{
	int					x_point;
	int					y_point;
	int					**map;
}						t_coord;

typedef struct			s_pti
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_pti;

typedef struct			s_c
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_pti				*pti;
	t_coord				*coord;
}						t_c;

void					draw_x_or_y(int x1, int y1, int x2, int y2, t_pti *img);
void					ft_pixel_put_to_image(t_pti *image, t_p *p);
void					draw_line(t_pti *img, t_p *p1, t_p *p2);
void					second_case(t_bres *b, t_pti *img, t_p *p1);
void					first_case(t_bres *b, t_pti *img, t_p *p1);
void					draw_x(t_coord *c, t_pti *img, int gap, int level, int iso, int or_x, int or_y);
void					draw_y(t_coord *c, t_pti *img, int gap, int level, int iso, int or_x, int or_y);
void					count_line_in_file(char *file_name, t_coord *coord);
void					print_p(t_coord *coord, t_pti *img, int gap, int level, int iso, int or_x, int or_y);
int						check_arguments(int *argc, char **argv, int *fd);
void					stock_coord(char *file_name, t_coord *coord);
void					init_coord(char *file_name, t_coord *coord);
void					open_map(int *argc, char **argv, int *fd);
void					check_len_map(int x_len, t_coord *coord);
int						key_hook(int keycode, void *param, t_pti *img, t_p *p);
void					count_coord(int *fd, t_coord *coord);
void					check_ret_gnl(int *fd, char *line);
void					menu(t_c *c);
void					clear_image(void *param, t_pti *img, t_p *p);

#endif
