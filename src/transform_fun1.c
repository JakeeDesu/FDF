/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_fun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:56:15 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 09:19:46 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_vec(t_vector *v, int x, int y, int z)
{
	v->x += (double)x;
	v->y += (double)y;
	v->z += (double)z;
}

void	scale_vec(t_vector *v, double s)
{
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

void	rotz_vec(t_vector *v, t_map *l)
{
	t_vector t;

	t.x = v->x;
	t.y = v->y;
	v->x = (t.x * cos(l->hat.rot.z)) + (t.y * (-sin(l->hat.rot.z)));
	v->y = (t.x * sin(l->hat.rot.z)) + (t.y * cos(l->hat.rot.z));
}

void	rotx_vec(t_vector *v, t_map *l)
{
	t_vector t;

	t.z = v->z;
	t.y = v->y;
	v->y = (t.y * cos(l->hat.rot.x)) + (t.z * -sin(l->hat.rot.x));
	v->z = (t.y * sin(l->hat.rot.x)) + (t.z * cos(l->hat.rot.x));
}

void	roty_vec(t_vector *v, t_map *l)
{
	t_vector t;

	t.x = v->x;
	t.z = v->z;
	v->x = (t.x * cos(l->hat.rot.y)) + (t.z * sin(l->hat.rot.y));
	v->z = (t.x * -sin(l->hat.rot.y)) + (t.z * cos(l->hat.rot.y));
}
