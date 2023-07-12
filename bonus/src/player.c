/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:38:06 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:03 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_rays(t_struct *cub)
{
	int		line_length;
	float	line_angle;
	int		line_end_x;
	int		line_end_y;

	fill_player(cub, cub->player.y - 0.5, cub->player.x - 0.5);
	line_length = TILE_SIZE * MINI_MAP;
	line_angle = cub->player.rotationAngle;
	line_end_x = cub->player.x + line_length * cos(line_angle);
	line_end_y = cub->player.y + line_length * sin(line_angle);
	draw_line(cub, cub->player.x, cub->player.y, line_end_x, line_end_y,
		0x800080FF);
}

void	move_player(t_struct *cub)
{
	float	new_player_x;
	float	new_player_y;

	cub->player.rotationAngle += cub->player.turnDirection * 0.09;
	new_player_x = cub->player.x + (cos(cub->player.rotationAngle)
			* cub->player.walkDirection);
	new_player_y = cub->player.y + (sin(cub->player.rotationAngle)
			* cub->player.walkDirection);
	if (has_wall_at(cub, new_player_x, new_player_y) == false)
	{
		cub->player.x = new_player_x;
		cub->player.y = new_player_y;
	}
	if (cub->HIDE_MAP % 2 == 0)
		player_rays(cub);
}

void	fill_player(t_struct *cub, int center_y, int center_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			mlx_put_pixel(cub->image, center_x + i, center_y + j, 0xFF00FFFF);
			j++;
		}
		i++;
	}
}
