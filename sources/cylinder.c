/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:18:33 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector3		find_n_cylinder(t_ray r, double t, t_figure cylinder)
{
	double		m;
	t_vector3	n;
	t_vector3	p;

	m = vec_dot(r.dir, cylinder.v) * t
		+ vec_dot(vec_sub(r.pos, cylinder.pos), cylinder.v);
	p = vec_add(r.pos, vec_scale(r.dir, t));
	n = vec_norm(vec_sub(vec_sub(p, cylinder.pos), vec_scale(cylinder.v, m)));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double			find_t_cylinder(t_rt *rt, t_ray *r, t_figure cylinder)
{
	double		a;
	double		b;
	double		c;
	double		d;

	rt->x = vec_sub(r->pos, cylinder.pos);
	a = vec_dot(r->dir, cylinder.v);
	a = vec_dot(r->dir, r->dir) - a * a;
	b = 2 * (vec_dot(r->dir, rt->x) - vec_dot(r->dir, cylinder.v)
		* vec_dot(rt->x, cylinder.v));
	c = vec_dot(rt->x, cylinder.v);
	c = vec_dot(rt->x, rt->x) - c * c - cylinder.radius * cylinder.radius;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d = d < 0.0003 ? -1 : choose_closest_t(a, b, d));
}

double			calc_cylinder(t_rt *rt, t_ray r, int id)
{
	double		t;
	t_figure	cylinder;

	cylinder = rt->figure[id];
	t = find_t_cylinder(rt, &r, cylinder);
	return (t);
}
