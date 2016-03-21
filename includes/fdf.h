/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/14 17:43:13 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <errno.h>
#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"

#define blue 0x23c5e3
#define white 0xFFFFFF
#define red 0xFF1616

int	check_arguments(int *argc, char **argv, int *fd);

#endif
