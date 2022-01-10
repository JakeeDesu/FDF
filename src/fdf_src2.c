/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:26:50 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/16 22:37:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot(t_rot *rot, double z, double x, double y)
{
	rot->z = z;
	rot->x = x;
	rot->y = y;
}

void	to_color(t_point *p, int c)
{
	p->color.r = c / 65536;
	p->color.g = (c % 65536) / 256;
	p->color.b = c % 256;
}

int		color(int r, int g, int b)
{
	int c;

	c = 0;
	if (r > 0)
		c += r * 65536;
	if (g > 0)
		c += g * 256;
	if (b > 0)
		c += b;
	return (c);
}

void	edit_colo(t_point *a, int r, int g, int b)
{
	a->color.r = r;
	a->color.g = g;
	a->color.b = b;
}

void	init_x_ev(t_obj *obj, int k_p, int m_p, int m_r)
{
	obj->x_ev[0] = k_p;
	obj->x_ev[2] = m_p;
	obj->x_ev[3] = m_r;
}
