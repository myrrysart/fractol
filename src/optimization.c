/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:39:23 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 15:10:09 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	period_refresh(int *period, t_complex *z_old, t_complex *z)
{
	*period += 1;
	if (*period > PERIOD_REFRESH_RATE_NUMBER)
	{
		*period = 0;
		*z_old = *z;
	}
	return (*period);
}

int	iterations_with_period_detection(t_complex z_start, t_complex c)
{
	t_complex	z;
	t_complex	z_old;
	int			i;
	int			period;
	double		temp_real;

	z = z_start;
	z_old.real = 0.0;
	z_old.imag = 0.0;
	period = 0;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (i);
		if (i > 0 && fabs(z.real - z_old.real) < TOLERANCE && fabs(z.imag
				- z_old.imag) < TOLERANCE)
			return (MAX_ITERATIONS);
		period_refresh(&period, &z_old, &z);
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		i++;
	}
	return (MAX_ITERATIONS);
}
