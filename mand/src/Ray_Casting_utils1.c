/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray_Casting_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:24:18 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/20 15:36:21 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	hit_horz_wall(t_struct *cub, t_steps *vars, int strip_id)
{
	if (cub->rays[strip_id].facing_up)
		vars->is_wal = vars->start_y - 1;
	else
		vars->is_wal = vars->start_y;
	if ((vars->is_wal < cub->window_height * (TILE_SIZE * MINI_MAP) \
		&& vars->start_x < cub->window_width * (TILE_SIZE * MINI_MAP) \
		&& vars->is_wal > 0 && vars->start_x > 0 \
		&& cub->map[(int)(vars->is_wal / (TILE_SIZE * MINI_MAP))]
		&& vars->start_x / (TILE_SIZE * MINI_MAP) < \
		ft_strlen(cub->map[(int)floor \
		((vars->is_wal / (TILE_SIZE * MINI_MAP)))]))
		&& cub->map[(int)(vars->is_wal / (TILE_SIZE
				* MINI_MAP))][(int)(vars->start_x / (TILE_SIZE
				* MINI_MAP))] == '1')
	{
		vars->horz_x = vars->start_x;
		vars->horz_y = vars->start_y;
		vars->horz_wall_hit = true;
		return (1);
	}
	return (0);
}
