/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/08 22:58:58 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_context *cont, int gap, t_coord *coord, t_pixel_to_image *img)
{
	int static x = 100;

	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 27)
	{
		mlx_clear_window(cont->mlx_ptr, cont->win_ptr);
		gap--;
		print_point(coord, img, gap);
		mlx_put_image_to_window(cont->mlx_ptr, cont->win_ptr, cont->img_ptr, 0, 0);
	}
	return (0);
}
