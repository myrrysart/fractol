/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_rendering.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:05 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 10:44:36 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	render_mandelbrot(t_fractal_data *data, int x, int y)
{
	t_complex		c;
	int				iterations;
	unsigned int	color;
	int				offset;
	int				fill_size;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			c.real = data->x_lookup[x];
			c.imag = data->y_lookup[y];
			iterations = iterations_with_period_detection((t_complex){0.0, 0.0}, c);
			color = data->color_map[iterations];
			fill_size = 0;
			while (fill_size < data->skip_factor && y + fill_size < data->win_height)
			{
				offset = 0;
				while (offset < data->skip_factor && x + offset < data->win_width)
				{
					*(unsigned int *)(data->current_buffer +
						(y + fill_size) * data->line_len +
						(x + offset) * (data->bpp / 8)) = color;
					offset++;
				}
				fill_size++;
			}
			x += data->skip_factor;
		}
		y += data->skip_factor;
	}
}
