/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:49:12 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:31:49 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void	fract_parser(double *frac_part, double *div, char *dec_pos)
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

static double	simple_atof(char *str)
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

static int	is_float_nbr(char *s)
{
	int	has_dot;
	int	has_digits;
	int	i;

	has_dot = 0;
	has_digits = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
			has_digits = 1;
		else
			return (0);
		i++;
	}
	return (has_digits);
}

static void	julia_init(int ac, char **av, t_fractal_data *data)
{
	if (ac != 4)
		show_usage_and_exit();
	if (!is_float_nbr(av[2]) || !is_float_nbr(av[3]))
		show_usage_and_exit();
	data->fractal_type = JULIA;
	data->julia_param.real = simple_atof(av[2]);
	data->julia_param.imag = simple_atof(av[3]);
	if (data->julia_param.real > 3.0 || data->julia_param.real < -3.0
		|| data->julia_param.imag > 3.0 || data->julia_param.imag < -3.0)
		show_usage_and_exit();
}

void	check_parameters(int ac, char **av, t_fractal_data *data)
{
	if (ac < 2)
		show_usage_and_exit();
	if (!ft_strncmp(av[1], "mandelbrot", 10) && ft_strlen(av[1]) == 10)
	{
		data->fractal_type = MANDELBROT;
		return ;
	}
	if (!ft_strncmp(av[1], "julia", 5) && ft_strlen(av[1]) == 5)
	{
		julia_init(ac, av, data);
		return ;
	}
	if (!ft_strncmp(av[1], "animation", 9) && ft_strlen(av[1]) == 9)
	{
		data->fractal_type = ANIMATION;
		return ;
	}
	if (!ft_strncmp(av[1], "burning_ship", 12) && ft_strlen(av[1]) == 12)
	{
		data->fractal_type = BURNING_SHIP;
		return ;
	}
	show_usage_and_exit();
}
