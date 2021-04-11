/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:30:13 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:12:49 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		selected_obj(t_obj *obj, int x, int y)
{
	t_point posi;

	point(&posi, x, y, 0);
	if (obj_select(obj, posi, obj->s_max, obj->s_min))
		return (1);
	if (palet_select(obj, posi, obj->pal.sel_max, obj->pal.sel_min))
		return (1);
	if (area1_select(obj, posi, obj->pal.area1.sel_max, obj->pal.area1.sel_min))
		return (1);
	if (area2_select(obj, posi, obj->pal.area2.sel_max, obj->pal.area2.sel_min))
		return (1);
	if (reset_select(obj, posi, obj->pal.reset.sel_max, obj->pal.reset.sel_min))
		return (1);
	else if (obj->selected)
	{
		if (obj->selected)
			obj->l.hat.scale = -0.05;
		obj->selected = 0;
		obj->fill = 0;
		obj->pal.selected = 0;
		obj->pal.area2.selected = 0;
		obj->pal.area1.selected = 0;
		return (1);
	}
	return (0);
}
