/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet_fun2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 23:41:10 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 05:06:18 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	p_alloc(t_obj *obj, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	point(&(obj->pal.size), j, i, 0);
	obj->pal.map = (t_point**)malloc(sizeof(t_point*) * i);
	while (a < i)
	{
		obj->pal.map[a] = (t_point*)malloc(sizeof(t_point) * j);
		b = 0;
		while (b < j)
		{
			point(&(obj->pal.map[a][b]), b, a, 0);
			b++;
		}
		a++;
	}
}

void	fill_r_down(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double alpha;

	alpha = (double)par->y / par->z;
	while (par->color.r - par->x >= 0)
	{
		c->r = -((alpha) * (255 - par->color.r));
		c->g = -((alpha) * (255 - par->color.g));
		c->b = -((alpha) * (255 - par->color.b));
		palet->map[par->y][*j].color.r = par->color.r - c->r;
		palet->map[par->y][*j].color.g = par->color.g - c->g;
		palet->map[par->y][*j].color.b = par->color.b - c->b;
		gen_c(&(palet->map[par->y][*j]));
		palet->map[par->y][*j].x += palet->position.x;
		palet->map[par->y][*j].y += palet->position.y;
		par->color.r -= par->x;
		(*j)++;
	}
}

void	init_area(t_area *area, t_point posi, int unit, int c)
{
	point(&(area->posi), posi.x, posi.y, posi.z);
	area->unit = unit;
	area->sel_max.x = area->posi.x + unit;
	area->sel_max.y = area->posi.y + unit;
	area->sel_min.x = area->posi.x;
	area->sel_min.y = area->posi.y;
	area->color = c;
	area->visible = 1;
	area->selected = 0;
}

void	draw_area(void *x_p, void *x_w, t_area area)
{
	int i;
	int j;

	if (area.visible)
	{
		i = area.posi.y;
		while (i < area.posi.y + area.unit)
		{
			j = area.posi.x;
			while (j < area.posi.x + area.unit)
			{
				mlx_pixel_put(x_p, x_w, j, i, area.color);
				j++;
			}
			i++;
		}
	}
}

void	draw_pal_setup(t_obj obj)
{
	int		i;
	int		j;
	t_point	**p;

	p = obj.pal.map;
	i = 0;
	while (i < obj.pal.size.y)
	{
		j = 0;
		while (j < obj.pal.size.x)
		{
			mlx_pixel_put(obj.x_p, obj.x_w, p[i][j].x, p[i][j].y, p[i][j].c);
			j++;
		}
		i++;
	}
	draw_area(obj.x_p, obj.x_w, obj.pal.area1);
	draw_area(obj.x_p, obj.x_w, obj.pal.area2);
	draw_area(obj.x_p, obj.x_w, obj.pal.reset);
}
