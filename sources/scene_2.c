/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:06:22 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 12:23:03 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		sphere_7_3(t_rt *rt)
{
	rt->figure[7].type = SPHERE;
	rt->figure[7].pos = vec_new(-2.5, 2.3, 8);
	rt->figure[7].dir = vec_new(0, 1, 0);
	rt->figure[7].color = set_color(100, 100, 100);
	rt->figure[7].spec = 30;
	rt->figure[7].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[7].dir);
	rt->figure[7].radius = 0.9;
	rt->figure[8].type = SPHERE;
	rt->figure[8].pos = vec_new(2.5, 2.3, 8);
	rt->figure[8].dir = vec_new(0, 1, 0);
	rt->figure[8].color = set_color(100, 100, 100);
	rt->figure[8].spec = 30;
	rt->figure[8].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[8].dir);
	rt->figure[8].radius = 0.9;
	rt->figure[9].type = SPHERE;
	rt->figure[9].pos = vec_new(-2.5, -2.3, 8);
	rt->figure[9].dir = vec_new(0, 1, 0);
	rt->figure[9].color = set_color(100, 100, 100);
	rt->figure[9].spec = 30;
	rt->figure[9].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[9].dir);
	rt->figure[9].radius = 0.9;
}

static void		sphere_7_2(t_rt *rt)
{
	rt->figure[10].type = SPHERE;
	rt->figure[10].pos = vec_new(2.5, -2.3, 8);
	rt->figure[10].dir = vec_new(0, 1, 0);
	rt->figure[10].color = set_color(100, 100, 100);
	rt->figure[10].spec = 30;
	rt->figure[10].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[10].dir);
	rt->figure[10].radius = 0.9;
	rt->figure[11].type = SPHERE;
	rt->figure[11].pos = vec_new(-2.5, 2.3, 12);
	rt->figure[11].dir = vec_new(0, 1, 0);
	rt->figure[11].color = set_color(100, 100, 100);
	rt->figure[11].spec = 30;
	rt->figure[11].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[11].dir);
	rt->figure[11].radius = 0.9;
	rt->figure[12].type = SPHERE;
	rt->figure[12].pos = vec_new(2.5, 2.3, 12);
	rt->figure[12].dir = vec_new(0, 1, 0);
	rt->figure[12].color = set_color(100, 100, 100);
	rt->figure[12].spec = 30;
	rt->figure[12].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[12].dir);
	rt->figure[12].radius = 0.9;
}

static void		sphere_7(t_rt *rt)
{
	rt->figure[13].type = SPHERE;
	rt->figure[13].pos = vec_new(-2.5, -2.3, 12);
	rt->figure[13].dir = vec_new(0, 1, 0);
	rt->figure[13].color = set_color(100, 100, 100);
	rt->figure[13].spec = 30;
	rt->figure[13].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[13].dir);
	rt->figure[13].radius = 0.9;
	rt->figure[14].type = SPHERE;
	rt->figure[14].pos = vec_new(2.5, -2.3, 12);
	rt->figure[14].dir = vec_new(0, 1, 0);
	rt->figure[14].color = set_color(100, 100, 100);
	rt->figure[14].spec = 30;
	rt->figure[14].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[14].dir);
	rt->figure[14].radius = 0.9;
	rt->figure[15].type = SPHERE;
	rt->figure[15].pos = vec_new(0, -1, 10);
	rt->figure[15].dir = vec_new(0, 1, 0);
	rt->figure[15].color = set_color(255, 100, 100);
	rt->figure[15].spec = 1000;
	rt->figure[15].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[15].dir);
	rt->figure[15].radius = 0.7;
}

static void		plane_7(t_rt *rt)
{
	rt->figure[2].type = PLANE;
	rt->figure[2].pos = vec_new(0, -2, 0);
	rt->figure[2].dir = vec_new(0, 1, 0);
	rt->figure[2].color = set_color(0, 150, 150);
	rt->figure[2].spec = 1000;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[5].type = PLANE;
	rt->figure[5].pos = vec_new(0, 2, 0);
	rt->figure[5].dir = vec_new(0, 1, 0);
	rt->figure[5].color = set_color(80, 80, 80);
	rt->figure[5].spec = 1000;
	rt->figure[5].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[5].dir);
	rt->figure[6].type = PLANE;
	rt->figure[6].pos = vec_new(0, -5, -15);
	rt->figure[6].dir = vec_new(100, 0, -1);
	rt->figure[6].color = set_color(50, 0, 0);
	rt->figure[6].spec = 100;
	rt->figure[6].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[6].dir);
}

void			init_scene_7(t_rt *rt)
{
	rt->objcount = 16;
	rt->lightcount = 4;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 19);
	rt->cam.rot = vec_new(0, 0, 0);
	rt->light[0].type = AMBIENT;
	rt->light[0].intense = 0.2;
	rt->light[1].type = POINT;
	rt->light[1].intense = 0.6;
	rt->light[1].pos = (t_vector3){7, 1.9, 20};
	rt->light[2].type = POINT;
	rt->light[2].intense = 0.6;
	rt->light[2].pos = (t_vector3){-7, 1.9, 20};
	rt->light[3].type = POINT;
	rt->light[3].intense = 0.2;
	rt->light[3].pos = (t_vector3){0, 1.9, 10};
	plane_7(rt);
	sphere_7(rt);
	sphere_7_2(rt);
	sphere_7_3(rt);
	cylinder_7(rt);
	cylinder_7_2(rt);
}
