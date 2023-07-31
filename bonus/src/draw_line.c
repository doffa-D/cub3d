/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:43:15 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/20 19:51:34 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	point_wall_and_dor_open(t_struct *cub)
{
	if (cub->map[cub->line.checky / (int)(TILE_SIZE * MINI_MAP)]
		&& cub->map[(int)cub->line.y / (int)(TILE_SIZE * MINI_MAP)]
		&& cub->map[cub->line.checky / (int)(TILE_SIZE
			* MINI_MAP)][(int)cub->line.x / (int)(TILE_SIZE * MINI_MAP)] == '1'
		&& cub->map[(int)cub->line.y / (int)(TILE_SIZE
			* MINI_MAP)][cub->line.checkx / (int)(TILE_SIZE * MINI_MAP)] == '1')
		return (1);
	cub->line.checkx = cub->line.x;
	cub->line.checky = cub->line.y;
	if (cub->map[(int)(cub->line.y / (TILE_SIZE * MINI_MAP))]
		&& cub->map[(int)(cub->line.y / (TILE_SIZE
				* MINI_MAP))][(int)(cub->line.x / (TILE_SIZE
				* MINI_MAP))] == 'D')
	{
		cub->line.dor_x = (cub->line.x / (TILE_SIZE * MINI_MAP));
		cub->line.dor_y = (cub->line.y / (TILE_SIZE * MINI_MAP));
		return (1);
	}
	return (0);
}

int	point(t_struct *cub)
{
	if (point_wall_and_dor_open(cub))
		return (1);
	else if (cub->map[(int)(cub->line.y / (TILE_SIZE * MINI_MAP))]
			&& cub->map[(int)(cub->line.y / (TILE_SIZE
					* MINI_MAP))][(int)(cub->line.x / (TILE_SIZE
					* MINI_MAP))] == '5')
	{
		cub->line.dor_x = (cub->line.x / (TILE_SIZE * MINI_MAP));
		cub->line.dor_y = (cub->line.y / (TILE_SIZE * MINI_MAP));
		return (2);
	}
	return (0);
}

void	inisalation(t_struct *cub, int end_point_x, int end_point_y)
{
	cub->line.dx = end_point_x - cub->player.x;
	cub->line.dy = end_point_y - cub->player.y;
	cub->line.steps = abs(cub->line.dy);
	if (abs(cub->line.dx) > abs(cub->line.dy))
		cub->line.steps = abs(cub->line.dx);
	cub->line.x = cub->player.x;
	cub->line.y = cub->player.y;
	cub->line.checkx = cub->line.x;
	cub->line.checky = cub->line.y;
}

void	draw_line(t_struct *cub, int end_point_x, int end_point_y, int color)
{
	int	check;
	int	i;

	check = 0;
	i = -1;
	inisalation(cub, end_point_x, end_point_y);
	while (++i <= cub->line.steps)
	{
		check = point(cub);
		if (check == 1 || \
		(cub->line.x == end_point_x && cub->line.y == end_point_y) \
		|| (cub->line.x < 0 || cub->line.y < 0))
			break ;
		else if (check == 0)
		{
			cub->line.dor_x = 0;
			cub->line.dor_y = 0;
		}
		if (color != 0)
			mlx_put_pixel(cub->image, cub->line.x, cub->line.y, color);
		cub->line.x += (float)cub->line.dx / cub->line.steps;
		cub->line.y += (float)cub->line.dy / cub->line.steps;
	}
}
