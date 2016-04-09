/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:57:03 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/09 16:52:43 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *param)
{
	int static	x = 0;
	int static	gap = 1;
	
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 24)
	{
		/*mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);*/
		mlx_clear_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		gap++;
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	if (keycode == 27)
	{
		/*mlx_destroy_image(((t_context *)param)->mlx_ptr, ((t_context *)param)->img_ptr);*/
		mlx_clear_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr);
		gap--;
		print_point(((t_context *)param)->coord, ((t_context *)param)->pti, gap);
		mlx_put_image_to_window(((t_context *)param)->mlx_ptr, ((t_context *)param)->win_ptr, ((t_context *)param)->img_ptr, 0, 0);
	}
	return (0);
}
