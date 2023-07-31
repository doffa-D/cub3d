/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:35:03 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/20 19:46:47 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check(t_struct *cub)
{
	if (cub->map[cub->line.dor_y] && cub->map[cub->line.dor_y] \
	[cub->line.dor_x] == '5')
		cub->map[cub->line.dor_y][cub->line.dor_x] = 'D';
	else if (cub->map[cub->line.dor_y] && cub->map[cub->line.dor_y] \
	[cub->line.dor_x] == 'D')
		cub->map[cub->line.dor_y][cub->line.dor_x] = '5';
}

int	mouse_handler(double xpos, double ypos, void *param)
{
	t_struct	*cub;

	cub = (t_struct *)param;
	(void)ypos;
	if (xpos > cub->old_x && cub->mouse_mode % 2 == 1)
		cub->player.turn_direction = 1;
	else if (xpos < cub->old_x && cub->mouse_mode % 2 == 1)
		cub->player.turn_direction = -1;
	cub->old_x = xpos;
	move_player(cub);
	return (0);
}

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

int	key_press(mlx_key_data_t keydata, void *param)
{
	t_struct	*cub;

	cub = (t_struct *)param;
	if (keydata.key == 'M' && keydata.action == 0)
		cub->hide_map++;
	if (keydata.key == 258 && keydata.action == 0)
		cub->mouse_mode++;
	if (cub->mouse_mode % 2 == 0)
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
	else
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_DISABLED);
	if (keydata.key == 'E' && keydata.action == 0)
		check(cub);
	return (0);
}
