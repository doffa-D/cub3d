/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:38:06 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/20 15:35:33 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
}
