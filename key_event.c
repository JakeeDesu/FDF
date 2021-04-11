/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:12:09 by hmhindat          #+#    #+#             */
/*   Updated: 2019/03/06 13:10:53 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_scaling(int key, t_obj *param)
{
	if (key == 69 && param->l.trans.scale + 0.1 < 1.3)
		param->l.hat.scale = 0.1;
	else if (key == 78 && param->l.trans.scale - 0.1 > -2)
		param->l.hat.scale = -0.1;
	else if (key == 6)
	{
		if (param->z_key)
			param->z_key = 0;
		else
			param->z_key = 1;
	}
}

void	coloring(int key, t_obj *param)
{
	if (key == 8)
	{
		if (param->c_z)
		{
			init_list_color(param);
			param->c_z = 0;
		}
		else
			param->c_z = 1;
	}
	else if (key == 3)
	{
		if (param->fill)
			param->fill = 0;
		else
			param->fill = 1;
	}
}

void	key_movement_and_rotation(int key, t_obj *param)
{
	if (key == 123)
		param->l.hat.rot.y = -(5 * M_PI) / 180;
	else if (key == 124)
		param->l.hat.rot.y = (5 * M_PI) / 180;
	else if (key == 125)
		param->l.hat.rot.x = -(5 * M_PI) / 180;
	else if (key == 126)
		param->l.hat.rot.x = (5 * M_PI) / 180;
	else if (key == 83)
		param->l.hat.rot.z = (2 * M_PI) / 180;
	else if (key == 82)
		param->l.hat.rot.z = -(2 * M_PI) / 180;
	else if (key == 0 && param->l.trans.position.x > param->s_min.x + 12)
		param->l.hat.posi.x = -10;
	else if (key == 1 && param->l.trans.position.y < param->s_max.y - 12)
		param->l.hat.posi.y = 10;
	else if (key == 2 && param->l.trans.position.x < param->s_max.x - 12)
		param->l.hat.posi.x = 10;
	else if (key == 13 && param->l.trans.position.y > param->s_min.y + 12)
		param->l.hat.posi.y = -10;
}

void	p_key(int key_code, t_obj *param)
{
	mlx_clear_window(param->x_p, param->x_w);
	key_scaling(key_code, param);
	key_movement_and_rotation(key_code, param);
	coloring(key_code, param);
	draw_obj(param);
	draw_pal_setup(*param);
}
