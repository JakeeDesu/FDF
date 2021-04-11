/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj_fun1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:50:53 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 12:01:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_trans_unit(t_obj *obj)
{
	int uni;
	int unit;

	uni = (obj->l.x > obj->l.y) ? obj->l.x : obj->l.y;
	unit = (H_WIN_SIZE > W_WIN_SIZE) ? W_WIN_SIZE : H_WIN_SIZE;
	unit = (unit / 2) / uni;
	unit = (unit > 1) ? unit : 1;
	obj->l.trans.dx = unit;
	obj->l.trans.dy = unit;
	obj->l.trans.dz = unit;
}

void	init_trans(t_obj *obj)
{
	t_point center;
	t_point posi;

	rot(&(obj->l.trans.rot), 0, 0, 0);
	obj->l.trans.scale = 0;
	obj->selected = 0;
	obj->visible = 1;
	point(&posi, obj->l.trans.position.x, obj->l.trans.position.y, 0);
	point(&center, obj->l.trans.center.x, obj->l.trans.center.y, 0);
	point(&(obj->l.trans.sel_max), center.x + posi.x, center.y + posi.y, 0);
	point(&(obj->l.trans.sel_min), posi.x - center.x, posi.y - center.y, 0);
	edit_colo(&(obj->s_min), 150, 150, 150);
	edit_colo(&(obj->s_max), 180, 180, 200);
	point(&(obj->s_min), W_WIN_SIZE / 3, H_WIN_SIZE / 8, 0);
	point(&(obj->s_max), (W_WIN_SIZE / 8) * 7, (H_WIN_SIZE / 8) * 7, 0);
	obj->s_center.x = obj->s_min.x + ((obj->s_max.x - obj->s_min.x) / 2);
	obj->s_center.y = obj->s_min.y + ((obj->s_max.y - obj->s_min.y) / 2);
	obj->s_center.z = 0;
	obj->cursor_s = 5;
	obj->c_z = 0;
	obj->z_key = 1;
	cp_point(&(obj->l.trans.position), obj->s_center);
}

void	init_trans_center(t_obj *obj)
{
	obj->l.trans.center.x = ((obj->l.x - 1) * obj->l.trans.dx) / 2;
	obj->l.trans.center.y = ((obj->l.y - 1) * obj->l.trans.dy) / 2;
	obj->l.trans.center.z = ((obj->l.z - 1) * obj->l.trans.dz) / 2;
}

void	init_hat(t_obj *obj)
{
	vector(&(obj->l.hat.i), obj->l.trans.dx, 0, 0);
	c_to_c(&(obj->l.hat.ic), color_m(255, 255, 255));
	vector(&(obj->l.hat.j), 0, obj->l.trans.dy, 0);
	c_to_c(&(obj->l.hat.jc), color_m(255, 255, 255));
	vector(&(obj->l.hat.k), 0, 0, obj->l.trans.dz);
	c_to_c(&(obj->l.hat.kc), color_m(255, 255, 255));
	obj->l.hat.rot.x = 0;
	obj->l.hat.rot.y = 0;
	obj->l.hat.rot.z = 0;
	obj->l.hat.scale = 0;
	obj->l.hat.color_unit = 255 / obj->l.trans.dz;
	point(&(obj->l.hat.posi), 0, 0, 0);
}

void	init_obj(t_obj *obj)
{
	t_point posi;

	init_trans_unit(obj);
	init_hat(obj);
	init_trans(obj);
	obj->fill = 0;
	init_trans_center(obj);
	point(&posi, 0, 0, 0);
	make_pal(obj, 255, posi);
	init_x_ev(obj, key_pr, mouse_pr, non);
}
