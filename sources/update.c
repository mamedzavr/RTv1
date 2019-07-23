/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:04:52 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/23 16:24:50 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		sdl_run(t_rt *rt)
{
	SDL_UpdateTexture(rt->sdl.fillscreen, NULL, rt->color, WINW * 4);
	SDL_SetRenderDrawColor(rt->sdl.render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(rt->sdl.render, rt->sdl.fillscreen, NULL, NULL);
	SDL_RenderPresent(rt->sdl.render);
	SDL_RenderClear(rt->sdl.render);
}

static void		color(t_rt *rt, t_ray ray, int *i)
{
	t_color		buff;

	buff = trace_ray(rt, ray);
	(buff.r > 255) ? buff.r = 255 : 0;
	(buff.g > 255) ? buff.g = 255 : 0;
	(buff.b > 255) ? buff.b = 255 : 0;
	rt->color[i[0] + i[1] * WINW] = (buff.r << 16) + (buff.g << 8) + \
														(buff.b);
}

void			update_screen(t_rt *rt)
{
	// float		x;
	// float		y;
	int			i[2];
	t_ray		ray;
	t_vector3	ppc;

	i[1] = -1;
	if (!(rt->t = (double*)malloc(sizeof(double) * rt->objcount)))
		memory_error();
	ppc = vec_add(rt->cam.pos, vec_scale(rt->cam.dir, PPD));
	ray.pos = rt->cam.pos;
	while (++i[1] < WINH)
	{
		i[0] = -1;
		while (++i[0] < WINW)
		{
			// x = ((2 * (i[0] + 0.5) / WINW - 1) * tan(FOV / 2.) * WINW / WINH) + rt->cam.rot.x;
			// y = -(2 * (i[1] + 0.5) / WINH - 1) * tan(FOV / 2.) + rt->cam.rot.y;


			// rt->cam.dir = vec_new(0, 0, -1);
			// rt->cam.dir = vec_rot_xyz(rt->cam.dir, rt->cam.rot);
			// rt->cam.updir = vec_new(0, -1, 0);
			// rt->cam.updir = vec_rot_xyz(rt->cam.updir, rt->cam.rot);
			// rt->cam.ldir = vec_norm(vec_cross(rt->cam.dir, rt->cam.updir));
			ray.dir = vec_sub(ppc, vec_scale(rt->cam.ldir, (i[0] - WINH)));
			ray.dir = vec_add(ray.dir, vec_scale(rt->cam.updir, (i[1] - WINH)));
			ray.dir = vec_norm(vec_sub(ray.dir, ray.pos));


			// canvas_to_viewport(rt, x, y);
			// rt->cam.dir = vec_norm((t_vector3){x, y, -1});
			// ray.dir =  rt->cam.dir;
			color(rt, ray, i);
		}
	}
	sdl_run(rt);
}
