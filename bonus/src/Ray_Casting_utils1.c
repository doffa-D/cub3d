/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray_Casting_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:24:18 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/20 15:33:59 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	horz_dor_close(t_struct *cub, int strip_id, t_steps *vars)
{
	if (cub->rays[strip_id].facing_up)
		vars->is_wal = vars->start_y - 1;
	else
		vars->is_wal = vars->start_y;
	if ((vars->is_wal > 0 && vars->start_x > 0
			&& vars->is_wal < cub->window_width * (TILE_SIZE * MINI_MAP)
			&& vars->start_x < cub->window_width * (TILE_SIZE * MINI_MAP)
			&& cub->map[(int)floor((vars->is_wal / (TILE_SIZE * MINI_MAP)))]
			&& vars->start_x / (TILE_SIZE \
			* MINI_MAP) < ft_strlen(cub->map[(int)floor((vars->is_wal \
			/ (TILE_SIZE * MINI_MAP)))])) \
		&& cub->map[(int)floor((vars->is_wal / (TILE_SIZE \
			* MINI_MAP)))][(int)floor((vars->start_x / (TILE_SIZE \
			* MINI_MAP)))] == 'D' && cub->map[(int)floor(cub->player.y
			/ (TILE_SIZE * MINI_MAP))][(int)floor(cub->player.x / (TILE_SIZE
				* MINI_MAP))] != 'D')
	{
		vars->horz_x = vars->start_x;
		vars->horz_y = vars->start_y;
		vars->horz_content = 'D';
		vars->horz_wall_hit = true;
		return (1);
	}
	return (0);
}

int	open_close_horz_dor(t_struct *cub, int strip_id, t_steps *vars)
{
	if (horz_dor_close(cub, strip_id, vars))
		return (1);
	if ((vars->is_wal < cub->window_height * (TILE_SIZE * MINI_MAP)
			&& vars->start_x < cub->window_width * (TILE_SIZE * MINI_MAP)
			&& vars->is_wal > 0 && vars->start_x > 0
			&& cub->map[(int)(vars->is_wal / (TILE_SIZE * MINI_MAP))] \
			&& vars->start_x / (TILE_SIZE \
			* MINI_MAP) < ft_strlen(cub->map[(int)floor((vars->is_wal \
			/ (TILE_SIZE * MINI_MAP)))]))
		&& cub->map[(int)(vars->is_wal / (TILE_SIZE
				* MINI_MAP))][(int)(vars->start_x / (TILE_SIZE
				* MINI_MAP))] == '5')
	{
		vars->horz_content = '5';
	}
	return (0);
}

int	vert_dor_close(t_struct *cub, int strip_id, t_steps *vars)
{
	if (cub->rays[strip_id].facing_left)
		vars->is_wal = vars->start_x - 1;
	else
		vars->is_wal = vars->start_x;
	if ((vars->start_y > 0 && vars->is_wal > 0
			&& vars->start_y < cub->window_width * (TILE_SIZE * MINI_MAP)
			&& vars->is_wal < cub->window_width * (TILE_SIZE * MINI_MAP))
		&& cub->map[(int)floor((vars->start_y / (TILE_SIZE * MINI_MAP)))]
		&& vars->is_wal / (TILE_SIZE
			* MINI_MAP) < ft_strlen(cub->map[(int)floor((vars->start_y \
			/ (TILE_SIZE * MINI_MAP)))])
		&& cub->map[(int)floor((vars->start_y / (TILE_SIZE \
			* MINI_MAP)))][(int)floor((vars->is_wal / (TILE_SIZE \
			* MINI_MAP)))] == 'D' && cub->map[(int)floor(cub->player.y
			/ (TILE_SIZE * MINI_MAP))][(int)floor(cub->player.x / (TILE_SIZE
				* MINI_MAP))] != 'D')
	{
		vars->vert_x = vars->start_x;
		vars->vert_y = vars->start_y;
		vars->vert_content = 'D';
		vars->vert_wall_hit = true;
		return (1);
	}
	return (0);
}

int	open_close_vert_dor(t_struct *cub, int strip_id, t_steps *vars)
{
	if (vert_dor_close(cub, strip_id, vars))
		return (1);
	if (vars->start_y < cub->window_height * (TILE_SIZE * MINI_MAP)
		&& vars->is_wal < cub->window_width * (TILE_SIZE * MINI_MAP)
		&& vars->start_y > 0 && vars->is_wal > 0 && cub->map[(int)(vars->start_y
			/ (TILE_SIZE * MINI_MAP))] && vars->is_wal / (TILE_SIZE
			* MINI_MAP) < ft_strlen(cub->map[(int)floor((vars->start_y
					/ (TILE_SIZE * MINI_MAP)))]) && cub->map[(int)(vars->start_y
			/ (TILE_SIZE * MINI_MAP))][(int)(vars->is_wal / (TILE_SIZE
				* MINI_MAP))] == '5')
	{
		vars->vert_content = '5';
	}
	return (0);
}

int	hit_horz_wall(t_struct *cub, t_steps *vars)
{
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
		vars->horz_content = '1';
		vars->horz_wall_hit = true;
		return (1);
	}
	return (0);
}
