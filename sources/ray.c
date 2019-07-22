#include "../includes/rt.h"

double		choose_closest_t(double a, double b, double d)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0.0003) || (t1 >= 0.0003 && t2 < 0.0003))
		return (t1);
	if ((t2 <= t1 && t2 >= 0.0003) || (t2 >= 0.0003 && t1 < 0.0003))
		return (t2);
	return (-1);
}

void		find_closest_intersection(t_rt *rt, t_ray r)
{
	int		i = -1;
	rt->closest_obj = NULL;

	while (++i < rt->objcount)
	{
		if (ft_strcmp(rt->figure[i].type, "sphere") == 0)
			rt->t[i] = calc_sphere(rt, r, i);
		else if (ft_strcmp(rt->figure[i].type, "cone") == 0)
			rt->t[i] = calc_cone(rt, r, i);
		else if (ft_strcmp(rt->figure[i].type, "cylinder") == 0)
			rt->t[i] = calc_cylinder(rt, r, i);
		else if (ft_strcmp(rt->figure[i].type, "plane") == 0)
			rt->t[i] = calc_plane(rt, r, i);
	}
}

int			find_closest_obj(t_rt *rt)
{
	int		id;
	int		i;

	id = -1;
	i = -1;
	while (++i < rt->objcount)
	{
		if (rt->t[i] >= 0 && (id == -1 || rt->t[i] < rt->t[id]))
			id = i;
	}
	return (id);
}

void		compute_ray(t_rt *rt, t_vector3 n, t_ray r, double t)
{
	if (rt->id == -1)
		return ;
	rt->n = vec_cpy(n);
	rt->p = vec_add(r.pos, vec_scale(r.dir, t));
}

t_color		trace_ray(t_rt *rt, t_ray r)
{
	int		i;
	t_color	current_color;
	t_vector3	pt;
	double		huy;


	i = -1;
	rt->id = -1;
	if (!(rt->t = (double*)malloc(sizeof(double) * rt->objcount)))
		memory_error();
	while (++i < rt->objcount)
	{
		rt->t[i] = INFINITY;
		find_closest_intersection(rt, r);
	}
	rt->id = find_closest_obj(rt);
	if (rt->id == -1)
		return ((t_color){0,0,0});
	if (ft_strcmp(rt->figure[rt->id].type, "sphere") == 0 && rt->t[rt->id] > 0)
		compute_ray(rt, find_n_sphere(r, rt->t[rt->id], rt->figure[rt->id].pos), r, rt->t[rt->id]);
	else if (ft_strcmp(rt->figure[rt->id].type, "cone") == 0)
	{
		pt = vec_add(r.pos, vec_scale(r.dir, rt->t[rt->id]));
		if (rt->t[rt->id] > 0)
		{
			compute_ray(rt, find_n_cone(r, pt, rt->t[rt->id], rt->figure[rt->id]), r, rt->t[rt->id]);
		}
	}
	else if (ft_strcmp(rt->figure[rt->id].type, "cylinder") == 0)
	{
		if (rt->t[rt->id] > 0)
			compute_ray(rt, find_n_cylinder(r, rt->t[rt->id], rt->figure[rt->id]), r, rt->t[rt->id]);
	}
	else if (ft_strcmp(rt->figure[rt->id].type, "plane") == 0)
	{
		if (rt->t[rt->id] > 0)
			compute_ray(rt, find_n_plane(r, rt->figure[rt->id]), r, rt->t[rt->id]);
	}
	int		id;
	id = rt->id;
	huy = compute_light(rt, rt->p, rt->n);
	current_color = mult_color(rt->figure[id].color, huy);
	free(rt->t);
	return (current_color);
}
