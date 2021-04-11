/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:06:39 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:06:44 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_center(t_obj *obj)
{
	t_point o;

	point(&o, obj->s_max.x - 1, obj->l.trans.position.y, 0);
	edit_colo(&o, 0, 0, 0);
	edit_colo(&(obj->l.trans.position), 190, 90, 90);
	draw_line(obj, obj->l.trans.position, o);
	point(&o, obj->s_min.x + 1, obj->l.trans.position.y, 0);
	draw_line(obj, obj->l.trans.position, o);
	point(&o, obj->l.trans.position.x, obj->s_min.y + 1, 0);
	edit_colo(&o, 0, 0, 0);
	edit_colo(&(obj->l.trans.position), 90, 90, 190);
	draw_line(obj, obj->l.trans.position, o);
	point(&o, obj->l.trans.position.x, obj->s_max.y - 1, 0);
	draw_line(obj, obj->l.trans.position, o);
}

void	draw_border(t_obj *obj, t_point min, t_point max, t_color color)
{
	t_point n;
	t_point m;

	edit_colo(&m, color.r, color.g, color.b);
	edit_colo(&n, color.r, color.g, color.b);
	point(&m, min.x, min.y, 0);
	point(&n, max.x, min.y, 0);
	draw_line2(obj, m, n);
	point(&n, min.x, max.y, 0);
	draw_line2(obj, m, n);
	point(&m, max.x, max.y, 0);
	draw_line2(obj, n, m);
	point(&n, max.x, min.y, 0);
	draw_line2(obj, m, n);
}

void	draw_selection(t_obj *obj, int d, t_point max, t_point min)
{
	if (d)
		draw_border(obj, min, max, min.color);
	else
		draw_border(obj, min, max, max.color);
}

void	selection(t_obj *obj)
{
	t_point b_min;
	t_point b_max;

	point(&(b_min), obj->s_max.x + 5, obj->s_min.y + 100, 0);
	b_max.x = obj->s_max.x + 5 + obj->cursor_s;
	b_max.y = obj->s_min.y + 100 + obj->cursor_s;
	edit_colo(&b_min, 0, 0, 0);
	to_color(&b_max, obj->pal.area1.color);
	draw_selection(obj, obj->pal.area1.selected, b_min, b_max);
	draw_selection(obj, obj->selected, obj->s_min, obj->s_max);
	point(&(b_min), obj->pal.area1.sel_min.x, obj->pal.area1.sel_min.y, 0);
	point(&(b_max), obj->pal.area1.sel_max.x, obj->pal.area1.sel_max.y, 0);
	edit_colo(&b_max, 255, 0, 0);
	edit_colo(&b_min, 100, 0, 0);
	draw_selection(obj, obj->pal.area1.selected, b_min, b_max);
	point(&(b_min), obj->pal.area2.sel_min.x, obj->pal.area2.sel_min.y, 0);
	point(&(b_max), obj->pal.area2.sel_max.x, obj->pal.area2.sel_max.y, 0);
	draw_selection(obj, obj->pal.area2.selected, b_min, b_max);
}

void	draw_obj(t_obj *obj)
{
	t_elem	*elem2;

	elem2 = obj->l.list2;
	do_trans(obj);
	if (obj->selected)
		show_center(obj);
	if (!obj->fill)
		while (elem2->left)
		{
			if (elem2->left && elem2->v.y == elem2->left->v.y)
				draw_line(obj, elem2->p, elem2->left->p);
			if (elem2->down && elem2->v.x == elem2->down->v.x)
				draw_line(obj, elem2->p, elem2->down->p);
			elem2 = elem2->left;
		}
	else
		while (elem2->left)
		{
			if (elem2->v.y == elem2->left->v.y)
				fill_area(obj, elem2);
			elem2 = elem2->left;
		}
	selection(obj);
}
