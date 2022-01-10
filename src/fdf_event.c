/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:23:07 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:07:16 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_event(t_obj *obj)
{
	if (obj->x_ev[0] == key_pr)
		mlx_hook(obj->x_w, key_pr, 0, key_press, obj);
	if (obj->x_ev[1] == key_re)
		mlx_hook(obj->x_w, key_re, 0, key_release, obj);
	if (obj->x_ev[2] == mouse_pr)
		mlx_hook(obj->x_w, mouse_pr, 0, mouse_press, obj);
	if (obj->x_ev[3] == mouse_re)
		mlx_hook(obj->x_w, mouse_re, 0, mouse_release, obj);
	if (obj->x_ev[4] == mouse_mv)
		mlx_hook(obj->x_w, mouse_mv, 0, mouse_move, obj);
}
