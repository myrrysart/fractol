/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_rendering.c                                   /_\/ / /\ \ \   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:52:36 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/25 22:06:23 by art                       myrrys.art     */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	mandelbrot_iterations(t_complex c)
{
	t_complex	z;
	int			i;
	double		z_real_sq;
	double		z_imag_sq;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			return (i);
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		i++;
	}
	return (MAX_ITERATIONS);
}

void	render_mandelbrot(t_fractal_data *data, int x, int y)
{
	t_complex		c;
	int				iterations;
	unsigned int	color;
	int				offset;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			c.real = data->x_lookup[x];
			c.imag = data->y_lookup[y];
			iterations = mandelbrot_iterations(c);
			color = data->color_map[iterations];
			offset = y * data->line_len + x * (data->bpp / 8);
			*(unsigned int *)(data->current_buffer + offset) = color;
			x++;
		}
		y++;
	}
}
