/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:41:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:03 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	vertical_horizontal(t_struct *cub)
{
	int	x;
	int	i;

	x = -1;
	while (++x <= cub->WINDOW_WIDTH)
	{
		i = -1;
		while (++i < cub->WINDOW_HEIGHT * TILE_SIZE * MINI_MAP)
			mlx_put_pixel(cub->image, (x * TILE_SIZE * MINI_MAP), i,
				0xFFFFFFFF);
	}
	x = -1;
	while (++x <= cub->WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < cub->WINDOW_WIDTH * TILE_SIZE * MINI_MAP)
			mlx_put_pixel(cub->image, i, (x * TILE_SIZE * MINI_MAP),
				0xFFFFFFFF);
	}
}

void	draw_wall(t_struct *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE * MINI_MAP)
	{
		j = 0;
		while (j < TILE_SIZE * MINI_MAP)
		{
			mlx_put_pixel(cub->image, (x * TILE_SIZE * MINI_MAP) + i, (y
					* TILE_SIZE * MINI_MAP) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_windows(t_struct *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->close_dor % 2 == 0 && cub->map[y][x] == 'D'
				&& cub->map[(int)floor(cub->player.y / (TILE_SIZE
						* MINI_MAP))][(int)floor(cub->player.x / (TILE_SIZE
						* MINI_MAP))] != 'D')
				draw_wall(cub, x, y, 0x800080FF);
			if (cub->map[y][x] == '1')
			{
				draw_wall(cub, x, y, 0x800080FF);
			}
			x++;
		}
		y++;
	}
	vertical_horizontal(cub);
}
