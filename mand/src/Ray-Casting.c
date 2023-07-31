/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray-Casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:21 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/20 15:05:58 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	distance_points(float x, float y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

float	normalize_angle(float angle)
{
	if (angle > 2 * M_PI)
		angle -= (2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	clacul_steps(t_struct *cub, int strip_id, t_steps *step,
		int check_ver_horz)
{
	if (check_ver_horz == HORIZOMNTAL)
	{
		step->y = TILE_SIZE * MINI_MAP;
		if (cub->rays[strip_id].facing_up)
			step->y *= -1;
		step->x = (TILE_SIZE * MINI_MAP) / tan(cub->rays[strip_id].ray_angle);
		if (step->x > 0 && cub->rays[strip_id].facing_left)
			step->x *= -1;
		else if (step->x < 0 && cub->rays[strip_id].facing_right)
			step->x *= -1;
	}
	if (check_ver_horz == VERTICAL)
	{
		step->x = TILE_SIZE * MINI_MAP;
		if (cub->rays[strip_id].facing_left)
			step->x *= -1;
		step->y = (TILE_SIZE * MINI_MAP) * tan(cub->rays[strip_id].ray_angle);
		if (step->y > 0 && cub->rays[strip_id].facing_up)
			step->y *= -1;
		else if (step->y < 0 && cub->rays[strip_id].facing_down)
			step->y *= -1;
	}
}

void	set_up_face(t_struct *cub, float ray_angle, int strip_id)
{
	cub->rays[strip_id].ray_angle = normalize_angle(ray_angle);
	if (cub->rays[strip_id].ray_angle >= M_PI \
	&& cub->rays[strip_id].ray_angle <= M_PI * 2)
		cub->rays[strip_id].facing_up = 1;
	else
		cub->rays[strip_id].facing_up = 0;
	cub->rays[strip_id].facing_down = !cub->rays[strip_id].facing_up;
	if (cub->rays[strip_id].ray_angle >= (M_PI / 2) \
	&& cub->rays[strip_id].ray_angle <= ((3 * M_PI) / 2))
		cub->rays[strip_id].facing_left = 1;
	else
		cub->rays[strip_id].facing_left = 0;
	cub->rays[strip_id].facing_right = !cub->rays[strip_id].facing_left;
}

void	calculate_start_cordinate(t_struct *cub, int strip_id, t_steps *step,
		int check_ver_horz)
{
	float	y_next_point_position;
	float	x_next_point_position;

	if (check_ver_horz == HORIZOMNTAL)
	{
		y_next_point_position = ((int)(cub->player.y / (TILE_SIZE * MINI_MAP)))
			* (TILE_SIZE * MINI_MAP);
		if (cub->rays[strip_id].facing_down)
			y_next_point_position += TILE_SIZE * MINI_MAP;
		x_next_point_position = ((y_next_point_position - cub->player.y)
				/ tan(cub->rays[strip_id].ray_angle)) + cub->player.x;
	}
	if (check_ver_horz == VERTICAL)
	{
		x_next_point_position = ((int)(cub->player.x / (TILE_SIZE * MINI_MAP)))
			* (TILE_SIZE * MINI_MAP);
		if (cub->rays[strip_id].facing_right)
			x_next_point_position += TILE_SIZE * MINI_MAP;
		y_next_point_position = ((x_next_point_position - cub->player.x)
				* tan(cub->rays[strip_id].ray_angle)) + cub->player.y;
	}
	step->start_x = x_next_point_position;
	step->start_y = y_next_point_position;
}
