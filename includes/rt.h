#ifndef FT_RTV1_H
# define FT_RTV1_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <SDL_image.h>
# include <OpenCL/opencl.h>
# include "../libvec/libvec.h"

// # define WINW 200
// # define WINH 200
# define WINW 1000
# define WINH 1000
# define HALF_WINW WINW / 2
# define HALF_WINH WINH / 2
# define VIEW_W 1
# define VIEW_H 1
# define FOV (60 * (M_PI / 180))
# define RAD(x) (x * (M_PI / 180))
# define MAX(x, y) ((x < y) ? y : x;)
# define ABS(x) (x) > 0 ? (x) : -(x)
# define DROUND(d) ABS(d) < 0.00001 ? 0 : (d)

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
	char			*type;
	double			intense;
	t_vector3		pos;
	t_vector3		dir;
}					t_light;

typedef struct		s_ray
{
	t_vector3		pos;
	t_vector3		dir;
	double			*t;
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
}					t_cam;

typedef	struct		s_view
{
	t_vector3		pos;
}					t_view;

typedef	struct		s_figure
{
	char			*type;
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
	t_view			view;
	t_sdl			sdl;
	t_light			*light;
	t_figure		*figure;
	t_vector3		p;
	t_vector3		r;
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

int 				main(int ac, char **av);
void				init(t_rt *rt);
void				init_sdl(t_rt *rt);
void				key(t_rt *rt);
void				update_screen(t_rt *rt);
void				canvas_to_viewport(t_rt *rt, int x, int y);
void				memory_error(void);


t_color				trace_ray(t_rt *rt, t_ray r);
void				compute_ray(t_rt *rt, t_vector3 n, t_ray r, double t);
void				find_closest_intersection(t_rt *rt, t_ray r);
double				choose_closest_t(double a, double b, double d);
int					find_closest_obj(t_rt *rt);

t_vector3			find_n_cone(t_ray r, t_vector3 pt, double t, t_figure cone);
double				fint_t_cone(t_ray *r, t_figure cone);
double				calc_cone(t_rt *rt, t_ray r, int id);

t_vector3			find_n_sphere(t_ray r, double d, t_vector3 cent);
double				find_t_sphere(t_ray *r, t_figure sphere);
double				calc_sphere(t_rt *rt, t_ray r, int id);

t_vector3			find_n_cylinder(t_ray r, double t, t_figure cylinder);
double				find_t_cylinder(t_ray *r, t_figure cylinder);
double				calc_cylinder(t_rt *rt, t_ray r, int id);

t_vector3			find_n_plane(t_ray r, t_figure plane);
double				find_t_plane(t_ray *r, t_figure plane);
double				calc_plane(t_rt *rt, t_ray r, int id);

t_color				mult_color(t_color color, double i);
t_color				set_color(int r, int g, int b);

double				compute_light(t_rt *rt, t_vector3 P, t_vector3 N);
int					compute_shadow(t_rt *rt, t_ray ray, t_vector3 light_pos);

#endif
