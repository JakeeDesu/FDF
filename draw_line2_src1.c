/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 08:57:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 09:49:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	d_l2(t_obj *o, t_point a, t_point b, t_color cl)
{
	float	m;
	float	c;
	t_point	str;

	cp_point(&str, a);
	m = (float)(b.y - a.y) / (float)(b.x - a.x);
	c = (a.y - (m * a.x));
	if ((b.x - a.x) > (b.y - a.y))
		while (a.x < b.x)
		{
			mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
			if (((m * a.x++) + c) - 0.5 > a.y)
				a.y++;
		}
	else
		while (a.y < b.y)
		{
			mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
			if (((a.y++ - c) / m) + 0.5 > a.x)
				a.x++;
		}
}

void	d_minus2(t_obj *o, t_point a, t_point b, t_color cl)
{
	float	m;
	float	c;
	t_point sign;
	t_point str;

	cp_point(&str, a);
	sign.x = (b.x - a.x) > 0 ? 1 : -1;
	sign.y = (b.y - a.y) > 0 ? 1 : -1;
	m = (float)(b.y - a.y) / (float)(b.x - a.x);
	c = (a.y - (m * a.x));
	if (((b.x - a.x) * sign.x) > ((b.y - a.y) * sign.y))
		while (a.x < b.x)
		{
			mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
			if (((m * a.x++) + c) - 0.5 < a.y)
				a.y--;
		}
	else
		while (a.y > b.y)
		{
			mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
			if (((a.y-- - c) / m) + 0.5 > (float)a.x)
				a.x++;
		}
}

void	straight_l2(t_obj *o, t_point a, t_point b, t_color cl)
{
	t_point str;

	cp_point(&str, a);
	if ((a.x - b.x) == 0)
	{
		if (a.y > b.y)
			while (a.y-- > b.y)
				mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
		else
			while (a.y++ < b.y)
				mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
	}
	else
	{
		if (a.x > b.x)
			while (a.x-- > b.x)
				mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
		else
			while (a.x++ < b.x)
				mlx_pixel_put(o->x_p, o->x_w, a.x, a.y, c_g(&str, a, b));
	}
}
