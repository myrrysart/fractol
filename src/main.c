/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:14:59 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/23 01:43:40 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	main(int ac, char **av)
{
	void *mlx;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	mlx_new_window(mlx, 1000, 1000, "Hello world");
	while (1)
		mlx_loop(mlx);
}

