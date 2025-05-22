/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:09:04 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/23 01:42:26 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    FRACTAL_H
# define    FRACTAL_H
# include <mlx.h>
# include <libft.h>

typedef struct	s_fractal_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fractal_data;

#endif
