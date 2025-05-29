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
void	toggle_quality_mode(t_fractal_data *data)
{
	data->low_res_mode = !data->low_res_mode;
	if (data->low_res_mode)
		data->skip_factor = 8;
	else
		data->skip_factor = 1;
}

int	handle_key(int keycode, void *generic_data)
{
	t_fractal_data	*data;

	data = (t_fractal_data *)generic_data;
	if (keycode == ESC_KEY)
		cleanup(generic_data, 0);
	if (keycode == 118)
		toggle_quality_mode(data);
	if (keycode == 98 && data->low_res_mode)
	{
		data->skip_factor = 1;
		update_and_display(data);
		data->skip_factor = 8;
	}
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
	double			mouse_real;
	double			mouse_imag;
	double			zoom_factor;

	data = (t_fractal_data *)generic_data;
	mouse_real = ((x / (double)data->win_width) * 2.0 - 1.0) * data->zoom + data->center_x;
	mouse_imag = (1.0 - (y / (double)data->win_height) * 2.0) * data->zoom + data->center_y;
	
	if (keycode == 4)
		zoom_factor = 0.9;
	else if (keycode == 5)
		zoom_factor = 1.1;
	else
		return (0);
	
	data->center_x = mouse_real + (data->center_x - mouse_real) * zoom_factor;
	data->center_y = mouse_imag + (data->center_y - mouse_imag) * zoom_factor;
	data->zoom *= zoom_factor;
	update_and_display(data);
	return (0);
}
