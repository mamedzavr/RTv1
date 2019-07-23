/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:59:34 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 17:37:42 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		key(t_rt *rt)
{
	const Uint8	*key;

	key = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&rt->sdl.event);
	rt->sdl.event.type == SDL_QUIT ? rt->boolean = 1 : 0;
	rt->sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		rt->boolean = 1 : 0;
	if (key[SDL_SCANCODE_UP] && rt->run-- > 0)
		rt->cam.pos.y += 0.1;
	if (key[SDL_SCANCODE_DOWN] && rt->run-- > 0)
		rt->cam.pos.y -= 0.1;
	if (key[SDL_SCANCODE_LEFT] && rt->run-- > 0)
		rt->cam.pos.x -= 0.1;
	if (key[SDL_SCANCODE_RIGHT] && rt->run-- > 0)
		rt->cam.pos.x += 0.1;
	if (key[SDL_SCANCODE_W] && rt->run-- > 0)
		rt->cam.pos.z -= 0.1;
	if (key[SDL_SCANCODE_S] && rt->run-- > 0)
		rt->cam.pos.z += 0.1;


	if (key[SDL_SCANCODE_KP_4] && rt->run-- > 0)
		rt->cam.rot.y += 0.2;
	if (key[SDL_SCANCODE_KP_6] && rt->run-- > 0)
		rt->cam.rot.y -= 0.2;
	if (key[SDL_SCANCODE_KP_5] && rt->run-- > 0)
		rt->cam.rot.x -= 0.2;
	if (key[SDL_SCANCODE_KP_8] && rt->run-- > 0)
		rt->cam.rot.x += 0.2;
	// if (key[SDL_SCANCODE_E] && rt->run-- > 0)
	// 	rt->cam.rot.z -= 0.2;
	// if (key[SDL_SCANCODE_D] && rt->run-- > 0)
	// 	rt->cam.rot.z += 0.2;
	// printf("\ncam.pos.x=%f\ncam.pos.y=%f\ncam.pos.z=%f\ncam.rot.x=%f\ncam.rot.y=%f|\n", rt->cam.pos.x, rt->cam.pos.y, rt->cam.pos.z, rt->cam.rot.x, rt->cam.rot.y);
}

void		init_sdl(t_rt *rt)
{
	Uint32		render_flags;

	rt->sdl.win = SDL_CreateWindow("RTv1",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, 0);
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	rt->sdl.render = SDL_CreateRenderer(rt->sdl.win, -1, render_flags);
	rt->sdl.fillscreen = SDL_CreateTexture(rt->sdl.render,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WINW, WINH);
}

// void		init(t_rt *rt)
// {
// 	rt->objcount = 6;
// 	rt->lightcount = 3;

// 	if (!(rt->color = (unsigned int *)malloc(sizeof(unsigned int) * WINH * WINW)))
// 		memory_error();
// 	if (!(rt->figure = (t_figure *)malloc(sizeof(t_figure) * rt->objcount)))
// 		memory_error();
// 	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->lightcount)))
// 		memory_error();

// 	rt->figure[0].type = "sphere";
// 	rt->figure[0].pos = vec_new(-3, 1, -3);
// 	rt->figure[0].radius = 2;
// 	rt->figure[0].color = set_color(0, 150, 0);
// 	rt->figure[0].spec = 50;

// 	rt->figure[1].type = "plane";
// 	rt->figure[1].pos = vec_new(0, -1, 0);
// 	rt->figure[1].dir = vec_new(0, 1, 0);
// 	rt->figure[1].radius = 5000;
// 	rt->figure[1].color = set_color(150, 150, 0);
// 	rt->figure[1].spec = 50;
// 	rt->figure[1].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[1].dir);

// 	rt->figure[2].type = "sphere";
// 	rt->figure[2].pos = vec_new(3, 1, -3);
// 	rt->figure[2].radius = 2;
// 	rt->figure[2].color = set_color(0, 0, 150);
// 	rt->figure[2].spec = 50;

// 	rt->figure[3].type = "cone";
// 	// rt->figure[3].type = "cylinder";
// 	rt->figure[3].pos = vec_new(0, 1, 0);
// 	rt->figure[3].dir =  vec_new(0, -1, 0);
// 	rt->figure[3].angle = 0.1;
// 	rt->figure[3].color = set_color(100, 50, 150);
// 	rt->figure[3].spec = 50;
// 	rt->figure[3].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[3].dir);
// 	rt->figure[3].radius = tan(RAD(0.8));

// 	rt->figure[5].type = "cylinder";
// 	rt->figure[5].pos = vec_new(0, 1, 0);
// 	rt->figure[5].dir =  vec_new(0, -1, 30);
// 	rt->figure[5].angle = 0.1;
// 	rt->figure[5].color = set_color(50, 50, 50);
// 	rt->figure[5].spec = 50;
// 	rt->figure[5].v = vec_rot_xyz(vec_new(0, 1, 0), rt->figure[5].dir);
// 	rt->figure[5].radius = 0;


// 	rt->figure[4].type = "sphere";
// 	rt->figure[4].pos = vec_new(0, 1, -1);
// 	rt->figure[4].radius = 0;
// 	rt->figure[4].color = set_color(0, 288, 50);
// 	rt->figure[4].spec = 50;


// 	rt->light[0].type = "ambient";
// 	rt->light[0].intense = 0.2;

// 	rt->light[1].type = "point";
// 	rt->light[1].intense = 0.3;
// 	rt->light[1].pos = (t_vector3){-3, 2, 5};

// 	rt->light[2].type = "point";
// 	rt->light[2].intense = 0.8;
// 	rt->light[2].pos = (t_vector3){3, 2, 5};

// 	rt->cam.pos = vec_new(0, 9, 20);
// 	rt->cam.dir = vec_new(0, 0, 0);
// 	rt->view.pos = vec_new(1, 1, 1);

	// rt->light[0].type = "point";
	// rt->light[0].intense = 0.3;
	// rt->light[0].pos = (t_vector3){-3, 2, 5};
// }



void		parse_number(t_rt *rt, char c)
{
	if (!(rt->color = (unsigned int *)malloc(sizeof(unsigned int) * WINH * WINW)))
		memory_error();
	rt->cam.rot = (t_vector3){0, 0, 0};
	(c == '1') ? init_scene_1(rt) : 0;
	(c == '2') ? init_scene_2(rt) : 0;
	(c == '3') ? init_scene_3(rt) : 0;
	(c == '4') ? init_scene_4(rt) : 0;
	(c == '5') ? init_scene_5(rt) : 0;
	(c == '6') ? init_scene_6(rt) : 0;
	(c == '7') ? init_scene_7(rt) : 0;
}

int 		main(int ac, char **av)
{
	t_rt	rt;

	rt.run = 0;
	rt.boolean = 0;
	if (ac == 2 && (av[1][0] == '1' || av[1][0] == '2' || av[1][0] == '3' || av[1][0] == '4' ||
		av[1][0] == '5' || av[1][0] == '6' || av[1][0] == '7'))
	{
		parse_number(&rt, av[1][0]);
		init_sdl(&rt);
		while (!rt.boolean)
		{
			if (rt.run == 0)
			{
				rt.cam.dir = vec_new(0, 0, -1);
				rt.cam.dir = vec_rot_xyz(rt.cam.dir, rt.cam.rot);
				rt.cam.updir = vec_new(0, -1, 0);
				rt.cam.updir = vec_rot_xyz(rt.cam.updir, rt.cam.rot);
				rt.cam.ldir = vec_norm(vec_cross(rt.cam.dir, rt.cam.updir));
				update_screen(&rt);
				rt.run = 1;
			}
			key(&rt);
		}
	}
	else
		ft_putendl("usage:\n./RTv1 1 || 2 || 3 || 4 || 5 || 6 || 7");
	return (0);
}
