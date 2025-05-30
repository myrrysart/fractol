/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:18:11 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/30 11:01:22 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <libft.h>
# include <mlx.h>
// sin and pi
# include <math.h>

// Keycodes
# define ESC_KEY 65307
# define SPACE_KEY 32
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364

// math definitions
# define MAX_ANIMATION_STEPS 1500
# define MAX_ITERATIONS 4000
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1920
# define PERIOD_CHECK_LENGTH 2
# define PERIOD_CHECK_START 450
# define PERIOD_CHECK_FREQ 5
# define TOLERANCE 1e-14

// colors
# define NUM_OF_PALETTES 5

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	ANIMATION,
	BURNING_SHIP
}	t_fractal_type;

typedef struct s_complex
{
	double			real;
	double			imag;
}	t_complex;

typedef struct s_fractal_data
{
	int				bpp;
	int				line_len;
	int				endian;
	int				win_height;
	int				win_width;
	int				animation_active;
	int				animation_index;
	int				current_palette;
	int				low_res_mode;
	int				skip_factor;
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

// animation
int					animate_julia(void *generic_data);

// rendering utilities
void				init_coordinate_lookup(t_fractal_data *data);
int					iterations_with_period_detection(t_complex z_start,
						t_complex c);

// palette
void				init_palette(t_fractal_data *data);
int					classic_color(int iteration);
int					pastel_color(int iteration);
int					noir_color(int iteration);
int					psyaiai_color(int iteration);
// handle_input
int					handle_mouse(int keycode, int x, int y, void *generic_data);
int					handle_key(int keycode, void *generic_data);

// parameter parsing
void				check_parameters(int ac, char **av, t_fractal_data *data);
void				show_usage_and_exit(void);

//
void				cleanup(t_fractal_data *data, int nbr);
// rendering
void				update_and_display(t_fractal_data *data);
void				render_julia(t_fractal_data *data, int x, int y);
void				render_mandelbrot(t_fractal_data *data, int x, int y);
void				render_ship(t_fractal_data *data, int x, int y);
int					get_sin_intensity(int iteration);
void				fill_color_map(t_fractal_data *data, int (*color_func)(int),
						int bg);
void				fill_pixel_block(t_fractal_data *data, int x, int y,
						unsigned int color);
#endif
