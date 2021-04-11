/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:13:00 by hmhindat          #+#    #+#             */
/*   Updated: 2021/04/11 19:06:49 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define W_WIN_SIZE 3000
# define H_WIN_SIZE 1500

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
}				t_color;

typedef struct	s_rot
{
	double			x;
	double			y;
	double			z;
}				t_rot;

typedef struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				c;
	t_color			color;
}				t_point;

typedef struct	s_hat
{
	t_vector		i;
	t_vector		j;
	t_vector		k;
	t_color			ic;
	t_color			jc;
	t_color			kc;
	int				color_unit;
	double			scale;
	t_rot			rot;
	t_point			posi;

}				t_hat;

typedef struct	s_area
{
	t_point			posi;
	int				unit;
	t_point			sel_max;
	t_point			sel_min;
	int				color;
	int				visible;
	int				selected;
}				t_area;

typedef struct	s_trans
{
	int				dx;
	int				dy;
	int				dz;
	t_rot			rot;
	t_point			center;
	t_point			position;
	double			scale;
	t_point			sel_max;
	t_point			sel_min;
	t_area			area_selected;
}				t_trans;

typedef struct	s_elem
{
	t_vector		v;
	t_point			p;
	struct s_elem	*down;
	struct s_elem	*left;
}				t_elem;

typedef struct	s_map
{
	t_elem			*list;
	t_elem			*list2;
	int				x;
	int				y;
	int				z;
	t_hat			hat;
	t_trans			trans;
	t_point			center;
}				t_map;

typedef enum	e_type
{
	obj, palet, surface
}				t_type;

typedef enum	e_event
{
	non = 0, key_re = 3, key_pr = 2, mouse_re = 5, mouse_pr = 4, mouse_mv = 6
}				t_event;

typedef struct	s_palet
{
	t_point			**map;
	t_point			size;
	t_point			position;
	t_point			sel_max;
	t_point			sel_min;
	t_area			area1;
	t_area			area2;
	t_area			reset;
	int				selected;
}				t_palet;

typedef struct	s_obj
{
	void			*x_p;
	void			*x_w;
	void			*x_m;
	t_point			s_max;
	t_point			s_min;
	t_point			s_center;
	int				z_key;
	int				max_z;
	t_map			l;
	t_palet			pal;
	int				c_z;
	int				fill;
	int				cursor_s;
	int				selected;
	int				visible;
	t_event			x_ev[5];

}				t_obj;
void			load_lmap(t_obj *obj, char *file);
void			cp_l(t_map *l, t_elem *list, t_elem **list2);
t_elem			*new_ex(t_elem **list, t_elem **up);
void			add_e(t_elem *elem, t_elem *left, t_elem *up);
void			cp_elem(t_elem **elem1, t_elem *elem2, int x, int y);
int				take_hexa(char c);
int				cnt_spaces(char *line, char c);
void			take_color(char *line, int *j, t_point *p);
void			init_obj(t_obj *obj);
void			init_hat(t_obj *obj);
void			draw_obj(t_obj *obj);
int				draw_line(t_obj *obj, t_point a, t_point b);
int				draw_line2(t_obj *obj, t_point a, t_point b);
void			d_l2(t_obj *o, t_point a, t_point b, t_color cl);
void			d_minus2(t_obj *o, t_point a, t_point b, t_color cl);
void			straight_l2(t_obj *o, t_point a, t_point b, t_color cl);
void			d_l(t_obj *o, t_point a, t_point b, t_color cl);
void			d_minus(t_obj *o, t_point a, t_point b, t_color cl);
void			straight_l(t_obj *o, t_point a, t_point b, t_color cl);
t_color			color_m(int r, int g, int b);
int				eq_c(t_color a, t_color b);
double			total_dis(t_point *start, t_point a, t_point b);
double			curr_dis(t_point *start, t_point a, t_point b);
int				c_g(t_point *start, t_point a, t_point b);
void			do_trans(t_obj *obj);
void			update(t_obj *obj);
void			translate_vec(t_vector *v, int x, int y, int z);
void			scale_vec(t_vector *v, double s);
void			rotz_vec(t_vector *v, t_map *l);
void			rotx_vec(t_vector *v, t_map *l);
void			roty_vec(t_vector *v, t_map *l);
void			scale_hat(t_obj *obj);
void			translate_p(t_point *point, int x, int y, int z);
void			to_view(t_obj *obj, double z, double x, double y);
void			init_list2(t_obj *obj);
void			p_to_v(t_vector *v, t_point p);
void			c_to_c(t_color *c1, t_color c2);
void			point(t_point *p, int x, int y, int z);
void			vector(t_vector *v, double x, double y, double z);
void			gen_c(t_point *p);
void			rot(t_rot *rot, double z, double x, double y);
void			to_color(t_point *p, int c);
int				color(int r, int g, int b);
void			init_x_ev(t_obj *obj, int k_p, int m_p, int m_r);
void			edit_colo(t_point *a, int r, int g, int b);
void			cp_point(t_point *p2, t_point p1);
void			reset(t_obj *obj);
void			make_pal(t_obj *obj, int size, t_point position);
void			p_alloc(t_obj *obj, int i, int j);
void			fill_r_up(t_palet *palet, t_color *c, int *j, t_point *par);
void			fill_g_up(t_palet *palet, t_color *c, int *j, t_point *par);
void			fill_b_up(t_palet *palet, t_color *c, int *j, t_point *par);
void			fill_r_down(t_palet *palet, t_color *c, int *j, t_point *par);
void			fill_g_down(t_palet *palet, t_color *c, int *j, t_point *par);
void			fill_b_down(t_palet *palet, t_color *c, int *j, t_point *par);
void			init_area(t_area *area, t_point posi, int unit, int c);
void			draw_pal_setup(t_obj obj);
int				selected_obj(t_obj *obj, int x, int y);
int				obj_select(t_obj *obj, t_point p, t_point max, t_point min);
int				palet_select(t_obj *obj, t_point p, t_point max, t_point min);
int				area1_select(t_obj *obj, t_point p, t_point max, t_point min);
int				area2_select(t_obj *obj, t_point p, t_point max, t_point min);
int				reset_select(t_obj *obj, t_point p, t_point max, t_point min);
void			check_event(t_obj *obj);
int				key_press(int key_code, t_obj *param);
int				key_release(int key_code, t_obj *param);
int				mouse_move(int x, int y, t_obj *param);
int				mouse_release(int button, int x, int y, t_obj *param);
int				mouse_press(int button, int x, int y, t_obj *param);
void			p_key(int key_code, t_obj *param);
void			button_1(t_obj *param, int x, int y);
void			button_4(t_obj *param, int x, int y);
void			button_5(t_obj *param, int x, int y);
double			vector_magnitude(t_vector v);
void			c_grade(t_obj obj, t_elem *elem);
void			init_list_color(t_obj *obj);
void			coloring(int key, t_obj *param);
void			fill_area(t_obj *obj, t_elem *p);

#endif
