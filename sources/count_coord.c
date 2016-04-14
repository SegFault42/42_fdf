/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:32:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 01:03:14 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_coord(char *file, t_coord *coord)
{
	coord->map = NULL;
	count_line_in_file(file, coord);
}

void	count_line_in_file(char *file, t_coord *coord)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		if (i++ == 0)
			x_len = tab_len(split);
		coord->x_point = tab_len(split);
		tab_free(split);
		check_len_map(x_len, coord);
		free(line);
	}
	check_ret_gnl(&fd, line);
	coord->y_point = i;
	close(fd);
}

void	stock_coord(char *file, t_coord *coord, t_xpm *xpm)
{
	char	*line;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	init_coord(file, coord);
	xpm->fd = open(file, O_RDONLY);
	coord->map = (int **)malloc(sizeof(int *) * coord->y_point);
	while (get_next_line(xpm->fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		coord->map[i] = (int *)malloc(sizeof(int) * coord->x_point);
		while (j < coord->x_point)
		{
			coord->map[i][j] = ft_atoi(split[j]);
			j++;
		}
		tab_free(split);
		free(line);
		j = 0;
		i++;
	}
	close(xpm->fd);
}
