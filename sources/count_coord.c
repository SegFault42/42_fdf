/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_x_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:32:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/07 19:35:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_coord(char *file_name, t_coord *coord)
{
	coord->map = NULL;
	count_line_in_file(file_name, coord);
}

void	count_line_in_file(char *file_name, t_coord *coord)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		if (i++ == 0)
			x_len = tab_len(split);
		coord->x_point = tab_len(split);
		tab_free(split);
		if (x_len != coord->x_point)
		{
			ft_putendl("Map not well formatted !");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	check_ret_gnl(&fd, line);
	coord->y_point = i;
	close(fd);
}

void	stock_coord(char *file_name, t_coord *coord)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	init_coord(file_name, coord);
	fd = open(file_name, O_RDONLY);
	coord->map = (int **)malloc(sizeof(int *) * coord->y_point);
	while (get_next_line(fd, &line) > 0)
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
	close(fd);
}
