#include "../includes/rt.h"

t_color		set_color(int r, int g, int b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color		mult_color(t_color color, double i)
{
	t_color		r;
	r.r = color.r * i;
	r.g = color.g * i;
	r.b = color.b * i;
	return (r);
}
