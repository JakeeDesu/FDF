/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:06:34 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/14 06:32:47 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_obj obj;

	load_lmap(&obj, argv[1]);
	obj.x_p = mlx_init();
	obj.x_w = mlx_new_window(obj.x_p, W_WIN_SIZE, H_WIN_SIZE, "V_2-1");
	init_obj(&obj);
	draw_obj(&obj);
	draw_pal_setup(obj);
	check_event(&obj);
	mlx_loop(obj.x_p);
	return (0);
}
