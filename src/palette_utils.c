/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:09:18 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/27 18:09:23 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	get_sin_intensity(int iteration)
{
	double	normalized;
	double	sin_value;

	normalized = (double)iteration / MAX_ITERATIONS;
	sin_value = sin(normalized * M_PI / 2);
	return ((int)(sin_value * 255));
}

void	fill_color_map(t_fractal_data *data, int (*color_func)(int), int bg)
{
	int	i;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		if (i == MAX_ITERATIONS)
			data->color_map[i] = bg;
		else
			data->color_map[i] = color_func(i);
		i++;
	}
}
