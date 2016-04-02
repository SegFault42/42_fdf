/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:01:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/27 17:55:11 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Gerer si on ouvre un dossier au lieu d'un fichier
*/

int	check_arguments(int *argc, char **argv, int *fd)
{
	if (*argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <filename>");
		exit(1);
	}
	open_map(argc, &(*argv), fd);
	return (EXIT_SUCCESS);
}

void	open_map(int *argc, char **argv, int *fd)
{
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(1);
	}
}
