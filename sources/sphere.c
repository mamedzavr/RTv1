/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:04:20 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector3		find_n_sphere(t_ray r, double d, t_vector3 cent)
{
	t_vector3	n;

	n = vec_add(r.pos, vec_scale(r.dir, d));
	n = vec_norm(vec_sub(n, cent));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double			find_t_sphere(t_ray *r, t_figure sphere)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = vec_dot(r->dir, r->dir);
	b = 2 * vec_dot(r->dir, vec_sub(r->pos, sphere.pos));
	c = vec_dot(vec_sub(r->pos, sphere.pos),
		vec_sub(r->pos, sphere.pos)) - sphere.radius * sphere.radius;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d < 0.0003 ? -1 : choose_closest_t(a, b, d));
}

double			calc_sphere(t_rt *rt, t_ray r, int id)
{
	double		t;
	t_figure	sphere;

	sphere = rt->figure[id];
	t = find_t_sphere(&r, sphere);
	return (t);
}
