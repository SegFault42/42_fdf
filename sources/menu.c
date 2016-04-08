/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:57:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/08 15:44:02 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_context *c)
{
	mlx_string_put(c->mlx_ptr, c->win_ptr, 0, -5, GREEN, "Menu");


	/*int	fd;*/
	/*char **line;*/

	/*fd = open("../test", O_RDONLY);*/
	/*while (get_next_line(fd, line) > 0)*/
	/*{*/
		/*printf("%s", *line);*/
		/*mlx_string_put(c->mlx_ptr, c->win_ptr, 0, 0, GREEN, *line);*/
	/*}*/
}
