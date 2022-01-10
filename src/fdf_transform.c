/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 03:34:44 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/16 22:26:15 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_to_point(t_obj *obj, t_elem *e, t_hat h)
{
	e->p.x = ((e->v.x * h.i.x) + (e->v.y * h.j.x) + (e->v.z * h.k.x) + 0.5);
	e->p.y = ((e->v.x * h.i.y) + (e->v.y * h.j.y) + (e->v.z * h.k.y) + 0.5);
	e->p.z = ((e->v.x * h.i.z) + (e->v.y * h.j.z) + (e->v.z * h.k.z) + 0.5);
	translate_p(&(e->p), obj->l.trans.position.x, obj->l.trans.position.y, 0);
}

void	trans_obj(t_obj *obj)
{
	t_elem	*elem;
	t_point	s_max;
	t_point	s_min;

	obj->max_z = 0;
	elem = obj->l.list2;
	cp_point(&s_max, obj->l.trans.area_selected.sel_max);
	cp_point(&s_min, obj->l.trans.area_selected.sel_min);
	while (elem)
	{
		if (obj->selected && obj->pal.area2.selected)
			to_color(&(elem->p), obj->pal.area2.color);
		vec_to_point(obj, elem, obj->l.hat);
		if (obj->l.trans.area_selected.selected)
		{
			if (elem->p.x < s_max.x && elem->p.x > s_min.x)
			{
				if (elem->p.y < s_max.y && elem->p.y > s_min.y)
					to_color(&(elem->p), obj->l.trans.area_selected.color);
			}
		}
		if (obj->c_z)
			c_grade(*obj, elem);
		elem = elem->left;
	}
}

void	trans_hat(t_obj *obj)
{
	scale_hat(obj);
	if (obj->l.hat.rot.x)
	{
		rotx_vec(&(obj->l.hat.i), &(obj->l));
		rotx_vec(&(obj->l.hat.j), &(obj->l));
		rotx_vec(&(obj->l.hat.k), &(obj->l));
	}
	else if (obj->l.hat.rot.y)
	{
		roty_vec(&(obj->l.hat.i), &(obj->l));
		roty_vec(&(obj->l.hat.j), &(obj->l));
		roty_vec(&(obj->l.hat.k), &(obj->l));
	}
	else if (obj->l.hat.rot.z)
	{
		rotz_vec(&(obj->l.hat.i), &(obj->l));
		rotz_vec(&(obj->l.hat.j), &(obj->l));
		rotz_vec(&(obj->l.hat.k), &(obj->l));
	}
}

void	do_trans(t_obj *obj)
{
	trans_hat(obj);
	update(obj);
	trans_obj(obj);
}
