/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:51:37 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector3		find_n_plane(t_ray r, t_figure plane)
{
	if (vec_dot(r.dir, plane.v) < 0)
		return (plane.v);
	return (vec_scale(plane.v, -1));
}

double			find_t_plane(t_ray *r, t_figure plane)
{
	double		t;
	double		a;
	double		b;

	a = vec_dot(vec_sub(r->pos, plane.pos), plane.v);
	b = vec_dot(r->dir, plane.v);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	return (t > 0.0003 ? t : -1);
}

double			calc_plane(t_rt *rt, t_ray r, int id)
{
	double		t;
	t_figure	plane;

	plane = rt->figure[id];
	t = find_t_plane(&r, plane);
	return (t);
}
