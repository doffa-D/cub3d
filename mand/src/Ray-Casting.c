/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray-Casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:41:19 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/13 10:22:26 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

float				distancePoints(float x, float y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

float				normalizeAngle(float angle)
{
	angle = remainder(angle, 2*M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void				castRay(t_struct *cub,float rayAngle, int stripId)
{
	rayAngle = normalizeAngle(rayAngle);
	int face_up = rayAngle >= M_PI && rayAngle <= M_PI * 2;
	int face_down = !face_up;
	int face_left = rayAngle >= (M_PI / 2) && rayAngle <= ((3 * M_PI) / 2);
	int face_right = !face_left;



	float x_next_point_position;
	float y_next_point_position;

	float horzWallContent = 0;
	float foundHorzWallHit = 0;
	float check_is_wall = 0;
	float horz_point_y_intersection = 0;
	float horz_point_x_intersection = 0;

	float step_y = TILE_SIZE * MINI_MAP;
	if(face_up)
		step_y *= -1;
	/////////////
	float step_x =	(TILE_SIZE * MINI_MAP) / tan(rayAngle);
	if(step_x > 0 && face_left)
		step_x *= -1;
	else if(step_x < 0 && face_right)
		step_x *= -1;
	/////////////
	y_next_point_position = ((int)(cub->player.y / (TILE_SIZE * MINI_MAP))) * (TILE_SIZE * MINI_MAP);
	if(face_down)
		y_next_point_position += TILE_SIZE * MINI_MAP;
	/////////////
	x_next_point_position = ((y_next_point_position - cub->player.y) / tan(rayAngle)) + cub->player.x;
	/////////////
	while (x_next_point_position >= 0 && x_next_point_position <= cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) &&
		   y_next_point_position >= 0 && y_next_point_position <= cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP))
	{
		if(face_up)
			check_is_wall = y_next_point_position - 1;
		else
			check_is_wall = y_next_point_position;
		if((check_is_wall < cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP) && x_next_point_position < cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) && check_is_wall > 0 && x_next_point_position > 0 
		&& cub->map[(int)(check_is_wall / (TILE_SIZE * MINI_MAP))] \
		&& x_next_point_position / (TILE_SIZE * MINI_MAP) < ft_strlen(cub->map[(int)floor((check_is_wall  / (TILE_SIZE * MINI_MAP)))])) 
		&& cub->map[(int)(check_is_wall / (TILE_SIZE * MINI_MAP))][(int)(x_next_point_position / (TILE_SIZE * MINI_MAP))] == '1')
		{
			horz_point_x_intersection = x_next_point_position;
			horz_point_y_intersection = y_next_point_position;
			horzWallContent	 = cub->map[(int)(check_is_wall/(TILE_SIZE * MINI_MAP))][(int)(x_next_point_position/(TILE_SIZE * MINI_MAP))];
			foundHorzWallHit = true;
			break;
		}
		x_next_point_position+=step_x;
		y_next_point_position+=step_y;
	}




	x_next_point_position = 0;
	y_next_point_position = 0;
	float vertWallContent = 0;
	float foundvertWallHit = 0;
	float vertpoint_y_intersection = 0;
	float vertpoint_x_intersection = 0;

	check_is_wall = 0;

	step_x = TILE_SIZE * MINI_MAP;
	if(face_left)
		step_x *= -1;
	step_y =	(TILE_SIZE * MINI_MAP) * tan(rayAngle);
	if(step_y > 0 && face_up)
		step_y *= -1;   
	else if(step_y < 0 && face_down)
		step_y *= -1;
	x_next_point_position = ((int)(cub->player.x / (TILE_SIZE * MINI_MAP))) * (TILE_SIZE * MINI_MAP);
	if(face_right)
		x_next_point_position += TILE_SIZE * MINI_MAP;
	y_next_point_position = ((x_next_point_position - cub->player.x) * tan(rayAngle)) + cub->player.y;
	while (y_next_point_position <= cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP) \
		&& x_next_point_position <= cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) \
		&& y_next_point_position >= 0 \
		&& x_next_point_position >= 0)
	{
		if(face_left)
			check_is_wall = x_next_point_position - 1;
		else
			check_is_wall = x_next_point_position;
		if(y_next_point_position < cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP) \
		&& check_is_wall < cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) \
		&& y_next_point_position > 0 && check_is_wall > 0 \
		&& cub->map[(int)(y_next_point_position / (TILE_SIZE * MINI_MAP))] \
		&& check_is_wall / (TILE_SIZE * MINI_MAP) < ft_strlen(cub->map[(int)floor((y_next_point_position  / (TILE_SIZE * MINI_MAP)))])
		&& cub->map[(int)(y_next_point_position / (TILE_SIZE * MINI_MAP))][(int)(check_is_wall / (TILE_SIZE * MINI_MAP))] == '1')
		{
			vertpoint_x_intersection = x_next_point_position;
			vertpoint_y_intersection = y_next_point_position;
			vertWallContent	 = cub->map[(int)(y_next_point_position/(TILE_SIZE * MINI_MAP))][(int)(check_is_wall/(TILE_SIZE * MINI_MAP))];
			foundvertWallHit = true;
			break;
		}
		x_next_point_position+=step_x;
		y_next_point_position+=step_y;
	}
	float horz_distance;
    if (foundHorzWallHit)
        horz_distance = distancePoints(horz_point_x_intersection - cub->player.x, horz_point_y_intersection - cub->player.y);
    else
        horz_distance = INT_MAX;
    
    float vert_distance;
    if (foundvertWallHit)
        vert_distance = distancePoints(vertpoint_x_intersection - cub->player.x, vertpoint_y_intersection - cub->player.y);
    else
        vert_distance = INT_MAX;


	if (vert_distance < horz_distance)
	{
		cub->rays[stripId].distance		 = vert_distance;
		cub->rays[stripId].wallHitX		 = vertpoint_x_intersection;
		cub->rays[stripId].wallHitY		 = vertpoint_y_intersection;
		cub->rays[stripId].wasHitVertical = true;
		cub->rays[stripId].wallHitContent = vertWallContent;}
	else
	{
		cub->rays[stripId].distance		 = horz_distance;
		cub->rays[stripId].wallHitX		 = horz_point_x_intersection;
		cub->rays[stripId].wallHitY		 = horz_point_y_intersection;
		cub->rays[stripId].wasHitVertical = false;
		cub->rays[stripId].wallHitContent = horzWallContent;
	}
    cub->rays[stripId].rayAngle		= rayAngle;
    cub->rays[stripId].facing_down	= face_down;
    cub->rays[stripId].facing_up	= face_up;
    cub->rays[stripId].facing_right	= face_right;
    cub->rays[stripId].facing_left	= face_left;
}




void				castAllRays(t_struct *cub)
{	// start first ray subtracting half of our FOV
	float			rayAngle;
	rayAngle = cub->player.rotationAngle - (FOV_ANGLE / 2);
	for (int stripId=0; stripId < NUM_RAYS; stripId++)
	{
		castRay(cub,rayAngle, stripId);
		rayAngle += FOV_ANGLE / NUM_RAYS;
	}

}