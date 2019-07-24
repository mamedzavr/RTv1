/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:18:29 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector3	find_n_cone(t_ray r, t_vector3 pt, double t, t_figure cone)
{
	t_vector3	n;
	double		m;

	m = vec_dot(r.dir, cone.v) * t
		+ vec_dot(vec_sub(r.pos, cone.pos), cone.v);
	n = vec_scale(vec_scale(cone.v, m), (1 + cone.radius * cone.radius));
	n = vec_norm(vec_sub(vec_sub(pt, cone.pos), n));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double		find_t_cone(t_rt *rt, t_ray *r, t_figure cone)
{
	double		a;
	double		b;
	double		c;
	double		d;

	rt->x = vec_sub(r->pos, cone.pos);
	a = vec_dot(r->dir, cone.v);
	a = vec_dot(r->dir, r->dir) - (1 + cone.angle * cone.angle) * a * a;
	b = 2.0 * (vec_dot(r->dir, rt->x) - (1 + cone.angle * cone.angle)
		* vec_dot(r->dir, cone.v) * vec_dot(rt->x, cone.v));
	c = vec_dot(rt->x, cone.v);
	c = vec_dot(rt->x, rt->x) - (1 + cone.angle * cone.angle) * c * c;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d = d < 0.0003 ? -1 : choose_closest_t(a, b, d));
}

double		calc_cone(t_rt *rt, t_ray r, int id)
{
	double		t;
	t_figure	cone;

	cone = rt->figure[id];
	t = find_t_cone(rt, &r, cone);
	return (t);
}
