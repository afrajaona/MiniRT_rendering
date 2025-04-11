/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:56 by nyrandri          #+#    #+#             */
/*   Updated: 2025/04/11 16:08:02 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		end;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_image	image;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef t_point	t_vector;

typedef struct s_cartesian_coordinate
{
	t_point	origine;
	int		i;
	int		j;
	int		k;
}	t_cartesian_coordinate;

typedef	struct s_ray
{
	t_vector	origin;
	t_vector	direction;
} t_ray;

typedef enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef	struct s_obj_attr
{
	int			hit;
	double		scalar;
	t_vector	normal;
	t_type		type;
} t_obj_attr;

typedef struct s_camera
{
	t_cartesian_coordinate	sys; // par rapport a la referentielle absolue
	double						fov;
	long long int			focal_distance;
	t_vector				normal;
}	t_camera;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_cartesian_coordinate	sys;
	t_color					color;
	double					brightness_ratio;
}	t_light;

typedef struct s_sphere
{
	t_cartesian_coordinate	sys;
	double					diametre;
	t_color					color;
}	t_sphere;

typedef struct s_spheres
{
	int			nb;
	int			index;
	t_sphere	*member;
} t_spheres;

typedef struct s_plane
{
	t_point		pt;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_planes
{
	int		nb;
	int		index;
	t_plane	*member;
} t_planes;

typedef struct s_cylindre
{
	t_vector	center;
	t_vector	normal;
	double		diametre;
	double		height;
	t_color		color;
}	t_cylindre;

typedef	struct s_cylindres
{
	int			nb;
	int			index;
	t_cylindre	*member;
} t_cylindres;

typedef	struct s_objects
{
	int			no_camera;
	int			no_light;
	int			no_ambient;
	t_ambient	ambient;
	t_camera 	camera;
	t_light		light;
	t_spheres	*spheres;
	t_cylindres	*cylindres;
	t_planes	*planes;
} t_objects;

typedef struct s_cyl_helper
{
	t_vector	cap_center;
	double		t;
	int			i;
}	t_cyl_helper;

#endif
