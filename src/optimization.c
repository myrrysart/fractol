/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:39:23 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/29 14:03:15 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static double	complex_distance(t_complex a, t_complex b)
{
	double	real_diff;
	double	imag_diff;

	real_diff = a.real - b.real;
	imag_diff = a.imag - b.imag;
	return (real_diff * real_diff + imag_diff * imag_diff);
}

static int	check_period_cycle(t_complex z, t_complex *history, int i)
{
	int	j;

	j = 1;
	while (j <= PERIOD_CHECK_LENGTH && j <= i)
	{
		if (complex_distance(z, history[(i - j) % PERIOD_CHECK_LENGTH]) < TOLERANCE)
			return (1);
		j++;
	}
	return (0);
}

int	iterations_with_period_detection(t_complex z_start, t_complex c)
{
	t_complex	z;
	t_complex	history[PERIOD_CHECK_LENGTH];
	int			i;
	double		temp_real;

	z = z_start;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (i);
		history[i % PERIOD_CHECK_LENGTH] = z;
		if (i > PERIOD_CHECK_START && i % PERIOD_CHECK_FREQ == 0)
		{
			if (check_period_cycle(z, history, i))
				return (MAX_ITERATIONS);
		}
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		i++;
	}
	return (MAX_ITERATIONS);
}
