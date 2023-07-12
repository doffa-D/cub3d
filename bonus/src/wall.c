/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:40:30 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:34:32 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void background(t_struct *cub)
{
    int x = 0;
	int y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(cub->image, x, y, ft_pixel(cub->up[0],cub->up[1],cub->up[2],200));
			y++;
		}
		x++;
	}
    x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_pixel(cub->image, x, y, ft_pixel(cub->down[0],cub->down[1],cub->down[2],200));
			y++;
		}
		x++;
	}
}

void    Wall3D(t_struct *cub)
{
    background(cub);
    int i;
    i = 0;
    int j;
    float l;
    float end_point = 0;
    float start_point = 0;
    float shit;
    float shit2;
    float x = 0;
    while(i < NUM_RAYS)
    {
        float size_line = HEIGHT / (cub->rays[i].distance * cos(cub->rays[i].rayAngle - cub->player.rotationAngle) / (TILE_SIZE * MINI_MAP));

        // float size_line = HEIGHT / (cub->rays[i].distance / (TILE_SIZE * MINI_MAP));
        start_point = (HEIGHT / 2) - (size_line / 2);
        end_point = HEIGHT / 2 + size_line / 2;
        if (cub->rays[i].wasHitVertical)
        {
            shit =(cub->rays[i].wallHitY - (((int)(cub->rays[i].wallHitY) / (int)(TILE_SIZE * MINI_MAP)) * (int)(TILE_SIZE * MINI_MAP))) * cub->the_north.wall->width / (int)(TILE_SIZE * MINI_MAP) ;
            shit2 =(cub->rays[i].wallHitY - (((int)(cub->rays[i].wallHitY) / (int)(TILE_SIZE * MINI_MAP)) * (int)(TILE_SIZE * MINI_MAP))) * cub->dor.wall->width / (int)(TILE_SIZE * MINI_MAP) ;
        }
        else
        {
            shit =(cub->rays[i].wallHitX - (int)(cub->rays[i].wallHitX)/(int)(TILE_SIZE * MINI_MAP)*(int)(TILE_SIZE * MINI_MAP)) *cub->the_north.wall->height /(int)(TILE_SIZE * MINI_MAP) ;
            shit2 =(cub->rays[i].wallHitX - (int)(cub->rays[i].wallHitX)/(int)(TILE_SIZE * MINI_MAP)*(int)(TILE_SIZE * MINI_MAP)) *cub->dor.wall->height /(int)(TILE_SIZE * MINI_MAP) ;
        }
        if (start_point<0)
            start_point=0;
        l = cub->the_north.wall->height / size_line;
        j = 0;
        float tkha = (size_line / 2 - HEIGHT / 2);
        if (tkha < 0)
            tkha = 0;    
        x = (l * tkha) + 1;
        while (j < size_line && j < HEIGHT)
        {
            if(x < cub->the_north.wall->height && cub->the_north.color_buffer[(int)x] && cub->the_north.color_buffer[(int)x][(int)shit] && !cub->rays[i].wasHitVertical && cub->rays[i].facing_up && cub->rays[i].wallHitContent == '1')
                mlx_put_pixel(cub->image,i, start_point + j, cub->the_north.color_buffer[(int)x][(int)shit]);
            if(x < cub->the_west.wall->height && cub->the_west.color_buffer[(int)x] && cub->the_west.color_buffer[(int)x][(int)shit] && !cub->rays[i].wasHitVertical && cub->rays[i].facing_down && cub->rays[i].wallHitContent == '1')
                mlx_put_pixel(cub->image,i, start_point + j, cub->the_west.color_buffer[(int)x][(int)shit]);
            if (x < cub->the_south.wall->height && cub->the_south.color_buffer[(int)x] && cub->the_south.color_buffer[(int)x][(int)shit] && cub->rays[i].wasHitVertical && cub->rays[i].facing_right && cub->rays[i].wallHitContent == '1')
                mlx_put_pixel(cub->image,i, start_point + j, cub->the_south.color_buffer[(int)x][(int)shit]);
            if (x < cub->the_east.wall->height && cub->the_east.color_buffer[(int)x] && cub->the_east.color_buffer[(int)x][(int)shit] && cub->rays[i].wasHitVertical && cub->rays[i].facing_left && cub->rays[i].wallHitContent == '1')
                mlx_put_pixel(cub->image,i, start_point + j, cub->the_east.color_buffer[(int)x][(int)shit]);
            if(x < cub->dor.wall->height && cub->rays[i].wallHitContent == 'D' && cub->close_dor % 2 == 0 && cub->map[(int)floor(cub->player.y  / (TILE_SIZE * MINI_MAP))][(int)floor(cub->player.x  / (TILE_SIZE * MINI_MAP))] != 'D')
                mlx_put_pixel(cub->image,i, start_point + j, cub->dor.color_buffer[(int)x][(int)(shit2)]);

            x += l;
            j++;
        }
        i++;
    }
    if(cub->HIDE_MAP % 2 == 0)
    {
        i = 0;
        while(i < NUM_RAYS)
        {
            draw_line(cub, cub->player.x, cub->player.y, cub->rays[i].wallHitX, cub->rays[i].wallHitY, 0xFFFF00FF);
            i++;
        }
    }
    if(cub->Mouse_mode % 2 == 1)
        drow_aim(cub);
}

