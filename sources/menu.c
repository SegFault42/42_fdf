/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:57:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 22:46:30 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_c *c)
{
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, WHITE, "Esc = Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, WHITE, "+   = Zoom in");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 40, WHITE, "-   = Zoom out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 55, WHITE, "R   = Reset");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 70, WHITE, "P   = Level +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 85, WHITE, "O   = Level -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 100, WHITE, ">   = Move Right");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 115, WHITE, "<   = Move Left");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 130, WHITE, "^   = Move Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 145, WHITE, "v   = Move Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 160, WHITE, "T  = Rotate Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 175, WHITE, "G  = Rotate Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 190, WHITE, "1  = Front view");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 205, WHITE, "2  = Top view");
	menu2(c);
}

void	menu2(t_c *c)
{
	char	*x;
	char	*y;

	y = ft_itoa(c->bonus->or_y);
	x = ft_itoa(c->bonus->or_x);
	if (c->bonus->or_x >= 0)
		mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 220, GREEN, x);
	if (c->bonus->or_y >= 180)
		mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 235, GREEN, y);
	else
		mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 235, RED, y);
	if (c->bonus->or_x < 0 || c->bonus->or_x > WIDTH)
		mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 220, RED, x);
	if (c->bonus->or_y < 0 || c->bonus->or_y > (HEIGHT + 170))
		mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 235, RED, y);
}
