/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:58:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:03 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(void *param)
{
	t_struct	*cub;

	cub = (t_struct *)param;
	if (cub->map[(int)floor(cub->player.y / (TILE_SIZE
					* MINI_MAP))][(int)floor(cub->player.x / (TILE_SIZE
				* MINI_MAP))] == 'D')
		cub->close_dor = 1;
	key_hendler(cub);
	castAllRays(cub);
	Wall3D(cub);
	if (cub->HIDE_MAP % 2 == 0)
		draw_windows(cub);
	move_player(cub);
}
