/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:01:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/09 14:43:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_arguments(int *argc, char **argv, int *fd)
{
	if (*argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <filename>");
		exit(EXIT_FAILURE);
	}
	open_map(&(*argv), fd);
	return (EXIT_SUCCESS);
}

void	open_map(char **argv, int *fd)
{
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "/dev", 4) == 0)
	{
		ft_putendl("Map not well formatted");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp_ext(argv[1], ".fdf") == 1)
	{
		ft_putendl("Map not well formatted");
		exit(EXIT_FAILURE);
	}
}

void	check_ret_gnl(int *fd, char *line)
{
	if (get_next_line(*fd, &line) < 0)
	{
		ft_putendl("Not a valid file");
		exit(EXIT_FAILURE);
	}
}

void	check_len_map(int x_len, t_coord *coord)
{
	if (x_len != coord->x_point)
	{
		ft_putendl("Map not well formatted");
		exit(EXIT_FAILURE);
	}
}
