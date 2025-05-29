/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:35:22 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/29 17:24:11 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void	handle_movement(t_fractal_data *data, int *keycode)
{
	if (*keycode == LEFT_KEY)
	{
		data->center_x -= data->zoom * 0.1;
		update_and_display(data);
	}
	if (*keycode == RIGHT_KEY)
	{
		data->center_x += data->zoom * 0.1;
		update_and_display(data);
	}
	if (*keycode == UP_KEY)
	{
		data->center_y += data->zoom * 0.1;
		update_and_display(data);
	}
	if (*keycode == DOWN_KEY)
	{
		data->center_y -= data->zoom * 0.1;
		update_and_display(data);
	}
}

int	handle_key(int keycode, void *generic_data)
{
	t_fractal_data	*data;

	data = (t_fractal_data *)generic_data;
	if (keycode == ESC_KEY)
		cleanup(generic_data, 0);
	if (keycode == SPACE_KEY)
		if (data->fractal_type == ANIMATION)
			data->animation_active = !data->animation_active;
	handle_movement(data, &keycode);
	if (keycode == 99)
	{
		data->current_palette = (data->current_palette + 1) % NUM_OF_PALETTES;
		init_palette(data);
		update_and_display(data);
	}
	return (0);
}

int	handle_mouse(int keycode, int x, int y, void *generic_data)
{
	t_fractal_data	*data;

	data = (t_fractal_data *)generic_data;
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		data->zoom *= 0.9;
		update_and_display(data);
	}
	if (keycode == 5)
	{
		data->zoom *= 1.1;
		update_and_display(data);
	}
	return (0);
}
