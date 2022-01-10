/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 01:55:09 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 09:52:52 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_obj *obj, t_point a, t_point b)
{
	if ((a.x - b.x) * (b.y - a.y) == 0)
		straight_l(obj, a, b, color_m(0, 255, 0));
	else if ((b.x - a.x) * (b.y - a.y) > 0)
	{
		if ((b.x - a.x) >= 0)
			d_l(obj, a, b, color_m(0, 255, 0));
		else
			d_l(obj, b, a, color_m(0, 255, 0));
	}
	else if ((b.x - a.x) * (b.y - a.y) < 0)
	{
		if ((b.x - a.x) > 0)
			d_minus(obj, a, b, color_m(0, 255, 0));
		else
			d_minus(obj, b, a, color_m(0, 255, 0));
	}
	return (1);
}

int	draw_line2(t_obj *obj, t_point a, t_point b)
{
	if ((a.x - b.x) * (b.y - a.y) == 0)
		straight_l2(obj, a, b, color_m(0, 255, 0));
	else if ((b.x - a.x) * (b.y - a.y) > 0)
	{
		if ((b.x - a.x) >= 0)
			d_l2(obj, a, b, color_m(0, 255, 0));
		else
			d_l2(obj, b, a, color_m(0, 255, 0));
	}
	else
	{
		if ((b.x - a.x) > 0)
			d_minus2(obj, a, b, color_m(0, 255, 0));
		else
			d_minus2(obj, b, a, color_m(0, 255, 0));
	}
	return (1);
}
