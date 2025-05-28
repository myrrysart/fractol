/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:33 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/28 18:24:48 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	init_coordinate_lookup(t_fractal_data *data)
{
	int	i;
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

t_complex	pixel_to_complex(int x, int y, t_fractal_data *data)
{
	t_complex	c;
	double		norm_x;
	double		norm_y;

	norm_x = (x / (double)data->win_width) * 2.0 - 1.0;
	norm_y = (y / (double)data->win_height) * 2.0 - 1.0;
	c.real = norm_x * data->zoom + data->center_x;
	c.imag = norm_y * data->zoom + data->center_y;
	return (c);
}
