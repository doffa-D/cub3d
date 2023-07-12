/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:43:42 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 18:13:50 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	has_wall_at(t_struct *cub, float posx, float posy)
{
	int	map_id_x;
	int	map_id_y;

	if (posx < 0 || posx > cub->WINDOW_WIDTH * TILE_SIZE * MINI_MAP || posy < 0
		|| posy > cub->WINDOW_HEIGHT * TILE_SIZE * MINI_MAP)
		return (true);
	map_id_x = floor(posx / (TILE_SIZE * MINI_MAP));
	map_id_y = floor(posy / (TILE_SIZE * MINI_MAP));
	if (cub->close_dor % 2 == 0 && cub->map[map_id_y][map_id_x] == 'D'
		&& cub->map[(int)floor(cub->player->y / (TILE_SIZE
				* MINI_MAP))][(int)floor(cub->player->x / (TILE_SIZE
				* MINI_MAP))] != 'D')
		return (true);
	if(cub->map[(int)cub->player->y / (int)(TILE_SIZE  * MINI_MAP)] && cub->map[(int)posy / (int)(TILE_SIZE  * MINI_MAP)] 
        && cub->map[(int)cub->player->y / (int)(TILE_SIZE  * MINI_MAP)][(int)posx / (int)(TILE_SIZE  * MINI_MAP)] == '1' && cub->map[(int)posy / (int)(TILE_SIZE  * MINI_MAP)][(int)cub->player->x / (int)(TILE_SIZE  * MINI_MAP)] == '1' )
            return (true);
	if (cub->map[map_id_y][map_id_x] == '1')
		return (true);
	return (false);
}
