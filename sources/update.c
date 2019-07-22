#include "../includes/rt.h"

void		canvas_to_viewport(t_rt *rt, int x, int y)
{
	rt->cam.dir.x = x * rt->view.pos.x / WINW;
	rt->cam.dir.y = y * rt->view.pos.y / WINH;
	rt->cam.dir.z = rt->cam.pos.z;
}

void	update_screen(t_rt *rt)
{
	float		x;
	float		y;
	int			j;
	int			i;
	t_color		buff;
	t_ray		ray;

	j = 0;
	if (!(rt->t = (double*)malloc(sizeof(double) * rt->objcount)))
		memory_error();
	ray.pos = rt->cam.pos;
	while (j < WINH)
	{
		i = 0;
		while (i < WINW)
		{
			x = (2 * (i + 0.5) / WINW - 1) * tan(FOV / 2.) * WINW / WINH;
			y = - (2 * (j + 0.5) / WINH - 1) * tan(FOV / 2.);
			rt->cam.dir = vec_norm((t_vector3){x, y, -1});
			ray.dir = rt->cam.dir;
			buff = trace_ray(rt, ray);
			(buff.r > 255) ? buff.r = 255 : 0;
			(buff.g > 255) ? buff.g = 255 : 0;
			(buff.b > 255) ? buff.b = 255 : 0;
			// if (buff.r > 255)
			// if (buff.r > 255)
			// 	buff.r = 255;
			// if (buff.b > 255)
			// 	buff.b = 255;
			rt->color[i + j * WINW] = (buff.r << 16) + (buff.g << 8) + (buff.b);
			i++;
		}
		j++;
	}
	SDL_UpdateTexture(rt->sdl.fillscreen, NULL, rt->color, WINW * 4);
	SDL_SetRenderDrawColor(rt->sdl.render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(rt->sdl.render, rt->sdl.fillscreen, NULL,
	NULL);
	SDL_RenderPresent(rt->sdl.render);
	SDL_RenderClear(rt->sdl.render);
}
