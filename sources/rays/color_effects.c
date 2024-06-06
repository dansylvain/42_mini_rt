double	calculate_light_attenuation(t_ray *light_ray, double intensity)
{
	double			light_mag;
	const double	kc = 0.5;
	const double	kl = 45e-4;
	const double	kq = 75e-25;

	light_mag = get_vector_magnitude(light_ray->dir_vect.axis);
	return (intensity / (kc + kl * light_mag + kq * light_mag * light_mag));
}

double aces_tonemap(double x) {
    double a = 2.51;
    double b = 0.03;
    double c = 2.43;
    double d = 0.59;
    double e = 0.14;
    
    return (x * (a * x + b)) / (x * (c * x + d) + e);
}

void	apply_aces_tonemap(t_color *color)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		color->rgb[i] = aces_tonemap(color->rgb[i] / 255.0f) * 255;
	clamp_255(color);
}