/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:59:34 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/24 12:25:38 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		key(t_rt *rt)
{
	const Uint8	*key;

	key = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&rt->sdl.event);
	rt->sdl.event.type == SDL_QUIT ? rt->boolean = 1 : 0;
	rt->sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		rt->boolean = 1 : 0;
	(key[SDL_SCANCODE_UP] && rt->run-- > 0) ? rt->cam.pos.y += 0.1 : 0;
	(key[SDL_SCANCODE_DOWN] && rt->run-- > 0) ? rt->cam.pos.y -= 0.1 : 0;
	(key[SDL_SCANCODE_LEFT] && rt->run-- > 0) ? rt->cam.pos.x -= 0.1 : 0;
	(key[SDL_SCANCODE_RIGHT] && rt->run-- > 0) ? rt->cam.pos.x += 0.1 : 0;
	(key[SDL_SCANCODE_W] && rt->run-- > 0) ? rt->cam.pos.z -= 0.1 : 0;
	(key[SDL_SCANCODE_S] && rt->run-- > 0) ? rt->cam.pos.z += 0.1 : 0;
	(key[SDL_SCANCODE_KP_4] && rt->run-- > 0) ? rt->cam.rot.y += 0.2 : 0;
	(key[SDL_SCANCODE_KP_6] && rt->run-- > 0) ? rt->cam.rot.y -= 0.2 : 0;
	(key[SDL_SCANCODE_KP_5] && rt->run-- > 0) ? rt->cam.rot.x -= 0.2 : 0;
	(key[SDL_SCANCODE_KP_8] && rt->run-- > 0) ? rt->cam.rot.x += 0.2 : 0;
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

void		parse_number(t_rt *rt, char c)
{
	rt->run = 0;
	rt->boolean = 0;
	if (!(rt->color = (unsigned int *)malloc(sizeof(unsigned int)
		* WINH * WINW)))
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

int			main(int ac, char **av)
{
	t_rt	rt;

	if (ac == 2 && (av[1][0] == '1' || av[1][0] == '2' || av[1][0] == '3' ||
	av[1][0] == '4' || av[1][0] == '5' || av[1][0] == '6' || av[1][0] == '7'))
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
