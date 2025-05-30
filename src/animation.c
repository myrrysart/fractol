/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:08:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 13:26:41 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	animate_julia(void *generic_data)
{
	t_fractal_data	*data;
	double			angle;

	data = (t_fractal_data *)generic_data;
	if (!(data->fractal_type == ANIMATION) || !data->animation_active)
		return (0);
	data->animation_index = (data->animation_index + 1) % MAX_ANIMATION_STEPS;
	angle = ((double)data->animation_index / MAX_ANIMATION_STEPS) * 2.0 * M_PI;
	data->julia_param.real = JULIA_RADIUS * cos(angle);
	data->julia_param.imag = JULIA_RADIUS * sin(angle);
	update_and_display(data);
	return (0);
}
