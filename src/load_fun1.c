/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 05:09:51 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/13 21:57:39 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_elem	*new_ex(t_elem **list, t_elem **up)
{
	t_elem *new;

	new = (t_elem*)malloc(sizeof(t_elem));
	new->left = NULL;
	new->down = NULL;
	if (*list == NULL)
		return (new);
	else
	{
		if (*up)
			(*up)->down = (*list);
		(*list)->left = new;
	}
	return (new);
}

void	add_e(t_elem *elem, t_elem *left, t_elem *up)
{
	elem = left;
	elem->down = NULL;
	up->down = elem;
}

void	cp_elem(t_elem **elem1, t_elem *elem2, int x, int y)
{
	*elem1 = (t_elem*)malloc(sizeof(t_elem));
	p_to_v(&((*elem1)->v), elem2->p);
	translate_vec(&((*elem1)->v), x, y, 0);
	c_to_c(&((*elem1)->p.color), elem2->p.color);
	(*elem1)->p.c = elem2->p.c;
	(*elem1)->left = NULL;
	(*elem1)->down = NULL;
}
