/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_continued.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:17:48 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 10:18:19 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	classic_color(int iteration)
{
	int	blue;
	int	green;
	int	red;
	int	band;
	int	intensity;

	band = iteration % 32;
	intensity = (band * 255) / 32;
	if (intensity > 255)
		intensity = 255;
	blue = 128 + (intensity / 2);
	green = intensity / 3;
	red = (intensity * intensity) / 255;
	return ((red << 16) | (green << 8) | blue);
}

int	pastel_color(int iteration)
{
	int	red;
	int	green;
	int	blue;
	int	band;
	int	intensity;

	band = iteration % 16;
	intensity = (band * 255) / 16;
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

int	noir_color(int iteration)
{
	int	red;
	int	green;
	int	blue;
	int	band;
	int	intensity;

	band = iteration % 3;
	intensity = (band * 255) / 3;
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

int	psyaiai_color(int iteration)
{
	int	red;
	int	green;
	int	blue;

	red = (iteration * 5) % 255;
	green = (iteration * 9) % 255;
	blue = (iteration * 11) % 255;
	return ((red << 16) | (green << 8) | blue);
}
