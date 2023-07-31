/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:38:06 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/24 20:03:42 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_rays(t_struct *cub)
{
	int		i;
	int		line_end_x;
	int		line_end_y;
	float	ray_angle;
	float	fov_angle;

	fov_angle = (20 * (M_PI / 180));
	ray_angle = cub->player.rotation_angle - (fov_angle / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		line_end_x = cub->player.x + (MINI_MAP * TILE_SIZE) * cos(ray_angle);
		line_end_y = cub->player.y + (MINI_MAP * TILE_SIZE) * sin(ray_angle);
		draw_line(cub, line_end_x, line_end_y, 0);
		ray_angle += fov_angle / NUM_RAYS;
	}
	line_end_x = cub->player.x + ((MINI_MAP * TILE_SIZE) + 1)
		* cos(cub->player.rotation_angle);
	line_end_y = cub->player.y + ((MINI_MAP * TILE_SIZE) + 1)
		* sin(cub->player.rotation_angle);
	if (cub->hide_map % 2 == 0)
	{
		draw_line(cub, line_end_x, line_end_y, 0x000000FF);
		fill_player(cub, cub->player.y - 0.5, cub->player.x - 0.5);
	}
}

void	move_player(t_struct *cub)
{
	float	new_player_x;
	float	new_player_y;

	cub->player.rotation_angle += cub->player.turn_direction * 0.09;
	new_player_x = cub->player.x + (cos(cub->player.rotation_angle)
			* cub->player.walk_direction);
	new_player_y = cub->player.y + (sin(cub->player.rotation_angle)
			* cub->player.walk_direction);
	if (has_wall_at(cub, new_player_x, new_player_y) == false)
	{
		cub->player.x = new_player_x;
		cub->player.y = new_player_y;
	}
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
