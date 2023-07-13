/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:43:15 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 19:37:54 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void draw_line(t_struct *cub, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
	int sx, sy;
	if (x0 < x1)
		sx = 1; 
	else 
		sx = -1;
	if (y0 < y1) 
		sy = 1;
	else 
		sy = -1;

    int err = dx - dy;
    int e2;
    int checkx =x0;
    int checky =y0;

    while (1)
    {
        if(cub->map[checky / (int)(TILE_SIZE  * MINI_MAP)] && cub->map[y0 / (int)(TILE_SIZE  * MINI_MAP)] 
        && cub->map[checky / (int)(TILE_SIZE  * MINI_MAP)][x0 / (int)(TILE_SIZE  * MINI_MAP)] == '1' && cub->map[y0 / (int)(TILE_SIZE  * MINI_MAP)][checkx / (int)(TILE_SIZE  * MINI_MAP)] == '1' )
            break;
        checkx = x0;
        checky = y0;
        mlx_put_pixel(cub->image, x0, y0, color);
		if(cub->map[(int)(y0  / (TILE_SIZE * MINI_MAP))] && cub->map[(int)(y0  / (TILE_SIZE * MINI_MAP))][(int)(x0  / (TILE_SIZE * MINI_MAP))] == '1')
			break;
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }

}