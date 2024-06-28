# include "se_mini_struct_bonus.h"
# include "x_matrix_bonus.h"

# define ANGLE_NEWTON 3

void	generate_video_frames(t_data *data);
void	rotate_mesh(t_matrix_vector *vect, double angle, int axe[]);
void	trsl_mesh(t_cam *cam, t_matrix_vector *vect, double values[]);
double	*symmetrize_vector(double vect[]);
void	rotate_cam(t_cam *cam, double angle, int axe[]);
void	trsl_cam(t_cam *cam, t_matrix_vector *vect, double values[]);
void	trsl_about_cam(t_cam *cam, t_matrix_vector *vect, double values[]);




void	engrenages(t_data *data)
{
	printf("The mechanics of cogs is a lot like life: if one tooth is out of place, everything grinds to a halt. Just like trying to enjoy a vacation with your in-laws.");

}