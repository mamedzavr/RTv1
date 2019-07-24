/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:04:52 by fshanaha          #+#    #+#             */
/*   Updated: 2019/07/24 12:33:11 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

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
	int			i[2];
	t_ray		ray;
	t_vector3	ppc;

	i[1] = -1;
	ppc = vec_add(rt->cam.pos, vec_scale(rt->cam.dir, PPD));
	ray.pos = rt->cam.pos;
	while (++i[1] < WINH)
	{
		i[0] = -1;
		while (++i[0] < WINW)
		{
			ray.dir = vec_sub(ppc, vec_scale(rt->cam.ldir, (i[0] - WINW_H)));
			ray.dir = vec_add(ray.dir, vec_scale(rt->cam.updir,
				(i[1] - WINH_H)));
			ray.dir = vec_norm(vec_sub(ray.dir, ray.pos));
			color(rt, ray, i);
		}
	}
	sdl_run(rt);
}
