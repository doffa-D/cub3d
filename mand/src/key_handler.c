/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:35:03 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/20 15:13:17 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_hendler_v2(t_struct *cub)
{
	float	newplayerx;
	float	newplayery;

	newplayerx = 0;
	newplayery = 0;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		newplayerx += cos(cub->player.rotation_angle + M_PI / 2) * 0.2;
		newplayery += sin(cub->player.rotation_angle + M_PI / 2) * 0.2;
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		newplayerx += cos(cub->player.rotation_angle - M_PI / 2) * 0.2;
		newplayery += sin(cub->player.rotation_angle - M_PI / 2) * 0.2;
	}
	if (has_wall_at(cub, newplayerx + cub->player.x, newplayery
			+ cub->player.y) == false)
	{
		cub->player.x += newplayerx;
		cub->player.y += newplayery;
	}
}

void	key_hendler(t_struct *cub)
{
	cub->player.walk_direction = 0;
	cub->player.turn_direction = 0;
	cub->player.rotation_angle = normalize_angle(cub->player.rotation_angle);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		cub->player.walk_direction = 1;
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		cub->player.walk_direction = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player.turn_direction = 1;
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player.turn_direction = -1;
	key_hendler_v2(cub);
}
