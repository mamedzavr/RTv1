/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:16:43 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/24 12:14:45 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		init_scene_4_1(t_rt *rt)
{
	rt->figure[2].type = CYLINDER;
	rt->figure[2].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[2].dir = vec_new(0, -1, -50);
	rt->figure[2].color = set_color(87, 13, 78);
	rt->figure[2].spec = 30;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[2].radius = 0.5;
	rt->figure[3].type = PLANE;
	rt->figure[3].pos = vec_new(0, -5, -15);
	rt->figure[3].dir = vec_new(100, 0, -1);
	rt->figure[3].color = set_color(50, 13, 150);
	rt->figure[3].spec = 40;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[4].type = SPHERE;
	rt->figure[4].pos = vec_new(-0.5, -0.5, 0.2);
	rt->figure[4].radius = 0.5;
	rt->figure[4].color = set_color(130, 0, 0);
	rt->figure[4].spec = 25;
	rt->light[0].type = AMBIENT;
	rt->light[0].intense = 0.1;
	rt->light[1].type = POINT;
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){3, 2, 5};
}

void		init_scene_5(t_rt *rt)
{
	rt->objcount = 5;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(5, 5, 10);
	rt->cam.rot = vec_new(-10, 15, -5);
	rt->figure[0].type = CONE;
	rt->figure[0].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[0].dir = vec_new(0, -1, 50);
	rt->figure[0].angle = tan(RAD(30));
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 10;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(1));
	rt->figure[1].type = PLANE;
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(50, 50, 50);
	rt->figure[1].spec = 20;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	init_scene_5_1(rt);
}

void		init_scene_5_1(t_rt *rt)
{
	rt->figure[2].type = CYLINDER;
	rt->figure[2].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[2].dir = vec_new(0, -1, -50);
	rt->figure[2].color = set_color(87, 13, 78);
	rt->figure[2].spec = 30;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[2].radius = 0.5;
	rt->figure[3].type = PLANE;
	rt->figure[3].pos = vec_new(0, -5, -15);
	rt->figure[3].dir = vec_new(100, 0, -1);
	rt->figure[3].color = set_color(50, 13, 150);
	rt->figure[3].spec = 40;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[4].type = SPHERE;
	rt->figure[4].pos = vec_new(-0.5, -0.5, 0.2);
	rt->figure[4].radius = 0.5;
	rt->figure[4].color = set_color(130, 0, 0);
	rt->figure[4].spec = 25;
	rt->light[0].type = AMBIENT;
	rt->light[0].intense = 0.0;
	rt->light[1].type = POINT;
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){3, 2, 5};
}

void		init_scene_6(t_rt *rt)
{
	rt->objcount = 5;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(6, 2, 5);
	rt->cam.rot = vec_new(-22, 37, 0);
	rt->figure[0].type = CONE;
	rt->figure[0].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[0].dir = vec_new(0, -1, 50);
	rt->figure[0].angle = tan(RAD(30));
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 10;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(1));
	rt->figure[1].type = PLANE;
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(50, 50, 50);
	rt->figure[1].spec = 20;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	init_scene_6_1(rt);
}

void		init_scene_6_1(t_rt *rt)
{
	rt->figure[2].type = CYLINDER;
	rt->figure[2].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[2].dir = vec_new(0, -1, -50);
	rt->figure[2].color = set_color(87, 13, 78);
	rt->figure[2].spec = 30;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[2].radius = 0.5;
	rt->figure[3].type = PLANE;
	rt->figure[3].pos = vec_new(0, -5, -15);
	rt->figure[3].dir = vec_new(100, 0, -1);
	rt->figure[3].color = set_color(50, 13, 150);
	rt->figure[3].spec = 40;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[4].type = SPHERE;
	rt->figure[4].pos = vec_new(-0.5, -0.5, 0.2);
	rt->figure[4].radius = 0.5;
	rt->figure[4].color = set_color(130, 0, 0);
	rt->figure[4].spec = 25;
	rt->light[0].type = AMBIENT;
	rt->light[0].intense = 0.0;
	rt->light[1].type = POINT;
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){3, 2, 5};
}
