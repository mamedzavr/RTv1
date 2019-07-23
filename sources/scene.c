/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:53:48 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 14:41:31 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		init_scene_1(t_rt *rt)
{
	rt->objcount = 1;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 10);
	rt->cam.rot = vec_new(0, 0, 1);

	rt->view.pos = vec_new(1, 1, 1);

	rt->figure[0].type = "sphere";
	rt->figure[0].pos = vec_new(0, 0, 0);
	rt->figure[0].radius = 3;
	rt->figure[0].color = set_color(160, 0, 0);
	rt->figure[0].spec = 50;
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.0;
	rt->light[1].type = "point";
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){2, 0.5, 5};
}

void		init_scene_2(t_rt *rt)
{
	rt->objcount = 1;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 10);
	rt->cam.rot = vec_new(0, 0, 1);
	rt->view.pos = vec_new(1, 1, 1);
	rt->figure[0].type = "cylinder";
	rt->figure[0].pos = vec_new(0, 1, 0);
	rt->figure[0].dir =  vec_new(0, -1, 0);
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = -1;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = 2;
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.0;
	rt->light[1].type = "point";
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){20, 0.5, 20};
}

void		init_scene_3(t_rt *rt)
{
	rt->objcount = 2;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 5);
	rt->cam.rot = vec_new(0, 0, 1);
	rt->view.pos = vec_new(1, 1, 1);
	rt->figure[0].type = "cone";
	rt->figure[0].pos = vec_new(0, -0.2, 0);
	rt->figure[0].dir =  vec_new(0, -1, 0);
	rt->figure[0].angle = 0.5;
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 30;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(0.8));
	rt->figure[1].type = "plane";
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(10, 15, 110);
	rt->figure[1].spec = 50;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.0;
	rt->light[1].type = "point";
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){-5, 1.5, 5};
}

void		init_scene_4(t_rt *rt)
{
	rt->objcount = 5;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 5);
	rt->cam.rot = vec_new(0, 0, 1);
	rt->view.pos = vec_new(1, 1, 1);
	rt->figure[0].type = "cone";
	rt->figure[0].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[0].dir =  vec_new(0, -1, 50);
	rt->figure[0].angle = tan(RAD(30));
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 10;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(1));
	rt->figure[1].type = "plane";
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(50, 50, 50);
	rt->figure[1].spec = 20;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	rt->figure[2].type = "cylinder";
	rt->figure[2].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[2].dir =  vec_new(0, -1, -50);
	rt->figure[2].color = set_color(87, 13, 78);
	rt->figure[2].spec = 30;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[2].radius = 0.5;
	rt->figure[3].type = "plane";
	rt->figure[3].pos = vec_new(0, -5, -15);
	rt->figure[3].dir = vec_new(100, 0, -1);
	rt->figure[3].color = set_color(50, 13, 150);
	rt->figure[3].spec = 40;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[4].type = "sphere";
	rt->figure[4].pos = vec_new(-0.5, -0.5, 0.2);
	rt->figure[4].radius = 0.5;
	rt->figure[4].color = set_color(130, 0, 0);
	rt->figure[4].spec = 25;
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.0;
	rt->light[1].type = "point";
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
	rt->cam.pos = vec_new(0, 0, 5);
	rt->cam.rot = vec_new(0, 0, 1);
	rt->view.pos = vec_new(1, 1, 1);
	rt->figure[0].type = "cone";
	rt->figure[0].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[0].dir =  vec_new(0, -1, 50);
	rt->figure[0].angle = tan(RAD(30));
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 10;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(1));
	rt->figure[1].type = "plane";
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].color = set_color(50, 50, 50);
	rt->figure[1].spec = 20;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	rt->figure[2].type = "cylinder";
	rt->figure[2].pos = vec_new(-0.4, 0.45, 0);
	rt->figure[2].dir =  vec_new(0, -1, -50);
	rt->figure[2].color = set_color(87, 13, 78);
	rt->figure[2].spec = 30;
	rt->figure[2].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[2].dir);
	rt->figure[2].radius = 0.5;
	rt->figure[3].type = "plane";
	rt->figure[3].pos = vec_new(0, -5, -15);
	rt->figure[3].dir = vec_new(100, 0, -1);
	rt->figure[3].color = set_color(50, 13, 150);
	rt->figure[3].spec = 40;
	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
	rt->figure[4].type = "sphere";
	rt->figure[4].pos = vec_new(-0.5, -0.5, 0.2);
	rt->figure[4].radius = 0.5;
	rt->figure[4].color = set_color(130, 0, 0);
	rt->figure[4].spec = 25;
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.0;
	rt->light[1].type = "point";
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){3, 2, 5};
}

void		init_scene_6(t_rt *rt)
{
	rt->objcount = 2;
	rt->lightcount = 2;
	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
		memory_error();
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
		memory_error();
	rt->cam.pos = vec_new(0, 0, 5);
	rt->cam.rot = vec_new(1.7, -0.9, 1.4);
	rt->view.pos = vec_new(1, 1, 1);
	rt->figure[0].type = "cone";
	rt->figure[0].pos = vec_new(0, -0.2, 0);
	rt->figure[0].dir =  vec_new(0, -1, 0);
	rt->figure[0].angle = 0.5;
	rt->figure[0].color = set_color(15, 100, 0);
	rt->figure[0].spec = 30;
	rt->figure[0].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[0].dir);
	rt->figure[0].radius = tan(RAD(0.8));
	rt->figure[1].type = "plane";
	rt->figure[1].pos = vec_new(0, -1, 0);
	rt->figure[1].dir = vec_new(0, 1, 0);
	rt->figure[1].radius = 0;
	rt->figure[1].color = set_color(10, 15, 110);
	rt->figure[1].spec = 50;
	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);
	rt->light[0].type = "ambient";
	rt->light[0].intense = 0.2;
	rt->light[1].type = "point";
	rt->light[1].intense = 0.5;
	rt->light[1].pos = (t_vector3){1, 1.5, 5};
}
