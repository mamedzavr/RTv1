#include "../includes/rt.h"

t_vector3		find_n_cylinder(t_ray r, double t, t_figure cylinder)
{
	double	m;
	t_vector3	n;
	t_vector3	p;

	m = vec_dot(r.dir, cylinder.v) * t
		+ vec_dot(vec_sub(r.pos, cylinder.pos), cylinder.v);
	p = vec_add(r.pos, vec_scale(r.dir, t));
	n = vec_norm(vec_sub(vec_sub(p, cylinder.pos), vec_scale(cylinder.v, m)));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double		find_t_cylinder(t_ray *r, t_figure cylinder)
{
	t_vector3	x;
	double		a;
	double		b;
	double		c;
	double		d;

	x = vec_sub(r->pos, cylinder.pos);
	a = vec_dot(r->dir, cylinder.v);
	a = vec_dot(r->dir, r->dir) - a * a;
	b = 2 * (vec_dot(r->dir, x) - vec_dot(r->dir, cylinder.v)
		* vec_dot(x, cylinder.v));
	c = vec_dot(x, cylinder.v);
	c = vec_dot(x, x) - c * c - cylinder.radius * cylinder.radius;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d = d < 0 ? -1 : choose_closest_t(a, b, d));
}

double		calc_cylinder(t_rt *rt, t_ray r, int id)
{
	double		t;
	t_figure	cylinder;

	cylinder = rt->figure[id];
	t = find_t_cylinder(&r, cylinder);
	return (t);
}
