/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:17:15 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/25 03:19:54 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void	init_classic_palette(t_fractal_data *data)
{
	int	i;
	int	intensity;
	int	blue;
	int	green;
	int	red;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		if (i == MAX_ITERATIONS)
		{
			data->color_map[i] = 0x00000000;
		}
		else
		{
			intensity = (i * 255) / MAX_ITERATIONS;
			blue = 128 + (intensity / 2);
			green = intensity / 3;
			if (intensity > 128)
				red = (intensity - 128) * 2;
			else
				red = 0;
			data->color_map[i] = (red << 16) | (green << 8) | blue;
		}
		i++;
	}
}

static void	init_flame_palette(t_fractal_data *data)
{
	int	i;
	int	intensity;
	int	red;
	int	green;
	int	blue;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		if (i == MAX_ITERATIONS)
			data->color_map[i] = 0x000000;
		else
		{
			intensity = (i * 255) / MAX_ITERATIONS;
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
			data->color_map[i] = (red << 16) | (green << 8) | blue;
		}
		i++;
	}
}

static void	init_pastel_palette(t_fractal_data *data)
{
	int	i;
	int	intensity;
	int	red;
	int	blue;
	int	green;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		if (i == MAX_ITERATIONS)
			data->color_map[i] = 0x2C2C2C;
		else
		{
			intensity = (i * 255) / MAX_ITERATIONS;
			red = 180 + (intensity / 4);
			green = 150 + (intensity / 6);
			blue = 200 + (intensity / 5);
			if (red > 255)
				red = 255;
			if (green > 255)
				green = 255;
			if (blue > 255)
				blue = 255;
			data->color_map[i] = (red << 16) | (green << 8) | blue;
		}
		i++;
	}
}

static void	init_noir_palette(t_fractal_data *data)
{
	int	i;
	int	intensity;
	int	red;
	int	green;
	int	blue;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		if (i == MAX_ITERATIONS)
			data->color_map[i] = 0x000000;
		else
		{
			intensity = (i * 255) / MAX_ITERATIONS;
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
			data->color_map[i] = (red << 16) | (green << 8) | blue;
		}
		i++;
	}
}

void	init_palette(t_fractal_data *data)
{
	if (data->current_palette == 0)
		init_classic_palette(data);
	if (data->current_palette == 1)
		init_flame_palette(data);
	if (data->current_palette == 2)
		init_pastel_palette(data);
	if (data->current_palette == 3)
		init_noir_palette(data);
}
