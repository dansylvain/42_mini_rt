# include "se_mini_struct_bonus.h"
# include "x_matrix_bonus.h"

#define ANGLE_NEWTON 3

void	generate_video_frames(t_data *data);
void	rotate_mesh(t_matrix_vector *vect, double angle, int axe[]);
void	trsl_mesh(t_cam *cam, t_matrix_vector *vect, double values[]);
double	*symmetrize_vector(double vect[]);
void	rotate_cam(t_cam *cam, double angle, int axe[]);
void	trsl_cam(t_cam *cam, t_matrix_vector *vect, double values[]);
void	trsl_about_cam(t_cam *cam, t_matrix_vector *vect, double values[]);

void	newton_move_spheres(t_data *data)
{
	int axe[3];
	int sphere_num = 0;
	int cylinder_nbr = 0;
	static double angle_sp0 = ANGLE_NEWTON;
	static double angle_sp1 = -ANGLE_NEWTON;
	t_sphere *sphere;
	t_cylinder	*cylinder;
	t_ray_vector point;
	static int i = 1;
	static int j = 1;
	static int k = 1;
	static int l = 1;
	printf("Newton's third law: For every action, there is an equal and opposite reaction.\n");
	
	// ROTATE SPHERES
	while (sphere_num < data->sp_nbr)
	{
		if (j < 23 && sphere_num == 0)
		{
			if ((i % 11) - 1 == 0)
				angle_sp0 = -angle_sp0;
			sphere = &data->spheres[sphere_num];
			point.axis[0] = 30;
			point.axis[1] = -50;
			point.axis[2] = 0;


			trsl_mesh(NULL, &sphere->origin_vect, point.axis);
			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
			rotate_mesh(&sphere->origin_vect, angle_sp0, axe);
			
			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &sphere->origin_vect, point.axis);

		}
		if (j >= 23 && sphere_num == 6)
		{
			if ((i % 11) - 1 == 0)
				angle_sp1 = -angle_sp1;
			sphere = &data->spheres[sphere_num];
			point.axis[0] = -30;
			point.axis[1] = -50;
			point.axis[2] = 0;


			trsl_mesh(NULL, &sphere->origin_vect, point.axis);
			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
	
			rotate_mesh(&sphere->origin_vect, angle_sp1, axe);
			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &sphere->origin_vect, point.axis);

		}
		sphere_num++;
		
	}

	while (cylinder_nbr < data->cy_nbr)
	{
		if (j < 23 && cylinder_nbr == 0)
		{
			cylinder = &data->cylinders[cylinder_nbr];
			point.axis[0] = 30;
			point.axis[1] = -50;
			point.axis[2] = 0;


			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
			rotate_mesh(&cylinder->origin_vect, angle_sp0, axe);

			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			// if ((i % 11) - 1 == 0)
			// 	angle_sp0 = -angle_sp0;
			// cylinder = &data->cylinders[cylinder_nbr];
			point.axis[0] = 30;
			point.axis[1] = -50;
			point.axis[2] = 0;

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);


			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
			rotate_mesh(&cylinder->axis_vect, angle_sp0, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
		}
		if (j >= 23 && cylinder_nbr == 6)
		{
			cylinder = &data->cylinders[cylinder_nbr];
			point.axis[0] = -30;
			point.axis[1] = -50;
			point.axis[2] = 0;


			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
			rotate_mesh(&cylinder->origin_vect, angle_sp1, axe);

			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			// if ((i % 11) - 1 == 0)
			// 	angle_sp0 = -angle_sp0;
			// cylinder = &data->cylinders[cylinder_nbr];
			point.axis[0] = -30;
			point.axis[1] = -50;
			point.axis[2] = 0;

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);


			axe[0] = 0;
			axe[1] = 0;
			axe[2] = 1;
			rotate_mesh(&cylinder->axis_vect, angle_sp1, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

		}
		cylinder_nbr++;
		
	}


	i++;
	j++;
	if (j == 45)
		j = 1;
	printf("i: %i\n", i);

}