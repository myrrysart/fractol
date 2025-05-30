/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:33 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 10:51:52 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	init_coordinate_lookup(t_fractal_data *data)
{
	int		i;
	double	norm;

	i = 0;
	while (i < data->win_width)
	{
		norm = (i / (double)data->win_width) * 2.0 - 1.0;
		data->x_lookup[i] = norm * data->zoom + data->center_x;
		i++;
	}
	i = 0;
	while (i < data->win_height)
	{
		norm = 1.0 - (i / (double)data->win_height) * 2.0;
		data->y_lookup[i] = norm * data->zoom + data->center_y;
		i++;
	}
}

void	fill_pixel_block(t_fractal_data *data, int x, int y, unsigned int color)
{
	int	fill_size;
	int	offset;

	fill_size = 0;
	while (fill_size < data->skip_factor && y
		+ fill_size < data->win_height)
	{
		offset = 0;
		while (offset < data->skip_factor && x
			+ offset < data->win_width)
		{
			*(unsigned int *)(data->current_buffer + (y + fill_size)
					* data->line_len + (x + offset) * (data->bpp
						/ 8)) = color;
			offset++;
		}
		fill_size++;
	}
}
