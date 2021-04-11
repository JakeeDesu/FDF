/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_fun2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:11:08 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 18:03:43 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_p(t_point *point, int x, int y, int z)
{
	point->x += x;
	point->y += y;
	point->z += z;
}

double	vector_magnitude(t_vector v)
{
	return (sqrt((v.x * v.z) + (v.y * v.y) + (v.z * v.z)));
}

void	scale_hat(t_obj *obj)
{
	scale_vec(&(obj->l.hat.i), (obj->l.hat.scale * obj->z_key) + 1);
	scale_vec(&(obj->l.hat.j), (obj->l.hat.scale * obj->z_key) + 1);
	scale_vec(&(obj->l.hat.k), obj->l.hat.scale + 1);
}

void	to_view(t_obj *obj, double z, double x, double y)
{
	obj->l.hat.rot.x = -(obj->l.trans.rot.x - x);
	obj->l.hat.rot.y = -(obj->l.trans.rot.y - y);
	obj->l.hat.rot.z = -(obj->l.trans.rot.z - z);
}
