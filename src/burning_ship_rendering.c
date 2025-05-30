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
void	render_burning_ship(t_fractal_data *data, int y, int x)
{
	t_complex		c;
	t_complex		z;
	int				iterations;
	unsigned int	color;
	int				offset;
	double			temp_real;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			c.real = data->x_lookup[x];
			c.imag = data->y_lookup[y];
			z.real = 0.0;
			z.imag = 0.0;
			iterations = 0;
			while (iterations < MAX_ITERATIONS && 
				   z.real * z.real + z.imag * z.imag <= 4.0)
			{
				temp_real = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = -2.0 * fabs(z.real * z.imag) + c.imag;
				z.real = temp_real;
				iterations++;
			}
			color = data->color_map[iterations];
			offset = y * data->line_len + x * (data->bpp / 8);
			*(unsigned int *)(data->current_buffer + offset) = color;
			x += data->skip_factor;
		}
		y += data->skip_factor;
	}
}
