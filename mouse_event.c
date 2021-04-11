/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:22:42 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:11:24 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	button_1(t_obj *param, int x, int y)
{
	if (selected_obj(param, x, y))
	{
		mlx_clear_window(param->x_p, param->x_w);
		draw_pal_setup(*param);
		draw_obj(param);
	}
}

void	button_4(t_obj *param, int x, int y)
{
	mlx_clear_window(param->x_p, param->x_w);
	if (param->selected && !(param->pal.area1.selected))
	{
		if (param->l.trans.scale + 0.1 < 1.3)
			param->l.hat.scale = 0.1;
	}
	else if (param->pal.area1.selected && param->cursor_s < 100)
		param->cursor_s += 10;
	param->l.trans.area_selected.selected = 0;
	draw_pal_setup(*param);
	draw_obj(param);
}

void	button_5(t_obj *param, int x, int y)
{
	mlx_clear_window(param->x_p, param->x_w);
	if (param->selected && !(param->pal.area1.selected))
	{
		if (param->l.trans.scale - 0.1 > -2)
			param->l.hat.scale -= 0.1;
	}
	else if (param->pal.area1.selected && param->cursor_s - 10 > 5)
		param->cursor_s -= 10;
	draw_pal_setup(*param);
	draw_obj(param);
}
