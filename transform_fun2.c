/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:12 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 10:07:27 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_list2(t_obj *obj)
{
	t_elem	*p1;
	t_elem	*p2;

	p2 = obj->l.list2;
	p1 = obj->l.list;
	while (p1->left)
	{
		c_to_c(&(p2->p.color), p1->p.color);
		p2->p.c = color(p1->p.color.r, p1->p.color.g, p1->p.color.b);
		p1 = p1->left;
		p2 = p2->left;
	}
}
