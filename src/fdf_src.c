/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:24:17 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/16 01:03:55 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	vector(t_vector *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	p_to_v(t_vector *v, t_point p)
{
	v->x = (double)p.x;
	v->y = (double)p.y;
	v->z = (double)p.z;
}

void	c_to_c(t_color *c1, t_color c2)
{
	c1->r = c2.r;
	c1->g = c2.g;
	c1->b = c2.b;
}

void	gen_c(t_point *p)
{
	p->c = color(p->color.r, p->color.g, p->color.b);
}
