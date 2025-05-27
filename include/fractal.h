/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:18:11 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/27 18:49:31 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <mlx.h>
# include <libft.h>
//sin and pi
# include <math.h>

//Keycodes
# define ESC_KEY 65307
# define SPACE_KEY 32
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
//math definitions
# define MAX_ITERATIONS 100
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT	1080
# define NUM_OF_PALETTES 4


typedef enum	e_fractal_type
{
	MANDELBROT,
	JULIA,
	ANIMATION
}	t_fractal_type;

typedef struct	s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct	s_fractal_data
{
	int				bpp;
	int				line_len;
	int				endian;
	int				win_height;
	int				win_width;
	int				animation_active;
	int				animation_index;
	int				current_palette;
	t_fractal_type	fractal_type;
	unsigned int	color_map[MAX_ITERATIONS + 1];
	char			*img_data1;
	char			*img_data2;
	void			*mlx;
	void			*win;
	void			*buffer1;
	void			*buffer2;
	void			*current_image;
	char			*current_buffer;
	double			animation_timer;
	double			center_x;
	double			center_y;
	double			zoom;
	double			width_scale;
	double			height_scale;
	t_complex		julia_param;
	double			x_lookup[MAX_WIN_WIDTH];
	double			y_lookup[MAX_WIN_HEIGHT];
}	t_fractal_data;
void	init_palette(t_fractal_data *data);
int		handle_mouse(int keycode, int x, int y, void *generic_data);
int		handle_key(int keycode, void *generic_data);
void	check_parameters(int ac, char **av, t_fractal_data *data);
int		animate_julia(void *generic_data);
void	update_and_display(t_fractal_data *data);
t_complex	pixel_to_complex(int x, int y, t_fractal_data *data);
void	init_coordinate_lookup(t_fractal_data *data);
void	render_julia(t_fractal_data *data);
void	render_mandelbrot(t_fractal_data *data);
void	cleanup(t_fractal_data *data, int nbr);
#endif
