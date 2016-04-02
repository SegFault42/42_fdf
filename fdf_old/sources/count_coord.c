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

void	count_coord(int *fd, t_coord *coord)
{
	char	*line;
	char	**ret;
	int		**tab;
	int		var;

	coord->x_temp = 0;
	coord->y_point = 0;
	coord->x_point = 1;
	while ((var = get_next_line(*fd, &line)) > 0)
	{
		ret = ft_strsplit(line, ' ');
		while (ret[coord->x_point])
		{
			/*tab[j][i] = ft_atoi(ret[coord->x_point]);*/
			printf("(ret) ret[%d] = %s\n", coord->x_point, ret[coord->x_point]);
			/*printf("(tab) tab[j][%d] = %d\n", coord->x_point, tab[j][i]);*/
			coord->x_point++;
		}
		coord->y_point++;
		if (coord->x_point > coord->x_temp)
			coord->x_temp = coord->x_point;
		coord->x_point = 0;
	}
	close(*fd);
}

void	stock_coord(int *fd, int *argc, char **argv, t_coord *coord)
{
	int var;

	open_map(argc, argv, fd);
	printf("le fichier contient %d ligne(s)\n", coord->y_point);
	printf("la ligne la plus grande contient %d int\n", coord->x_temp);
	coord->map = (coord **)malloc(sizeof(coord **) * coord->y_point);
	while ((var = get_next_line(*fd, &line)) > 0)
	{
		
	}
}
