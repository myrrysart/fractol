/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:00:45 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:01:00 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	show_usage_and_exit(void)
{
	ft_printf("Usage: './fractol' followed by one of these:\n");
	ft_printf("mandelbrot\n");
	ft_printf("julia [float] [float]\n");
	ft_printf("burning_ship");
	ft_printf("animation\n");
	exit(0);
}
