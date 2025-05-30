/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:12 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 10:51:20 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	flame_color_math(int intensity, int *red, int *green, int *blue)
{
	if (intensity < 85)
	{
		*red = intensity * 2;
		*green = 0;
		*blue = intensity / 3;
	}
	else if (intensity < 170)
	{
		*red = 255;
		*green = (intensity - 85) * 2;
		*blue = 0;
	}
	else
	{
		*red = 255;
		*green = 255;
		*blue = (intensity - 170) * 3;
	}
}

static int	flame_color(int iteration)
{
	int	red;
	int	green;
	int	blue;
	int	band;
	int	intensity;

	band = iteration % 8;
	intensity = (band * 255) / 8;
	flame_color_math(intensity, &red, &green, &blue);
	return ((red << 16) | (green << 8) | blue);
}

void	init_palette(t_fractal_data *data)
{
	if (data->current_palette == 0)
		fill_color_map(data, classic_color, 0x00000000);
	if (data->current_palette == 1)
		fill_color_map(data, flame_color, 0x000000);
	if (data->current_palette == 2)
		fill_color_map(data, pastel_color, 0x2C2C2C);
	if (data->current_palette == 3)
		fill_color_map(data, noir_color, 0x000000);
	if (data->current_palette == 4)
		fill_color_map(data, psyaiai_color, 0x000000);
}
