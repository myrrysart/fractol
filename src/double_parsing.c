/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:49:12 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/27 18:31:53 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	fract_parser(double *frac_part, double *div, char *dec_pos)
{
	int	i;

	i = 1;
	if (dec_pos)
	{
		*dec_pos = '.';
		while (dec_pos[i])
		{
			*frac_part += (dec_pos[i] - '0') / *div;
			*div *= 10.0;
			i++;
		}
	}
}

double	simple_atof(char *str)
{
	int		sign;
	int		integer_part;
	double	fractional_part;
	double	divisor;
	char	*decimal_pos;

	sign = 1;
	fractional_part = 0.0;
	divisor = 10.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	decimal_pos = ft_strchr(str, '.');
	if (decimal_pos)
		*decimal_pos = '\0';
	integer_part = ft_atoi(str);
	fract_parser(&fractional_part, &divisor, decimal_pos);
	return (sign * (integer_part + fractional_part));
}

void	show_usage_and_exit(void)
{
	ft_printf("Usage: './fractol' followed by one of these:\n");
	ft_printf("mandelbrot\n");
	ft_printf("julia [number] [number]\n");
	ft_printf("animation\n");
	exit(0);
}

void	check_parameters(int ac, char **av, t_fractal_data *data)
{
	if (ac < 2)
		show_usage_and_exit();
	if (!ft_strncmp(av[1], "mandelbrot", 10))
	{
		data->fractal_type = MANDELBROT;
		return ;
	}
	if (!ft_strncmp(av[1], "julia", 5))
	{
		if (ac != 4)
			show_usage_and_exit();
		data->fractal_type = JULIA;
		data->julia_param.real = simple_atof(av[2]);
		data->julia_param.imag = simple_atof(av[3]);
		return ;
	}
	if (!ft_strncmp(av[1], "animation", 9))
	{
		data->fractal_type = ANIMATION;
		return ;
	}
	show_usage_and_exit();
}
