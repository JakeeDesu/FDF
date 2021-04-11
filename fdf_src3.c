/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 02:58:35 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/16 21:08:14 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cp_point(t_point *p2, t_point p1)
{
	point(p2, p1.x, p1.y, p1.z);
	p2->c = p1.c;
	edit_colo(p2, p1.color.r, p1.color.g, p1.color.b);
}

void	iso_view(t_obj *obj)
{
	obj->l.hat.rot.z = (-45 * M_PI) / 180;
	obj->l.hat.rot.x = (54.736 * M_PI) / 180;
	obj->l.hat.rot.y = (0 * M_PI) / 180;
	rotz_vec(&(obj->l.hat.i), &(obj->l));
	rotz_vec(&(obj->l.hat.j), &(obj->l));
	rotz_vec(&(obj->l.hat.k), &(obj->l));
	rotx_vec(&(obj->l.hat.i), &(obj->l));
	rotx_vec(&(obj->l.hat.j), &(obj->l));
	rotx_vec(&(obj->l.hat.k), &(obj->l));
}

void	init_list_color(t_obj *obj)
{
	t_elem	*elem;
	t_elem	*elem2;

	elem2 = obj->l.list2;
	elem = obj->l.list;
	while (elem)
	{
		elem2->p.color.r = elem->p.color.r;
		elem2->p.color.g = elem->p.color.g;
		elem2->p.color.b = elem->p.color.b;
		elem2->p.c = elem->p.c;
		elem = elem->left;
		elem2 = elem2->left;
	}
}

void	reset(t_obj *obj)
{
	init_list2(obj);
	init_hat(obj);
	iso_view(obj);
	obj->l.hat.rot.z = 0;
	obj->l.hat.rot.x = 0;
	obj->pal.area1.selected = 0;
	obj->pal.area2.selected = 0;
	obj->selected = 0;
	obj->pal.selected = 0;
	obj->l.trans.area_selected.selected = 0;
}
