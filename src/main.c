/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:08:54 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:43:23 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

static void	init_fractal_view(t_fractal_data *data);
void		cleanup(t_fractal_data *data, int nbr);
int			close_window(t_fractal_data *data);

int	main(int ac, char **av)
{
	t_fractal_data	data;

	check_parameters(ac, av, &data);
	data.win_height = MAX_WIN_HEIGHT;
	data.win_width = MAX_WIN_WIDTH;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
			"fractol");
	init_palette(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop_hook(data.mlx, animate_julia, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	data.buffer1 = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img_data1 = mlx_get_data_addr(data.buffer1, &data.bpp, &data.line_len,
			&data.endian);
	data.buffer2 = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img_data2 = mlx_get_data_addr(data.buffer2, &data.bpp, &data.line_len,
			&data.endian);
	data.current_image = data.buffer1;
	data.current_buffer = data.img_data1;
	init_fractal_view(&data);
	update_and_display(&data);
	mlx_loop(data.mlx);
	cleanup(&data, 0);
}

void	cleanup(t_fractal_data *data, int nbr)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(nbr);
}

static void	init_fractal_view(t_fractal_data *data)
{
	data->current_palette = 0;
	data->animation_active = 1;
	data->animation_index = 0;
	data->animation_timer = 0.0;
	if (data->fractal_type == MANDELBROT)
		data->center_x = -0.8;
	else if (data->fractal_type == BURNING_SHIP)
		data->center_x = -1.8;
	else
		data->center_x = 0.0;
	data->center_y = 0.0;
	data->zoom = 1.6;
	data->low_res_mode = 0;
	data->skip_factor = 1;
}

int	close_window(t_fractal_data *data)
{
	cleanup(data, 0);
	return (0);
}
