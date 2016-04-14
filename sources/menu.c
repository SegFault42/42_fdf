/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:57:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/14 20:42:54 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_c *c)
{
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, GREEN, "Esc = Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, GREEN, "+   = Zoom in");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 40, GREEN, "-   = Zoom out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 55, GREEN, "R   = Reset");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 70, GREEN, "P   = Level +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 85, GREEN, "O   = Level -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 100, GREEN, ">   = Move Right");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 115, GREEN, "<   = Move Left");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 130, GREEN, "^   = Move Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 145, GREEN, "v   = Move Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 160, GREEN, "T  = Rotate Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 175, GREEN, "G  = Rotate Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 190, GREEN, "1  = Front view");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 205, GREEN, "2  = Top view");
}
