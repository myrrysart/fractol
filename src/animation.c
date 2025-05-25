/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                              /_\/ / /\ \ \   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:47:23 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/25 21:51:00 by art                       myrrys.art     */
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
	double			angle;

	data = (t_fractal_data *)generic_data;
	if (!(data->fractal_type == ANIMATION) || !data->animation_active)
		return (0);
	data->animation_index = (data->animation_index + 1) % MAX_ANIMATION_STEPS;
	angle = ((double)data->animation_index / MAX_ANIMATION_STEPS) * 2.0 * M_PI;
	data->julia_param.real = 0.7885 * cos(angle);
	data->julia_param.imag = 0.7885 * sin(angle);
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
