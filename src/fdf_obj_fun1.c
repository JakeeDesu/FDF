/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj_fun2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 01:52:50 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:14:23 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		obj_select(t_obj *obj, t_point p, t_point max, t_point min)
{
	if (p.x < max.x && p.y < max.y && p.x > min.x && p.y > min.y)
	{
		if (!(obj->selected))
		{
			obj->l.hat.scale = 0.05;
			obj->selected = 1;
			obj->pal.selected = 0;
		}
		else if (obj->pal.area1.selected)
		{
			obj->l.trans.area_selected.selected = 1;
			point(&(obj->l.trans.area_selected.posi), p.x, p.y, 0);
			obj->l.trans.area_selected.color = obj->pal.area1.color;
		}
		return (1);
	}
	return (0);
}

int		palet_select(t_obj *obj, t_point p, t_point max, t_point min)
{
	if (p.x < max.x && p.y < max.y && p.x > min.x && p.y > min.y)
	{
		if (obj->pal.area1.selected)
			obj->pal.area1.color = obj->pal.map[p.y][p.x].c;
		if (obj->pal.area2.selected)
			obj->pal.area2.color = obj->pal.map[p.y][p.x].c;
		if (obj->selected && !(obj->pal.area1.selected))
		{
			obj->l.hat.scale = -0.05;
			obj->selected = 0;
		}
		obj->fill = 0;
		obj->l.trans.area_selected.selected = 0;
		obj->pal.selected = 1;
		return (1);
	}
	return (0);
}

int		area1_select(t_obj *obj, t_point p, t_point max, t_point min)
{
	if (p.x < max.x && p.y < max.y && p.x > min.x && p.y > min.y)
	{
		obj->l.trans.area_selected.selected = 0;
		obj->pal.area1.selected = 1;
		obj->pal.area2.selected = 0;
		obj->pal.selected = 0;
		obj->fill = 0;
		return (1);
	}
	return (0);
}

int		area2_select(t_obj *obj, t_point p, t_point max, t_point min)
{
	if (p.x < max.x && p.y < max.y && p.x > min.x && p.y > min.y)
	{
		if (obj->selected)
			obj->l.hat.scale = -0.05;
		obj->selected = 0;
		obj->fill = 0;
		obj->pal.area2.selected = 1;
		obj->pal.area1.selected = 0;
		obj->l.trans.area_selected.selected = 0;
		obj->pal.selected = 0;
		return (1);
	}
	return (0);
}

int		reset_select(t_obj *obj, t_point p, t_point max, t_point min)
{
	if (p.x < max.x && p.y < max.y && p.x > min.x && p.y > min.y)
	{
		obj->fill = 0;
		reset(obj);
		return (1);
	}
	return (0);
}
