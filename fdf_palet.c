/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 02:41:33 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 10:03:08 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	p_fill_l(t_palet *palet, int size, int h)
{
	int		j;
	int		i;
	t_point	params;
	t_color	c;

	j = 0;
	i = (6 * 255) / size;
	point(&(params), i, h, size);
	edit_colo(&params, 255, 0, 0);
	fill_b_up(palet, &c, &j, &params);
	params.color.b = 255;
	fill_r_down(palet, &c, &j, &params);
	params.color.r = 0;
	fill_g_up(palet, &c, &j, &params);
	params.color.g = 255;
	fill_b_down(palet, &c, &j, &params);
	params.color.b = 0;
	fill_r_up(palet, &c, &j, &params);
	params.color.r = 255;
	fill_g_down(palet, &c, &j, &params);
	params.color.g = 0;
}

int		make_pal_size(double how_much_screen)
{
	double unit;

	unit = (H_WIN_SIZE > W_WIN_SIZE) ? W_WIN_SIZE : H_WIN_SIZE;
	unit = ((unit * how_much_screen)) / 255;
	unit = ((unit + 5.0) > 1) ? unit + 0.5 : 1;
	return (((int)unit) * 255);
}

void	make_pal(t_obj *obj, int size, t_point position)
{
	t_point	p;
	int		i;

	i = 0;
	size = make_pal_size(0.25);
	p_alloc(obj, size, size);
	point(&(obj->pal.position), position.x, position.y, position.z);
	while (i < size)
		p_fill_l(&(obj->pal), size, i++);
	point(&p, (W_WIN_SIZE - size) / 64, size + ((H_WIN_SIZE - size) / 16), 0);
	init_area(&(obj->pal.area1), p, size / 4, color(255, 255, 255));
	cp_point(&p, obj->pal.area1.posi);
	p.y += (size / 4) + ((H_WIN_SIZE - size) / 64);
	init_area(&(obj->pal.area2), p, size / 4, color(255, 255, 255));
	cp_point(&p, obj->pal.area1.posi);
	p.y = H_WIN_SIZE - obj->pal.area1.posi.x - (size / 2);
	init_area(&(obj->pal.reset), p, size / 2, color(80, 151, 178));
	cp_point(&(obj->pal.sel_max), obj->pal.position);
	translate_p(&(obj->pal.sel_max), size, size, 0);
	cp_point(&(obj->pal.sel_min), obj->pal.position);
	obj->pal.selected = 0;
}
