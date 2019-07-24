/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:54:35 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/24 12:12:48 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <SDL_image.h>
# include <OpenCL/opencl.h>
# include "../libvec/libvec.h"

# define WINW 1000
# define WINH 1000
# define WINW_H WINW / 2
# define WINH_H WINH / 2
# define FOV (65 * (M_PI / 180))
# define RAD(x) (x * (M_PI / 180))
# define ABS(x) (x) > 0 ? (x) : -(x)
# define DROUND(d) ABS(d) < 0.00001 ? 0 : (d)
# define PPD 935

# define SPHERE 0
# define CONE 1
# define CYLINDER 2
# define PLANE 3
# define AMBIENT 0
# define POINT 1

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Texture		*fillscreen;
	SDL_Surface		*surf;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_light
{
	int				type;
	double			intense;
	t_vector3		pos;
	t_vector3		dir;
}					t_light;

typedef struct		s_ray
{
	t_vector3		pos;
	t_vector3		dir;
}					t_ray;

typedef struct		s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef	struct		s_cam
{
	t_vector3		pos;
	t_vector3		dir;
	t_vector3		rot;
	t_vector3		updir;
	t_vector3		ldir;
}					t_cam;

typedef	struct		s_figure
{
	int				type;
	t_vector3		pos;
	t_vector3		dir;
	t_vector3		v;
	t_color			color;
	double			radius;
	double			spec;
	double			angle;
}					t_figure;

typedef struct		s_rt
{
	t_cam			cam;
	t_sdl			sdl;
	t_light			*light;
	t_figure		*figure;
	t_vector3		p;
	t_vector3		x;
	t_vector3		r;
	t_vector3		l;
	t_vector3		v;
	t_vector3		n;
	t_vector3		rv;
	unsigned int	*color;
	int				boolean;
	int				run;
	double			*t;
	int				id;
	int				figure_count;
	t_figure		*closest_obj;
	int				objcount;
	int				lightcount;
}					t_rt;

int					main(int ac, char **av);
void				init(t_rt *rt);
void				init_sdl(t_rt *rt);
void				key(t_rt *rt);
void				update_screen(t_rt *rt);
void				memory_error(void);

t_color				trace_ray(t_rt *rt, t_ray r);
void				comp_ray(t_rt *rt, t_vector3 n, t_ray r, double t);
void				find_closest_intersection(t_rt *rt, t_ray r);
double				choose_closest_t(double a, double b, double d);
int					find_closest_obj(t_rt *rt);
void				choose_figure(t_rt *rt, t_ray r);

t_vector3			find_n_cone(t_ray r, t_vector3 pt, double t, t_figure cone);
double				find_t_cone(t_rt *rt, t_ray *r, t_figure cone);
double				calc_cone(t_rt *rt, t_ray r, int id);

t_vector3			find_n_sphere(t_ray r, double d, t_vector3 cent);
double				find_t_sphere(t_ray *r, t_figure sphere);
double				calc_sphere(t_rt *rt, t_ray r, int id);

t_vector3			find_n_cylinder(t_ray r, double t, t_figure cylinder);
double				find_t_cylinder(t_rt *rt, t_ray *r, t_figure cylinder);
double				calc_cylinder(t_rt *rt, t_ray r, int id);

t_vector3			find_n_plane(t_ray r, t_figure plane);
double				find_t_plane(t_ray *r, t_figure plane);
double				calc_plane(t_rt *rt, t_ray r, int id);

t_color				mult_color(t_color color, double i);
t_color				set_color(int r, int g, int b);

double				compute_light(t_rt *rt, t_vector3 p, t_vector3 n);
int					compute_shadow(t_rt *rt, t_ray ray, t_vector3 light_pos);
double				compute_shine(t_rt *rt, t_vector3 n, int i, double intense);

void				init_scene_1(t_rt *rt);
void				init_scene_2(t_rt *rt);
void				init_scene_3(t_rt *rt);
void				init_scene_3_1(t_rt *rt);
void				init_scene_4(t_rt *rt);
void				init_scene_4_1(t_rt *rt);
void				init_scene_5(t_rt *rt);
void				init_scene_5_1(t_rt *rt);
void				init_scene_6(t_rt *rt);
void				init_scene_6_1(t_rt *rt);
void				init_scene_7(t_rt *rt);
void				cylinder_7_2(t_rt *rt);
void				cylinder_7(t_rt *rt);

#endif
