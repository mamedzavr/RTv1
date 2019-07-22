#include "../includes/rt.h"

int			compute_shadow(t_rt *rt, t_ray ray, t_vector3 light_pos)
{
	double	dist;

	dist = vec_magn(vec_sub(light_pos, ray.pos));
	find_closest_intersection(rt, ray);
	rt->id = find_closest_obj(rt);
	if (rt->id < 0 || rt->t[rt->id] > dist)
	{
		return (dist);
	}
	return (-1);
}

double		compute_light(t_rt *rt, t_vector3 P, t_vector3 N)
{
	int			i;
	double		intense;
	t_vector3	L;
	double		n_dot_l;

	intense = 0.0;
	i = -1;
	while (++i < rt->lightcount)
	{
		if (ft_strcmp(rt->light[i].type, "ambient") == 0)
			intense += rt->light[i].intense;
		else
		{
			L = vec_sub(rt->light[i].pos, P);
			L = vec_norm(L);
			t_ray	r;
			r.pos = P;
			r.dir = L;
			n_dot_l = vec_dot(N, L);
			if (compute_shadow(rt, r, rt->light[i].pos) < 0)
			{
				continue ;
			}
			if (n_dot_l > 0)
				intense += rt->light[i].intense * n_dot_l;
			if (rt->figure[i].spec != -1)
			{
				t_vector3	R = vec_minus(vec_mult(N, 2 * vec_dot(N, L)), L);
				t_vector3	V = vec_mult(rt->cam.dir, -1);
				double		r_dot_v = vec_dot(R, V);
				r_dot_v = vec_dot(R, V);
				if (r_dot_v > 0)
					intense += rt->light[i].intense * pow(r_dot_v / (vec_magn(R) * vec_magn(V)), rt->figure[i].spec);
			}
		}
	}
	return (intense);
}
