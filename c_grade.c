/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_grade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:05:54 by iberchid          #+#    #+#             */
/*   Updated: 2019/02/16 22:18:25 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_grade(t_obj obj, t_elem *e)
{
	int		i;
	int		z;

	i = (e->v.z > 0) ? 1 : -1;
	z = (vector_magnitude(obj.l.hat.k) * (e->v.z * i)) + (obj.pal.size.x / 3);
	z %= (obj.pal.size.x);
	if (e->v.z)
		c_to_c(&(e->p.color), obj.pal.map[0][z].color);
	else
		c_to_c(&(e->p.color), obj.pal.map[0][obj.pal.size.x / 3].color);
}
