/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray_Casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:23:05 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/20 15:36:10 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	hit_vert_wall(t_struct *cub, t_steps *vars, int strip_id)
{
	if (cub->rays[strip_id].facing_left)
		vars->is_wal = vars->start_x - 1;
	else
		vars->is_wal = vars->start_x;
	if (vars->start_y < cub->window_height * (TILE_SIZE * MINI_MAP)
		&& vars->is_wal < cub->window_width * (TILE_SIZE * MINI_MAP)
		&& vars->start_y > 0 && vars->is_wal > 0 && cub->map[(int)(vars->start_y
			/ (TILE_SIZE * MINI_MAP))] && vars->is_wal / (TILE_SIZE
			* MINI_MAP) < ft_strlen(cub->map[(int)floor((vars->start_y
					/ (TILE_SIZE * MINI_MAP)))]) && cub->map[(int)(vars->start_y
			/ (TILE_SIZE * MINI_MAP))][(int)(vars->is_wal / (TILE_SIZE
				* MINI_MAP))] == '1')
	{
		vars->vert_x = vars->start_x;
		vars->vert_y = vars->start_y;
		vars->vert_wall_hit = true;
		return (1);
	}
	return (0);
}

void	check_horz(t_struct *cub, float ray_angle, int strip_id, t_steps *vars)
{
	set_up_face(cub, ray_angle, strip_id);
	vars->is_wal = 0;
	vars->horz_wall_hit = 0;
	vars->horz_y = 0;
	vars->horz_x = 0;
	clacul_steps(cub, strip_id, vars, HORIZOMNTAL);
	calculate_start_cordinate(cub, strip_id, vars, HORIZOMNTAL);
	while (vars->start_x >= 0 && vars->start_x <= cub->window_width * \
		(TILE_SIZE * MINI_MAP) && vars->start_y >= 0 && vars->start_y \
		<= cub->window_height * (TILE_SIZE * MINI_MAP))
	{
		if (hit_horz_wall(cub, vars, strip_id))
			break ;
		vars->start_x += vars->x;
		vars->start_y += vars->y;
	}
	if (vars->horz_wall_hit)
		vars->horz_distance = distance_points(vars->horz_x - cub->player.x, \
		vars->horz_y - cub->player.y);
	else
		vars->horz_distance = INT_MAX;
}

void	check_vert(t_struct *cub, int strip_id, t_steps *vars)
{
	vars->start_x = 0;
	vars->start_y = 0;
	vars->is_wal = 0;
	vars->vert_wall_hit = 0;
	vars->vert_y = 0;
	vars->vert_x = 0;
	vars->is_wal = 0;
	clacul_steps(cub, strip_id, vars, VERTICAL);
	calculate_start_cordinate(cub, strip_id, vars, VERTICAL);
	while (vars->start_y <= cub->window_height * (TILE_SIZE * MINI_MAP)
		&& vars->start_x <= cub->window_width * (TILE_SIZE * MINI_MAP)
		&& vars->start_y >= 0 && vars->start_x >= 0)
	{
		if (hit_vert_wall(cub, vars, strip_id))
			break ;
		vars->start_x += vars->x;
		vars->start_y += vars->y;
	}
	if (vars->vert_wall_hit)
		vars->vert_distance = distance_points(vars->vert_x - cub->player.x, \
		vars->vert_y - cub->player.y);
	else
		vars->vert_distance = INT_MAX;
}

void	cast_ray(t_struct *cub, float ray_angle, int strip_id)
{
	t_steps	vars;

	check_horz(cub, ray_angle, strip_id, &vars);
	check_vert(cub, strip_id, &vars);
	if (vars.vert_distance < vars.horz_distance)
	{
		cub->rays[strip_id].distance = vars.vert_distance;
		cub->rays[strip_id].wall_hit_x = vars.vert_x;
		cub->rays[strip_id].wall_hit_y = vars.vert_y;
		cub->rays[strip_id].was_hit_vertical = true;
	}
	else
	{
		cub->rays[strip_id].distance = vars.horz_distance;
		cub->rays[strip_id].wall_hit_x = vars.horz_x;
		cub->rays[strip_id].wall_hit_y = vars.horz_y;
		cub->rays[strip_id].was_hit_vertical = false;
	}
}

void	cast_all_rays(t_struct *cub)
{
	float	ray_angle;
	float	fov_angle;
	float	radian_beetwen_rays;
	int		strip_id;

	strip_id = 0;
	fov_angle = (60 * (M_PI / 180));
	ray_angle = cub->player.rotation_angle - (fov_angle / 2);
	radian_beetwen_rays = fov_angle / NUM_RAYS;
	while (strip_id < NUM_RAYS)
	{
		cast_ray(cub, ray_angle, strip_id);
		ray_angle += radian_beetwen_rays;
		strip_id++;
	}
}
