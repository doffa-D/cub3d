/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray-Casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:41:19 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 17:02:28 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

// float				distancePoints(float x1, float y1, float x2, float y2)
// {
//     return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
// }

// float				normalizeAngle(float angle)
// {
// 	angle = remainder(angle, 2*M_PI);
// 	if (angle < 0)
// 		angle = (2 * M_PI) + angle;
// 	return (angle);
// }

// void				castRay(t_struct *cub,float rayAngle, int stripId)
// { //TODO: All the crazy logic for horz, vert, ...
// 	rayAngle = normalizeAngle(rayAngle);

// 	int				isRayFacingDown	 = rayAngle > 0 && rayAngle < M_PI;
// 	int				isRayFacingUp	 = !isRayFacingDown;
// 	int				isRayFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
// 	int				isRayFacingLeft	 = !isRayFacingRight;

// 	float			xintercept, yintercept;
// 	float			xstep, ystep;

// 	///////////////////////////////////////////
// 	///HORIZONTAL RAY_GRID INTERSECTION CODE///
// 	///////////////////////////////////////////
// 	int				foundHorzWallHit = false;
// 	float			horzWallHitX	 = 0;
// 	float			horzWallHitY	 = 0;
// 	int				horzWallContent	 = 0;

// 	// Find the y-coordinate of the closest horizontal grid intersenction
// 	yintercept		=	floor(cub->player->y / (TILE_SIZE * MINI_MAP)) * (TILE_SIZE * MINI_MAP);
// 	if (isRayFacingDown) 
//         yintercept += (TILE_SIZE * MINI_MAP);
//     else
//         yintercept += 0;


// 	// Find the x-coordinate of the closest horizontal grid intersection
// 	xintercept		=	cub->player->x + (yintercept - cub->player->y) / tan(rayAngle);

// 	// Calculate the increment xstep and ystep
// 	ystep			=	(TILE_SIZE * MINI_MAP);
//     // printf("befor ystep %f\n",ystep);
//     if (isRayFacingUp)
//         ystep *= -1;
//     else
//         ystep *= 1;
// 	xstep			=	(TILE_SIZE * MINI_MAP) / tan(rayAngle);
//     // printf("========\n");
//     // printf("tan %f\n",tan(rayAngle));
//     // printf("xstep %f\n",xstep);
//     // printf("========\n");

//     if (isRayFacingLeft && xstep > 0)
//         xstep *= -1;
//     else if (isRayFacingRight && xstep < 0)
//         xstep *= -1;
    

// 	float			nextHorzTouchX = xintercept;
// 	float			nextHorzTouchY = yintercept;

// 	float		xToCheck;
// 	float		yToCheck;
// 	// Increment xstep and ystep until we find a wall
// 	while (nextHorzTouchX >= 0 && nextHorzTouchX <= cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) &&
// 		   nextHorzTouchY >= 0 && nextHorzTouchY <= cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP))
// 	{
// 		xToCheck = nextHorzTouchX;
//         if (isRayFacingUp)
//             yToCheck = nextHorzTouchY - 1;
//         else
//             yToCheck = nextHorzTouchY;

// 		if(yToCheck > 0 && xToCheck > 0 && yToCheck <  cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) && xToCheck < cub->WINDOW_WIDTH  * (TILE_SIZE * MINI_MAP) && cub->map[(int)floor((yToCheck  / (TILE_SIZE * MINI_MAP)))] && cub->map[(int)floor((yToCheck  / (TILE_SIZE * MINI_MAP)))][(int)floor((xToCheck  / (TILE_SIZE * MINI_MAP)))] == '1')
// 		{// Found a wall hit
// 			horzWallHitX	 = nextHorzTouchX;
// 			horzWallHitY	 = nextHorzTouchY;
// 			horzWallContent	 = cub->map[(int)floor(yToCheck/(TILE_SIZE * MINI_MAP))][(int)floor(xToCheck/(TILE_SIZE * MINI_MAP))];
//             foundHorzWallHit = true;
// 			break;
// 		}
// 		else
// 		{// Couldn't found a wall
// 			nextHorzTouchX += xstep;
// 			nextHorzTouchY += ystep;
// 		}
// 	}

// 	///////////////////////////////////////
// 	// /VERTICAL RAY_GRID INTERSECTION CODE///
// 	/////////////////////////////////////////
// 	int				foundVertWallHit = false;
// 	float			vertWallHitX	 = 0;
// 	float			vertWallHitY	 = 0;
// 	int				vertWallContent	 = 0;

// 	// Find the y-coordinate of the closest horizontal grid intersenction
// 	xintercept		=	floor(cub->player->x / (TILE_SIZE * MINI_MAP)) * (TILE_SIZE * MINI_MAP);
//     if (isRayFacingRight)
//         xintercept += (TILE_SIZE * MINI_MAP);
//     else
//         xintercept += 0;


// 	// Find the x-coordinate of the closest horizontal grid intersection
// 	yintercept		=	cub->player->y + (xintercept - cub->player->x) * tan(rayAngle);


// 	// Calculate the increment xstep and ystep
// 	xstep			=	(TILE_SIZE * MINI_MAP);
//     if (isRayFacingLeft)
//         xstep *= -1;
//     else 
//         xstep *= 1;

//     ystep = (TILE_SIZE * MINI_MAP) * tan(rayAngle);
//     if (isRayFacingUp && ystep > 0)
//         ystep *= -1;
//     else
//         ystep *= 1;
    
//     if (isRayFacingDown && ystep < 0)
//         ystep *= -1;
//     else
//         ystep *= 1;

// 	float			nextVertTouchX = xintercept;
// 	float			nextVertTouchY = yintercept;

// 	// Increment xstep and ystep until we find a wall
// 	while (nextVertTouchX >= 0 && nextVertTouchX <= cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) &&
// 		   nextVertTouchY >= 0 && nextVertTouchY <= cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP))
// 	{
//         if (isRayFacingLeft) 
//             xToCheck = nextVertTouchX - 1;
//         else 
//             xToCheck = nextVertTouchX;
    

// 		float		yToCheck = nextVertTouchY;

// 		if(yToCheck > 0 && xToCheck > 0 && yToCheck <  cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) && xToCheck < cub->WINDOW_WIDTH  * (TILE_SIZE * MINI_MAP) && cub->map[(int)floor((yToCheck  / (TILE_SIZE * MINI_MAP)))] && cub->map[(int)floor((yToCheck  / (TILE_SIZE * MINI_MAP)))][(int)floor((xToCheck  / (TILE_SIZE * MINI_MAP)))] == '1')
// 		{// Found a wall hit
// 			vertWallHitX	 = nextVertTouchX;
// 			vertWallHitY	 = nextVertTouchY;
// 			vertWallContent	 = cub->map[(int)floor(yToCheck/(TILE_SIZE * MINI_MAP))][(int)floor(xToCheck/(TILE_SIZE * MINI_MAP))];
// 			foundVertWallHit = true;
// 			break;
// 		}
// 		else
// 		{// Couldn't found a wall
// 			nextVertTouchX += xstep;
// 			nextVertTouchY += ystep;
// 		}
// 	}

// 	// Calculate both horizontal and vertical hit distances and choose the smallest one
//     float horzHitDistance;
//     if (foundHorzWallHit)
//         horzHitDistance = distancePoints(cub->player->x, cub->player->y, horzWallHitX, horzWallHitY);
//     else
//         horzHitDistance = INT_MAX;
    

//     float vertHitDistance;
//     if (foundVertWallHit)
//         vertHitDistance = distancePoints(cub->player->x, cub->player->y, vertWallHitX, vertWallHitY);
//     else
//         vertHitDistance = INT_MAX;


// 	if (vertHitDistance < horzHitDistance)
// 	{
// 		cub->rays[stripId].distance		 = vertHitDistance;
// 		cub->rays[stripId].wallHitX		 = vertWallHitX;
// 		cub->rays[stripId].wallHitY		 = vertWallHitY;
// 		cub->rays[stripId].wasHitVertical = true;
// 		cub->rays[stripId].wallHitContent = vertWallContent;}
// 	else
// 	{
// 		cub->rays[stripId].distance		 = horzHitDistance;
// 		cub->rays[stripId].wallHitX		 = horzWallHitX;
// 		cub->rays[stripId].wallHitY		 = horzWallHitY;
// 		cub->rays[stripId].wasHitVertical = false;
// 		cub->rays[stripId].wallHitContent = horzWallContent;
// 	}
//     cub->rays[stripId].rayAngle			 = rayAngle;
//     cub->rays[stripId].isRayFacingDown	 = isRayFacingDown;
//     cub->rays[stripId].isRayFacingUp		 = isRayFacingUp;
//     cub->rays[stripId].isRayFacingRight	 = isRayFacingRight;
//     cub->rays[stripId].isRayFacingLeft	 = isRayFacingLeft;
// }

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
	y_next_point_position = ((int)(cub->player->y / (TILE_SIZE * MINI_MAP))) * (TILE_SIZE * MINI_MAP);
	if(face_down)
		y_next_point_position += TILE_SIZE * MINI_MAP;
	/////////////
	x_next_point_position = ((y_next_point_position - cub->player->y) / tan(rayAngle)) + cub->player->x;
	/////////////
	while (x_next_point_position >= 0 && x_next_point_position <= cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) &&
		   y_next_point_position >= 0 && y_next_point_position <= cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP))
	{
		if(face_up)
			check_is_wall = y_next_point_position - 1;
		else
			check_is_wall = y_next_point_position;
		if(check_is_wall < cub->WINDOW_HEIGHT * (TILE_SIZE * MINI_MAP) 
		&& x_next_point_position < cub->WINDOW_WIDTH * (TILE_SIZE * MINI_MAP) 
		&& check_is_wall > 0 && x_next_point_position > 0 &&
		cub->map[(int)(check_is_wall / (TILE_SIZE * MINI_MAP))] &&
		cub->map[(int)(check_is_wall / (TILE_SIZE * MINI_MAP))][(int)(x_next_point_position / (TILE_SIZE * MINI_MAP))] == '1')
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
	x_next_point_position = ((int)(cub->player->x / (TILE_SIZE * MINI_MAP))) * (TILE_SIZE * MINI_MAP);
	if(face_right)
		x_next_point_position += TILE_SIZE * MINI_MAP;
	y_next_point_position = ((x_next_point_position - cub->player->x) * tan(rayAngle)) + cub->player->y;
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
        horz_distance = distancePoints(horz_point_x_intersection - cub->player->x, horz_point_y_intersection - cub->player->y);
    else
        horz_distance = INT_MAX;
    
    float vert_distance;
    if (foundvertWallHit)
        vert_distance = distancePoints(vertpoint_x_intersection - cub->player->x, vertpoint_y_intersection - cub->player->y);
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
	rayAngle = cub->player->rotationAngle - (FOV_ANGLE / 2);
	for (int stripId=0; stripId < NUM_RAYS; stripId++)
	{
		castRay(cub,rayAngle, stripId);
		rayAngle += FOV_ANGLE / NUM_RAYS;
	}

}