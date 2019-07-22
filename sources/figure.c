/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:58:00 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/22 19:03:15 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	choose_figure(t_rt *rt, t_ray r)
{
	t_vector3	pt;

	if (ft_strcmp(rt->figure[rt->id].type, "sphere") == 0 && rt->t[rt->id] > 0)
		comp_ray(rt, find_n_sphere(r, rt->t[rt->id], \
					rt->figure[rt->id].pos), r, rt->t[rt->id]);
	else if (ft_strcmp(rt->figure[rt->id].type, "cone") == 0)
	{
		pt = vec_add(r.pos, vec_scale(r.dir, rt->t[rt->id]));
		if (rt->t[rt->id] > 0)
		{
			comp_ray(rt, find_n_cone(r, pt, rt->t[rt->id], \
					rt->figure[rt->id]), r, rt->t[rt->id]);
		}
	}
	else if (ft_strcmp(rt->figure[rt->id].type, "cylinder") == 0)
	{
		if (rt->t[rt->id] > 0)
			comp_ray(rt, find_n_cylinder(r, rt->t[rt->id], \
					rt->figure[rt->id]), r, rt->t[rt->id]);
	}
	else if (ft_strcmp(rt->figure[rt->id].type, "plane") == 0)
	{
		if (rt->t[rt->id] > 0)
			comp_ray(rt, find_n_plane(r, rt->figure[rt->id]), r, rt->t[rt->id]);
	}
}
