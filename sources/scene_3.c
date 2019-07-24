/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:14:54 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 11:46:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		cylinder_7_2(t_rt *rt)
{
	rt->figure[0].type = CYLINDER;
	rt->figure[0].pos = vec_new(-2.5, 0, 12);
	rt->figure[0].dir = vec_new(0, 1, 0);
	rt->figure[0].color = set_color(100, 100, 100);
	rt->figure[0].spec = 30;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = 0.5;
	rt->figure[1].type = CYLINDER;
	rt->figure[1].pos = vec_new(2.5, 0, 12);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(100, 100, 100);
	rt->figure[1].spec = 30;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	rt->figure[1].radius = 0.5;
}

void		cylinder_7(t_rt *rt)
{
	rt->figure[3].type = CYLINDER;
	rt->figure[3].pos = vec_new(2.5, 0, 8);
	rt->figure[3].dir = vec_new(0, 1, 0);
	rt->figure[3].color = set_color(100, 100, 100);
	rt->figure[3].spec = 30;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[3].radius = 0.5;
	rt->figure[4].type = CYLINDER;
	rt->figure[4].pos = vec_new(-2.5, 0, 8);
	rt->figure[4].dir = vec_new(0, 1, 0);
	rt->figure[4].color = set_color(100, 100, 100);
	rt->figure[4].spec = 30;
	rt->figure[4].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[4].dir);
	rt->figure[4].radius = 0.5;
}
