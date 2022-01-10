/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 06:50:54 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:05:27 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key_code, t_obj *param)
{
	if (key_code == 53)
		exit(0);
	if (key_code == 49)
	{
		mlx_clear_window(param->x_p, param->x_w);
		init_list2(param);
		init_hat(param);
		param->pal.area1.selected = 0;
		param->pal.area2.selected = 0;
		param->selected = 0;
		param->fill = 0;
		param->pal.selected = 0;
		param->l.trans.area_selected.selected = 0;
		draw_obj(param);
		draw_pal_setup(*param);
	}
	if (param->selected)
	{
		p_key(key_code, param);
	}
	return (0);
}

int		key_release(int key_code, t_obj *param)
{
	return (0);
}

int		mouse_move(int x, int y, t_obj *param)
{
	return (0);
}

int		mouse_release(int button, int x, int y, t_obj *param)
{
	return (0);
}

int		mouse_press(int button, int x, int y, t_obj *param)
{
	if (button == 1)
	{
		button_1(param, x, y);
	}
	else if (button == 4)
	{
		button_4(param, x, y);
	}
	else if (button == 5)
	{
		button_5(param, x, y);
	}
	return (0);
}
