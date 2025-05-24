/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:14:59 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/23 17:22:28 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int	handle_key(int keycode, void *generic_data);
int	handle_mouse(int keycode, int x, int y, void *generic_data);
int	main(int ac, char **av)
{
	t_fractal_data	data;

	(void)ac;
	(void)av;
	data.win_height = 1080 * 2;
	data.win_width = 1920 * 2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "fractol");
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop(data.mlx);
}

void	draw(char *pixels, t_fractal_data *data)
{
	unsigned int	color;
	int				y;
	int				x;
	int				offset;

	y = 0;
	color = 0x00FF0000;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			offset = y * data->line_len + x * (data->bpp / 8);
			*(unsigned int *)(pixels + offset) = color;
			x++;
		}
		y++;
	}
}

void	flicker_animation(void *generic_data)
{
	t_fractal_data	*data;
	void			*img;
	char			*pixels;

	data = (t_fractal_data *)generic_data;
	img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	pixels = mlx_get_data_addr(img, &data->bpp, &data->line_len, &data->endian);
	ft_printf("mlx data: %d bpp, %d line_len, %d endian", data->bpp, data->line_len, data->endian);
	draw(pixels, data);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	mlx_destroy_image(data->mlx, img);
}

void	cleanup(void *generic_data, int nbr)
{
	t_fractal_data *data;

	data = (t_fractal_data *)generic_data;
	mlx_destroy_window(data->mlx, data->win);
	exit(nbr);
}

int	handle_key(int keycode, void *generic_data)
{
	t_fractal_data	*data;

	data = (t_fractal_data *)generic_data;
	ft_printf("Key has been pressed:%d\n", keycode);
	if (keycode == ESC_KEY)
		cleanup(generic_data, 0);
	if (keycode == SPACE_KEY)
		cleanup(generic_data, 1);
	return (0);
}

int	handle_mouse(int keycode, int x, int y, void *generic_data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		ft_printf("Left click\n");
	if (keycode == 2)
		ft_printf("Middle click\n");
	if (keycode == 3)
	{
		flicker_animation(generic_data);
		ft_printf("Right click\n");
	}
	if (keycode == 4)
		ft_printf("scroll up\n");
	if (keycode == 5)
		ft_printf("scroll down\n");
	return (0);
}
