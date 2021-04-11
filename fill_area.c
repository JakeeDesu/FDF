/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 08:57:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/17 05:36:14 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cross_point(t_point a, t_point b, t_point *p, int x)
{
	double	m;
	double	c;
	int		x_max;
	int		x_min;

	x_max = (a.x > b.x) ? a.x : b.x;
	x_min = (a.x < b.x) ? a.x : b.x;
	if (x <= x_min || x > x_max)
		return (0);
	p->x = x;
	if ((a.x - b.x) * (b.y - a.y) == 0)
	{
		p->y = a.y;
	}
	else
	{
		m = (float)(b.y - a.y) / (float)(b.x - a.x);
		c = (a.y - (m * a.x));
		p->y = ((m * p->x) + c) + 0.5;
	}
	to_color(p, c_g(&a, *p, b));
	return (1);
}

void	fill(t_obj *obj, t_elem *p, t_point x, int m)
{
	t_point	p1;
	t_point	p2;
	t_point	*px;

	m = x.y;
	while ((m) <= (x.x))
	{
		px = &p1;
		if (cross_point(p->p, p->left->p, px, m))
			px = &p2;
		if ((cross_point(p->p, p->down->p, px, m)))
			px = &p2;
		if ((cross_point(p->left->p, p->left->down->p, px, m)))
			px = &p2;
		if ((cross_point(p->down->p, p->left->down->p, px, m)))
			px = &p2;
		draw_line(obj, p1, p2);
		m++;
	}
}

void	fill_area(t_obj *obj, t_elem *p)
{
	int		m;
	t_point	x;

	if (p && p->left && p->down && p->left->down)
	{
		x.x = (p->p.x > p->left->p.x) ? p->p.x : p->left->p.x;
		if (p->down->p.x > p->left->down->p.x)
			m = p->down->p.x;
		else
			m = p->left->down->p.x;
		x.x = (x.x > m) ? x.x : m;
		x.y = (p->p.x < p->left->p.x) ? p->p.x : p->left->p.x;
		if (p->down->p.x < p->left->down->p.x)
			m = p->down->p.x;
		else
			m = p->left->down->p.x;
		x.y = (x.y < m) ? x.y : m;
		m = x.y;
		fill(obj, p, x, m);
	}
}
