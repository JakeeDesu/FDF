/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:05:47 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 09:53:29 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cursor(t_obj *obj)
{
	t_point posi;

	if (obj->l.trans.area_selected.selected)
	{
		cp_point(&posi, obj->l.trans.area_selected.posi);
		obj->l.trans.area_selected.sel_max.x = posi.x + obj->cursor_s;
		obj->l.trans.area_selected.sel_max.y = posi.y + obj->cursor_s;
		obj->l.trans.area_selected.sel_min.x = posi.x - obj->cursor_s;
		obj->l.trans.area_selected.sel_min.y = posi.y - obj->cursor_s;
	}
}

void	update_trans_and_hat(t_obj *obj)
{
	t_point posi;

	cp_point(&posi, obj->l.hat.posi);
	translate_p(&(obj->l.trans.position), posi.x, posi.y, 0);
	obj->l.trans.scale += (obj->l.hat.scale * obj->z_key);
	obj->l.trans.rot.x += obj->l.hat.rot.x;
	obj->l.trans.rot.y += obj->l.hat.rot.y;
	obj->l.trans.rot.z += obj->l.hat.rot.z;
	obj->l.hat.scale = 0;
	point(&(obj->l.hat.posi), 0, 0, 0);
	rot(&(obj->l.hat.rot), 0, 0, 0);
}

void	update(t_obj *obj)
{
	cursor(obj);
	update_trans_and_hat(obj);
}
