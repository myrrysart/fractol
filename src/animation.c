/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:08:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/27 18:50:59 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

t_complex	interpolate_complex(t_complex start, t_complex end, double t)
{
	t_complex	result;

	result.real = start.real + t * (end.real - start.real);
	result.imag = start.imag + t * (end.imag - start.imag);
	return (result);
}

int	animate_julia(void *generic_data)
{
	t_fractal_data	*data;
	int				skip;
	int				linear_index;
	int				x;
	int				y;

	data = (t_fractal_data *)generic_data;
	if (!(data->fractal_type == ANIMATION) || !data->animation_active)
		return (0);
	skip = 5;
	linear_index = data->animation_index * skip;
	x = linear_index % data->win_width;
	y = linear_index / data->win_width;
	data->julia_param = pixel_to_complex(x, y, data);
	data->animation_timer += 0.01;
	if (data->animation_timer > 0.02)
	{
		data->animation_index = (data->animation_index + 1) % (data->win_width
				* data->win_height);
		data->animation_timer = 0.0;
	}
	update_and_display(data);
	return (0);
}
