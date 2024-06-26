# include "se_mini_struct_bonus.h"
# include "x_matrix_bonus.h"

#define ANGLE_NEWTON 1

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
	// printf("The first rule of Fight Club is: you don't talk about Fight Club\n");
	
	// ROTATE SPHERES
	while (sphere_num < data->sp_nbr)
	{
		if (j < 61 && sphere_num == 0)
		{
			if ((i % 30) - 1 == 0)
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
		if (j >= 61 && sphere_num == 6)
		{
			if ((i % 30) - 1 == 0)
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
		if (j < 61 && cylinder_nbr == 0)
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

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			rotate_mesh(&cylinder->axis_vect, angle_sp0, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
		}
		if (j >= 61 && cylinder_nbr == 6)
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

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			rotate_mesh(&cylinder->axis_vect, angle_sp1, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
		}
		if (j < 61 && (cylinder_nbr == 7 || cylinder_nbr == 8))
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

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			rotate_mesh(&cylinder->axis_vect, angle_sp0, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
		}
		if (j >= 61 && (cylinder_nbr == 19 || cylinder_nbr == 20))
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

			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);

			rotate_mesh(&cylinder->axis_vect, angle_sp1, axe);


			symmetrize_vector(point.axis);
			trsl_mesh(NULL, &cylinder->origin_vect, point.axis);
		}
		cylinder_nbr++;	
	}



	static double angle = 1;

	t_cam *cam = &data->cam;
	t_matrix_vector pointm;

	pointm.axis[0] = 0;
	pointm.axis[1] = 0;
	pointm.axis[2] = 120;
	
	trsl_cam(cam, &pointm, pointm.axis);
	axe[0] = 0;
	axe[1] = 1;
	axe[2] = 0;
	rotate_cam(cam, angle, axe);
	symmetrize_vector(pointm.axis);
	trsl_cam(cam, &pointm, pointm.axis);



	i++;
	j++;
	printf("i: %i, j: %i\n", i, j);

	if (j == 121)
		j = 1;
}