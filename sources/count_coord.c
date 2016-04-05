/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_x_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:32:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/05 23:28:34 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_coord(char *file_name, t_coord *coord)
{

	coord->map = NULL;
	count_line_in_file(file_name, coord);
}

void		count_line_in_file(char *file_name, t_coord *coord)
{
	char	*line;
	int		i;
	int		fd;
	int		passage;
	char	**split;

	i = 0;
	passage = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (passage++ == 0)
		{
			split = ft_strsplit(line, ' ');
			coord->x_point = tab_len(split);
			tab_free(split);
		}
		i++;
		free(line);
	}
	coord->y_point = i;
	close(fd);
}


void	stock_coord(char *file_name, t_coord *coord)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	init_coord(file_name, coord);
	fd = open(file_name, O_RDONLY);
	coord->map = (char **)malloc(sizeof(char *) * coord->y_point + 1);
	while (get_next_line(fd, &line) > 0)
		coord->map[i++] = ft_strdup(line);
	coord->map[i] = NULL;
	i = 0;
	//printf
	while (coord->map[i])
		printf("%s\n", coord->map[i++]);
}
