/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:49:47 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 05:00:51 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_b_up(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double	alpha;

	while (par->color.b + par->x < (255))
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
		par->color.b += par->x;
		(*j)++;
	}
}

void	fill_g_up(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double	alpha;

	alpha = (double)par->y / par->z;
	while (par->color.g + par->x < (255))
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
		par->color.g += par->x;
		(*j)++;
	}
}

void	fill_r_up(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double alpha;

	alpha = (double)par->y / par->z;
	while (par->color.r + par->x < (255))
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
		par->color.r += par->x;
		(*j)++;
	}
}

void	fill_g_down(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double alpha;

	alpha = (double)par->y / par->z;
	while (par->color.g - par->x >= 0)
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
		par->color.g -= par->x;
		(*j)++;
	}
}

void	fill_b_down(t_palet *palet, t_color *c, int *j, t_point *par)
{
	double alpha;

	alpha = (double)par->y / par->z;
	while (par->color.b - par->x >= 0)
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
		par->color.b -= par->x;
		(*j)++;
	}
}
