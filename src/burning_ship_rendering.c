/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_rendering.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:09:40 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:08:39 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	render_ship_math(t_fractal_data *data, int x, int y)
{
	t_complex		c;
	t_complex		z;
	double			temp_real;
	int				iterations;

	c.real = data->x_lookup[x];
	c.imag = -data->y_lookup[y];
	z.real = 0.0;
	z.imag = 0.0;
	iterations = 0;
	while (iterations < MAX_ITERATIONS && z.real * z.real + z.imag
		* z.imag <= 4.0)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = fabs(2.0 * z.real * z.imag) + c.imag;
		z.real = fabs(temp_real);
		iterations++;
	}
	return (iterations);
}

void	render_ship(t_fractal_data *data, int x, int y)
{
	int				iterations;
	unsigned int	color;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			iterations = render_ship_math(data, x, y);
			color = data->color_map[iterations];
			fill_pixel_block(data, x, y, color);
			x += data->skip_factor;
		}
		y += data->skip_factor;
	}
}
