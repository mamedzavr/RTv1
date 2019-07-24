/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:58:00 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	choose_figure(t_rt *rt, t_ray r)
{
	t_vector3	pt;

	if (rt->figure[rt->id].type == SPHERE && rt->t[rt->id] > 0)
		comp_ray(rt, find_n_sphere(r, rt->t[rt->id], \
					rt->figure[rt->id].pos), r, rt->t[rt->id]);
	else if (rt->figure[rt->id].type == CONE)
	{
		pt = vec_add(r.pos, vec_scale(r.dir, rt->t[rt->id]));
		if (rt->t[rt->id] > 0)
		{
			comp_ray(rt, find_n_cone(r, pt, rt->t[rt->id], \
					rt->figure[rt->id]), r, rt->t[rt->id]);
		}
	}
	else if (rt->figure[rt->id].type == CYLINDER)
	{
		if (rt->t[rt->id] > 0)
			comp_ray(rt, find_n_cylinder(r, rt->t[rt->id], \
					rt->figure[rt->id]), r, rt->t[rt->id]);
	}
	else if (rt->figure[rt->id].type == PLANE)
	{
		if (rt->t[rt->id] > 0)
			comp_ray(rt, find_n_plane(r, rt->figure[rt->id]), r, rt->t[rt->id]);
	}
}
