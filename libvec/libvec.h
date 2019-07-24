/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:21 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/24 11:09:32 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

# define DTR(k) ((double)k * (M_PI / 180))

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

t_vector3			vec_new(double x, double y, double z);
t_vector3			vec_scale(t_vector3 v, double nb);
t_vector3			vec_add(t_vector3 v1, t_vector3 v2);
t_vector3			vec_sub(t_vector3 a, t_vector3 b);
double				vec_magn(t_vector3 v);
t_vector3			vec_norm(t_vector3 v);
t_vector3			vec_cpy(t_vector3 v);
t_vector3			vec_minus(t_vector3 a, t_vector3 b);
t_vector3			vec_mult(t_vector3 vec, double i);

double				vec_dot(t_vector3 a, t_vector3 b);
t_vector3			vec_cross(t_vector3 a, t_vector3 b);

t_vector3			vec_rot_x(t_vector3 v, double a);
t_vector3			vec_rot_y(t_vector3 v, double a);
t_vector3			vec_rot_z(t_vector3 v, double a);
t_vector3			vec_rot_xyz(t_vector3 v, t_vector3 r);
t_vector3			vec_rot_zyx(t_vector3 v, t_vector3 r);
void				vec_rewrite(t_vector3 *first, t_vector3 second);

#endif
