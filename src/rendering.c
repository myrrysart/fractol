/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:28 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 09:13:53 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	swap_buffers(t_fractal_data *data)
{
	if (data->current_buffer == data->img_data1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->buffer1, 0, 0);
		data->current_buffer = data->img_data2;
		data->current_image = data->buffer2;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->buffer2, 0, 0);
		data->current_buffer = data->img_data1;
		data->current_image = data->buffer1;
	}
}

void	update_and_display(t_fractal_data *data)
{
	init_coordinate_lookup(data);
	if (data->fractal_type == MANDELBROT)
		render_mandelbrot(data, 0, 0);
	else if (data->fractal_type == JULIA)
		render_julia(data, 0, 0);
	else if (data->fractal_type == ANIMATION)
		render_julia(data, 0, 0);
	else if (data->fractal_type == BURNING_SHIP)
		render_julia(data, 0, 0);
	swap_buffers(data);
}
