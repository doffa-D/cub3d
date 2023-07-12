/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:58:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 19:17:00 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	free_back(char **back)
{
	int i;
	i = 0;
	while(back[i])
	{
		free(back[i++]);
	}
	free(back);
}
void	free_color(t_texture *texture)
{
	int i;
	i = 0;
    while(i < (int)texture->wall->height) 
	{
        free(texture->color_buffer[i]);
		i++;   
    }
    free(texture->color_buffer);
	free(texture);
}
void	free_all_texters(t_struct *cub)
{
	int i;
	i = 0;
	while(i < 4)
		free(cub->texters[i++]);
	free(cub->texters);
	free_color(cub->the_north);
	free_color(cub->the_south);
	free_color(cub->the_west);
	free_color(cub->the_east);
}

void	free_all(t_struct *cub)
{
	int	i;

	i = 0;
	free_all_texters(cub);
	while (cub->map[i])
		free(cub->map[i++]);
	free(cub->map);
	free(cub->up);
	free(cub->down);
}