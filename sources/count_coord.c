/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:32:47 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/11 16:35:50 by cattouma         ###   ########.fr       */
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
		check_len_map(x_len, coord);
		free(line);
	}
	check_ret_gnl(&fd, line);
	coord->total_points = x_len * i;;
	coord->y_point = i;
	close(fd);
}


void	stock_coord(char *file_name, t_coord *coord)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	char	**split;
	int		v;
	int		gap;
	int		c_height;

	x = 0;
	y = 0;
	v = 0;
	gap = 20;
	c_height = 10;
	init_coord(file_name, coord);
	fd = open(file_name, O_RDONLY);
	coord->verteces = (t_point **)malloc(sizeof(t_point *) * coord->total_points);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		while (x < coord->x_point)
		{
			coord->verteces[v] = (t_point *)malloc(sizeof(t_point));
			coord->verteces[v]->x = ((x * gap) - (y * gap)) + ORIGIN_X;
			coord->verteces[v]->y = ((x * gap) + (y * gap)) / 2 + ORIGIN_Y - (ft_atoi(split[x]) * c_height);
			v++;
			x++;
		}
		tab_free(split);
		free(line);
		x = 0;
		y++;
	}
	/* v = 0; */
	/* int w = 1; */
	/* while (v < coord->total_points) */
	/* { */
	/* 	printf("%d, %d ", coord->verteces[v]->x, coord->verteces[v]->y); */
	/* 	if (w == coord->x_point) */
	/* 	{ */
	/* 		printf("\n"); */
	/* 		w = 0; */
	/* 	} */
	/* 	w++; */
	/* 	v++; */
	/* } */
	close(fd);
}
