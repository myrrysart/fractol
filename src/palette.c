/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                                /_\/ / /\ \ \   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:17:15 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/25 22:12:58 by art                       myrrys.art     */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static int	flame_color(int iteration)
{
	int	intensity;
	int	red;
	int	green;
	int	blue;

	intensity = (iteration * 255) / MAX_ITERATIONS;
	if (intensity < 85)
	{
		red = intensity * 2;
		green = 0;
		blue = intensity / 3;
	}
	else if (intensity < 170)
	{
		red = 255;
		green = (intensity - 85) * 2;
		blue = 0;
	}
	else
	{
		red = 255;
		green = 255;
		blue = (intensity - 170) * 3;
	}
	return ((red << 16) | (green << 8) | blue);
}

static int	classic_color(int iteration)
{
	int	intensity;
	int	blue;
	int	green;
	int	red;

	intensity = get_sin_intensity(iteration);
	blue = 128 + (intensity / 2);
	green = intensity / 3;
	if (intensity > 128)
		red = (intensity - 128) * 2;
	else
		red = 0;
	return ((red << 16) | (green << 8) | blue);
}

static int	pastel_color(int iteration)
{
	int	intensity;
	int	red;
	int	green;
	int	blue;

	intensity = get_sin_intensity(iteration);
	red = 180 + (intensity / 2);
	green = 150 + (intensity / 3);
	blue = 200 + (intensity / 2);
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

static int	noir_color(int iteration)
{
	int	intensity;
	int	red;
	int	green;
	int	blue;

	intensity = get_sin_intensity(iteration);
	if (intensity < 200)
	{
		red = intensity;
		green = intensity;
		blue = intensity;
	}
	else
	{
		red = 255;
		green = intensity / 4;
		blue = intensity / 4;
	}
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
}
