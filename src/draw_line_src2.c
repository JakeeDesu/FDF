/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fun_src.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:17:19 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 10:07:18 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	color_m(int r, int g, int b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

int		eq_c(t_color a, t_color b)
{
	if (a.r != b.r)
		return (0);
	if (a.g != b.g)
		return (0);
	if (a.b != b.b)
		return (0);
	return (1);
}

double	total_dis(t_point *start, t_point a, t_point b)
{
	int dx;
	int dy;

	dx = (b.x - start->x) < 0 ? (b.x - start->x) * (-1) : (b.x - start->x);
	dy = (b.y - start->y) < 0 ? (b.y - start->y) * (-1) : (b.y - start->y);
	return (sqrt((dx * dx) + (dy * dy)));
}

double	curr_dis(t_point *start, t_point a, t_point b)
{
	int dx;
	int dy;

	dx = (a.x - start->x) < 0 ? (a.x - start->x) * (-1) : (a.x - start->x);
	dy = (a.y - start->y) < 0 ? (a.y - start->y) * (-1) : (a.y - start->y);
	return (sqrt((dx * dx) + (dy * dy)));
}

int		c_g(t_point *start, t_point a, t_point b)
{
	double	alpha;
	double	totald;
	double	dis;

	totald = total_dis(start, a, b);
	dis = curr_dis(start, a, b);
	alpha = dis / totald;
	a.color = start->color;
	a.color.r = a.color.r + ((b.color.r - a.color.r) * alpha);
	a.color.g = a.color.g + ((b.color.g - a.color.g) * alpha);
	a.color.b = a.color.b + ((b.color.b - a.color.b) * alpha);
	return (color(a.color.r, a.color.g, a.color.b));
}
