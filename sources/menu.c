/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:57:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/11 23:38:13 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_context *c)
{
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, GREEN, "Esc         = Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, GREEN, "+           = Zoom in");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 40, GREEN, "-           = Zoom out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 55, GREEN, "R           = Reset");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 70, GREEN, "- (Num pad) = Level -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 85, GREEN, "+ (Num pad) = Level +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 1750, 10, GREEN, "1 = Front view");
}
