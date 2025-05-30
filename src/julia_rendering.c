/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:08:46 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 10:34:32 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	render_julia(t_fractal_data *data, int x, int y)
{
	t_complex		c;
	int				iterations;
	unsigned int	color;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			c.real = data->x_lookup[x];
			c.imag = data->y_lookup[y];
			iterations = iterations_with_period_detection(c, data->julia_param);
			color = data->color_map[iterations];
			fill_pixel_block(data, x, y, color);
			x += data->skip_factor;
		}
		y += data->skip_factor;
	}
}
