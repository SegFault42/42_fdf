/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_x_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:32:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/02 14:24:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_coord(char *file_name, t_coord *coord)
{
	coord->x_point = 0;
	coord->z_point = 0;
	coord->y_point = count_line_in_file(file_name);
	coord->map = NULL;
}

int		count_line_in_file(char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}


void	stock_coord(char *file_name, t_coord *coord)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	i = 0;
	init_coord(file_name, coord);
	fd = open(file_name, O_RDONLY);
	coord->map = (char **)malloc(sizeof(char *) * coord->y_point + 1);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		coord->map[i++] = ft_strdup(line);
		tab_free(split);
	}
	coord->map[i] = NULL;
	i = 0;
	while (coord->map[i])
		printf("%s\n", coord->map[i++]);
}
