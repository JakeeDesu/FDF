/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:12 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 11:19:22 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cp_l(t_map *l, t_elem *list, t_elem **list2)
{
	t_elem	*p2;
	t_elem	*p2up;
	t_point	params;

	point(&params, 1, 0, 0);
	p2up = NULL;
	cp_elem(&(*list2), list, -(l->x / 2), -(l->y / 2));
	p2 = *list2;
	while (list->left)
	{
		if (params.x == l->x)
			p2up = *list2;
		params.y = (list->left->p.z > params.y) ? list->left->p.z : params.y;
		params.z = (list->left->p.z < params.z) ? list->left->p.z : params.z;
		cp_elem(&(p2->left), list->left, -(l->x / 2), -(l->y / 2));
		if (p2up && p2up->v.x == p2->v.x)
		{
			p2up->down = p2;
			p2up = p2up->left;
		}
		list = list->left;
		p2 = p2->left;
		params.x++;
	}
	l->z = (params.y - params.z) / 2;
}

void	load_lpoint(t_elem **elem, t_elem **up, int y, char *line)
{
	t_point s_x_idx;

	point(&s_x_idx, 1, 0, 0);
	while (line[s_x_idx.z])
	{
		point(&(*elem)->p, s_x_idx.y, y, 0);
		if (line[s_x_idx.z] == '-' && (s_x_idx.x = -1))
			s_x_idx.z++;
		while (line[s_x_idx.z] <= '9' && line[s_x_idx.z] >= '0')
			(*elem)->p.z = (*elem)->p.z * 10 + (line[s_x_idx.z++] - '0');
		(*elem)->p.z *= s_x_idx.x;
		if (line[s_x_idx.z] == ',')
			take_color(line, &(s_x_idx.z), &((*elem)->p));
		else
		{
			(*elem)->p.c = color(255, 255, 255);
			to_color(&((*elem)->p), (*elem)->p.c);
		}
		while (line[s_x_idx.z] == ' ')
			s_x_idx.z++;
		*elem = new_ex(elem, up);
		if (*up != NULL)
			(*up) = (*up)->left;
		s_x_idx.y++;
	}
}

void	make_lmap(int fd, t_obj *obj)
{
	int		y;
	char	*line;
	t_elem	*elem;
	t_elem	*up;

	up = NULL;
	get_next_line(fd, &line);
	obj->l.x = cnt_spaces(line, ' ');
	obj->l.y = 0;
	obj->l.list = NULL;
	obj->l.list = new_ex(&(obj->l.list), &up);
	elem = obj->l.list;
	while (*line == ' ')
		line++;
	load_lpoint(&elem, &up, obj->l.y, line);
	obj->l.y++;
	up = obj->l.list;
	while (get_next_line(fd, &line) > 0)
	{
		while (*line == ' ')
			line++;
		load_lpoint(&elem, &up, obj->l.y, line);
		obj->l.y++;
	}
}

void	load_lmap(t_obj *obj, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	make_lmap(fd, obj);
	cp_l(&(obj->l), obj->l.list, &(obj->l.list2));
	obj->selected = 0;
}
