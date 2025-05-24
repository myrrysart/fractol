/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:09:04 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/23 16:20:26 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    FRACTAL_H
# define    FRACTAL_H
# include <mlx.h>
# include <libft.h>
# define ESC_KEY 65307
# define SPACE_KEY 32

typedef struct	s_fractal_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_height;
	int		win_width;
}	t_fractal_data;

#endif
