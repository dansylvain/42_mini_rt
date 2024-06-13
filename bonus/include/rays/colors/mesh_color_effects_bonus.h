#ifndef MESH_COLOR_EFFECTS_BONUS_H
# define MESH_COLOR_EFFECTS_BONUS_H

# include "se_mini_struct_bonus.h"
# include "x_linear_algebra_bonus.h"

double	calculate_light_attenuation(t_ray_pack *light_ray, double intensity);
double	calculate_light_reflexion(t_ray *ray, t_ray_pack *light_ray,
	t_ray_vector *normal);

#endif