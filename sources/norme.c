/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:58:26 by rabougue          #+#    #+#             */
/*   Updated: 2016/04/15 01:02:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	split_draw(t_p *p2, t_xy *xy, t_bonus *b, t_coord c)
{
	p2->x = ((xy->x * b->gap) - (xy->y * b->gap)) + b->or_x;
	p2->y = ((xy->x * b->gap) + (xy->y * b->gap)) / b->iso + b->or_y
		- (c.map[xy->y][xy->x] * b->level);
}

void	split_draw_x_2(t_p *p1, t_p *p2, t_xy *xy)
{
	xy->x++;
	p1->x = p2->x;
	p1->y = p2->y;
}

void	split_draw_y_2(t_p *p1, t_p *p2, t_xy *xy)
{
	xy->y++;
	p1->x = p2->x;
	p1->y = p2->y;
}
