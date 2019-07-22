#include "../includes/rt.h"

int			compute_shadow(t_rt *rt, t_ray ray, t_vector3 light_pos)
{
	int		i;
	double	dist;

	dist = vec_magn(vec_sub(light_pos, ray.pos));
	i = -1;
	while (++i < rt->objcount)
	{
		rt->t[i] = INFINITY;
		find_closest_intersection(rt, ray);
	}
	rt->id = find_closest_obj(rt);
	if (rt->id < 0 || rt->t[rt->id] > dist)
		return (-1);
	return (dist);
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
		else if (ft_strcmp(rt->light[i].type, "point") == 0)
		{
			L = vec_sub(rt->light[i].pos, P);
			L = vec_norm(L);
			t_ray	r;
			r.pos = P;
			r.dir = L;
			n_dot_l = vec_dot(N, L);
			if (compute_shadow(rt, r, rt->light[i].pos) > 0)
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


// double		compute_light(t_rt *rt, t_vector3 P, t_vector3 N)
// {
// 	int			i;
// 	double		intense;
// 	t_vector3	L;
// 	double		n_dot_l;

// 	intense = 0.0;
// 	i = -1;
// 	while (++i < rt->lightcount)
// 	{
// 		if (ft_strcmp(rt->light[i].type, "ambient") == 0)
// 			intense += rt->light[i].intense;
// 		else if (ft_strcmp(rt->light[i].type, "point") == 0)
// 		{
// 			t_ray	r;
// 			L = vec_norm(vec_sub(rt->light[i].pos, P));
// 			r.dir = L;
// 			// P = vec_add(P, vec_scale(P, 0.0001));
// 			r.pos = P;
// 			n_dot_l = vec_dot(N, L);
// 			if (n_dot_l > 0 && compute_shadow(rt, r, rt->light[i].pos) != -1)
// 			{
// 				intense += rt->light[i].intense * n_dot_l;
// 				// continue ;
// 			}
// 			if (rt->figure[i].spec != -1)
// 			{
// 				t_vector3	R = vec_minus(vec_mult(N, 2 * vec_dot(N, L)), L);
// 				t_vector3	V = vec_mult(rt->cam.dir, -1);
// 				double		r_dot_v = vec_dot(R, V);
// 				r_dot_v = vec_dot(R, V);
// 				if (r_dot_v > 0)
// 					intense += rt->light[i].intense * pow(r_dot_v / (vec_magn(R) * vec_magn(V)), rt->figure[i].spec);
// 			}
// 			// find_closest_intersection(rt, r);
// 			// if (rt->closest_obj != NULL)
// 			// 	continue ;
// 		}
// 	}
// 	return (intense);
// }
