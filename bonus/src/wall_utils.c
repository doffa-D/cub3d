/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:32:18 by nouakhro          #+#    #+#             */
/*   Updated: 2023/07/31 18:54:50 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	instialation_cord_pixel(t_struct *cub, t_wall_3d *var_3d_wall, int i)
{
	int	size_cub;

	size_cub = (MINI_MAP * TILE_SIZE);
	if ((cub->rays + i)->was_hit_vertical)
	{
		var_3d_wall->x_wall_cordinate = (cub->the_south.wall->width / \
		size_cub) * ((cub->rays + i)->wall_hit_y - \
		((int)((cub->rays + i)->wall_hit_y / size_cub)*size_cub));
		var_3d_wall->x_dor_cordinate = (cub->dor.wall->width / size_cub) \
		* ((cub->rays + i)->wall_hit_y - \
		((int)((cub->rays + i)->wall_hit_y / size_cub) *size_cub));
	}
	else
	{
		var_3d_wall->x_wall_cordinate = (cub->the_south.wall->width \
		/ size_cub) * ((cub->rays + i)->wall_hit_x - \
		((int)((cub->rays + i)->wall_hit_x / size_cub) *size_cub));
		var_3d_wall->x_dor_cordinate = (cub->dor.wall->width / size_cub) \
		* ((cub->rays + i)->wall_hit_x - \
		((int)((cub->rays + i)->wall_hit_x / size_cub) *size_cub));
	}
}

void	instialation_varables(t_struct *cub, t_wall_3d *var_3d_wall, int i)
{
	var_3d_wall->final_dist = HEIGHT / ((cub->rays + i)->distance
			* cos((cub->rays + i)->ray_angle - cub->player.rotation_angle)
			/ (MINI_MAP * TILE_SIZE));
	var_3d_wall->started_point = HEIGHT / 2 - var_3d_wall->final_dist / 2;
	if (var_3d_wall->started_point < 0)
		var_3d_wall->started_point = 0;
	instialation_cord_pixel(cub, var_3d_wall, i);
	var_3d_wall->px_img_px_wind = cub->the_south.wall->height
		/ var_3d_wall->final_dist;
	var_3d_wall->error_wall = var_3d_wall->final_dist / 2 - HEIGHT / 2;
	if (var_3d_wall->error_wall < 0)
		var_3d_wall->error_wall = 0;
	var_3d_wall->y_pixel_cordinate = var_3d_wall->error_wall
		* var_3d_wall->px_img_px_wind;
}

void	horz_img(t_struct *cub, t_wall_3d var_3d_wall, int i, int j)
{
	if (var_3d_wall.y_pixel_cordinate < cub->the_south.wall->height
		&& var_3d_wall.x_wall_cordinate < cub->the_south.wall->width
		&& !(cub->rays + i)->was_hit_vertical && (cub->rays + i)->facing_down
		&& (cub->rays + i)->wall_hit_content == '1')
		mlx_put_pixel(cub->image, i, var_3d_wall.started_point + j, \
		cub->the_south.color_buffer[(int)var_3d_wall.y_pixel_cordinate] \
		[(int)var_3d_wall.x_wall_cordinate]);
	if (var_3d_wall.y_pixel_cordinate < cub->the_south.wall->height
		&& var_3d_wall.x_wall_cordinate < cub->the_north.wall->width
		&& !(cub->rays + i)->was_hit_vertical && (cub->rays + i)->facing_up
		&& (cub->rays + i)->wall_hit_content == '1')
		mlx_put_pixel(cub->image, i, var_3d_wall.started_point + j, \
		cub->the_north.color_buffer[(int)var_3d_wall.y_pixel_cordinate] \
		[(int)var_3d_wall.x_wall_cordinate]);
}

void	verical_img(t_struct *cub, t_wall_3d var_3d_wall, int i, int j)
{
	if (var_3d_wall.y_pixel_cordinate < cub->the_south.wall->height
		&& var_3d_wall.x_wall_cordinate < cub->the_west.wall->width
		&& (cub->rays + i)->was_hit_vertical && (cub->rays + i)->facing_left
		&& (cub->rays + i)->wall_hit_content == '1')
		mlx_put_pixel(cub->image, i, var_3d_wall.started_point + j, \
		cub->the_west.color_buffer[(int)var_3d_wall.y_pixel_cordinate] \
			[(int)var_3d_wall.x_wall_cordinate]);
	if (var_3d_wall.y_pixel_cordinate < cub->the_south.wall->height
		&& var_3d_wall.x_wall_cordinate < cub->the_east.wall->width
		&& (cub->rays + i)->was_hit_vertical && (cub->rays + i)->facing_right
		&& (cub->rays + i)->wall_hit_content == '1')
		mlx_put_pixel(cub->image, i, var_3d_wall.started_point + j, \
		cub->the_east.color_buffer[(int)var_3d_wall.y_pixel_cordinate] \
		[(int)var_3d_wall.x_wall_cordinate]);
}
