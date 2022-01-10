/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 08:57:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/16 22:24:28 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_obj *obj, t_point a, int c)
{
	if (a.y < obj->s_max.y && a.y > obj->s_min.y &&
			a.x < obj->s_max.x && a.x > obj->s_min.x)
		mlx_pixel_put(obj->x_p, obj->x_w, a.x, a.y, c);
}

void	d_l(t_obj *o, t_point a, t_point b, t_color cl)
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
			put_pixel(o, a, c_g(&str, a, b));
			if (((m * a.x++) + c) - 0.5 > a.y)
				a.y++;
		}
	else
		while (a.y < b.y)
		{
			put_pixel(o, a, c_g(&str, a, b));
			if (((a.y++ - c) / m) + 0.5 > a.x)
				a.x++;
		}
}

void	d_minus(t_obj *o, t_point a, t_point b, t_color cl)
{
	t_vector	m_c;
	t_point		sign;
	t_point		str;

	cp_point(&str, a);
	sign.x = (b.x - a.x) > 0 ? 1 : -1;
	sign.y = (b.y - a.y) > 0 ? 1 : -1;
	m_c.x = (float)(b.y - a.y) / (float)(b.x - a.x);
	m_c.y = (a.y - (m_c.x * a.x));
	if (((b.x - a.x) * sign.x) > ((b.y - a.y) * sign.y))
		while (a.x < b.x)
		{
			put_pixel(o, a, c_g(&str, a, b));
			if (((m_c.x * a.x++) + m_c.y) - 0.5 < a.y)
				a.y--;
		}
	else
		while (a.y > b.y)
		{
			put_pixel(o, a, c_g(&str, a, b));
			if (((a.y-- - m_c.y) / m_c.x) + 0.5 > (float)a.x)
				a.x++;
		}
}

void	straight_l(t_obj *o, t_point a, t_point b, t_color cl)
{
	t_point str;

	cp_point(&str, a);
	if ((a.x - b.x) == 0)
	{
		if (a.y > b.y)
			while (a.y-- > b.y)
				put_pixel(o, a, c_g(&str, a, b));
		else
			while (a.y++ < b.y)
				put_pixel(o, a, c_g(&str, a, b));
	}
	else
	{
		if (a.x > b.x)
			while (a.x-- > b.x)
				put_pixel(o, a, c_g(&str, a, b));
		else
			while (a.x++ < b.x)
				put_pixel(o, a, c_g(&str, a, b));
	}
}
