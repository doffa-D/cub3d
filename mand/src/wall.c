/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:29 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/20 14:47:54 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	background(t_struct *cub)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT / 2)
		{
			mlx_put_pixel(cub->image, x, y, genirat_pixel(cub->up[0], \
				cub->up[1], cub->up[2], 200));
		}
	}
	x = -1;
	while (++x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_pixel(cub->image, x, y, genirat_pixel(cub->down[0], \
				cub->down[1], cub->down[2], 200));
			y++;
		}
	}
}

void	wall3d(t_struct *cub)
{
	t_wall_3d	var_3d_wall;
	int			i;
	int			j;

	background(cub);
	i = -1;
	while (++i < NUM_RAYS)
	{
		instialation_varables(cub, &var_3d_wall, i);
		j = 0;
		while (j < var_3d_wall.final_dist && j < HEIGHT)
		{
			horz_img(cub, var_3d_wall, i, j);
			verical_img(cub, var_3d_wall, i, j);
			var_3d_wall.y_pixel_cordinate += var_3d_wall.px_img_px_wind;
			j++;
		}
	}
}
