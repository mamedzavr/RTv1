/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:51:45 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		choose_closest_t(double a, double b, double d)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0.0003) || (t1 >= 0.0003 && t2 < 0.0003))
		return (t1);
	if ((t2 <= t1 && t2 >= 0.0003) || (t2 >= 0.0003 && t1 < 0.0003))
		return (t2);
	return (-1);
}

void		find_closest_intersection(t_rt *rt, t_ray r)
{
	int		i;

	rt->closest_obj = NULL;
	i = -1;
	while (++i < rt->objcount)
	{
		if (rt->figure[i].type == SPHERE)
			rt->t[i] = calc_sphere(rt, r, i);
		else if (rt->figure[i].type == CONE)
			rt->t[i] = calc_cone(rt, r, i);
		else if (rt->figure[i].type == CYLINDER)
			rt->t[i] = calc_cylinder(rt, r, i);
		else if (rt->figure[i].type == PLANE)
			rt->t[i] = calc_plane(rt, r, i);
	}
}

int			find_closest_obj(t_rt *rt)
{
	int		id;
	int		i;

	id = -1;
	i = -1;
	while (++i < rt->objcount)
	{
		if (rt->t[i] >= 0 && (id == -1 || rt->t[i] < rt->t[id]))
			id = i;
	}
	return (id);
}

void		comp_ray(t_rt *rt, t_vector3 n, t_ray r, double t)
{
	if (rt->id == -1)
		return ;
	rt->n = vec_cpy(n);
	rt->p = vec_add(r.pos, vec_scale(r.dir, t));
}

t_color		trace_ray(t_rt *rt, t_ray r)
{
	int			i;
	int			id;
	t_color		current_color;
	double		rgb;

	i = -1;
	rt->id = -1;
	if (!(rt->t = (double*)malloc(sizeof(double) * rt->objcount)))
		memory_error();
	while (++i < rt->objcount)
	{
		rt->t[i] = INFINITY;
		find_closest_intersection(rt, r);
	}
	rt->id = find_closest_obj(rt);
	if (rt->id == -1)
		return ((t_color){0, 0, 0});
	choose_figure(rt, r);
	id = rt->id;
	rgb = compute_light(rt, rt->p, rt->n);
	current_color = mult_color(rt->figure[id].color, rgb);
	free(rt->t);
	return (current_color);
}
