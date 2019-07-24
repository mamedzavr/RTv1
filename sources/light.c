/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:18:14 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			compute_shadow(t_rt *rt, t_ray ray, t_vector3 light_pos)
{
	double	dist;

	dist = vec_magn(vec_sub(light_pos, ray.pos));
	find_closest_intersection(rt, ray);
	rt->id = find_closest_obj(rt);
	if (rt->id < 0 || rt->t[rt->id] > dist)
		return (dist);
	return (-1);
}

double		compute_shine(t_rt *rt, t_vector3 n, int i, double intense)
{
	double		r_dot_v;

	r_dot_v = 0.0;
	rt->r = vec_minus(vec_mult(n, 2 * vec_dot(n, rt->l)), rt->l);
	rt->v = vec_mult(rt->cam.dir, -1);
	r_dot_v = vec_dot(rt->r, rt->v);
	if (r_dot_v > 0)
		intense += rt->light[i].intense * pow(r_dot_v / \
		(vec_magn(rt->r) * vec_magn(rt->v)), rt->figure[i].spec);
	return (intense);
}

double		compute_light(t_rt *rt, t_vector3 p, t_vector3 n)
{
	int			i;
	double		intense;
	double		n_dot_l;
	t_ray		ray;

	intense = 0.0;
	i = -1;
	while (++i < rt->lightcount)
	{
		if (rt->light[i].type == AMBIENT)
			intense += rt->light[i].intense;
		else
		{
			rt->l = vec_norm(vec_sub(rt->light[i].pos, p));
			ray.pos = p;
			ray.dir = rt->l;
			n_dot_l = vec_dot(n, rt->l);
			if (compute_shadow(rt, ray, rt->light[i].pos) < 0)
				continue ;
			(n_dot_l > 0) ? intense += rt->light[i].intense * n_dot_l : 0;
			if (rt->figure[i].spec != -1)
				intense = compute_shine(rt, n, i, intense);
		}
	}
	return (intense);
}
