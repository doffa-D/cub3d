/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:14:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 19:35:52 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	background_buffer(char **path, t_struct *cub, char **str,int j)
{
	char	**back;
	int		x;

	x = -1;
	while (path[++x])
	{
		if (ft_strchr(path[x], '.'))
			str[++j] = ft_strtrim(ft_strchr(path[x], '.'), "\n");
		else if (ft_strchr(path[x], 'F'))
		{
			back = ft_split(ft_strchr(path[x], 'F') + 2, ',');
			cub->up[0] = ft_atoi(back[0]);
			cub->up[1] = ft_atoi(back[1]);
			cub->up[2] = ft_atoi(back[2]);
			free_back(back);
		}
		else if (ft_strchr(path[x], 'C'))
		{
			back = ft_split(ft_strchr(path[x], 'C') + 2, ',');
			cub->down[0] = ft_atoi(back[0]);
			cub->down[1] = ft_atoi(back[1]);
			cub->down[2] = ft_atoi(back[2]);
			free_back(back);
		}
	}
}

void	path_extract(t_struct *cub, char **path)
{
	int		i;
	char	**str;

	i = -1;
	str = ft_calloc(sizeof(char *) , 3);
	cub->up = ft_calloc(sizeof(int) , 2);
	cub->down = ft_calloc(sizeof(int) , 2);
	background_buffer(path, cub, str,-1);
	while (cub->texters[++i])
		free(cub->texters[i]);
	free(cub->texters);
	cub->texters = ft_calloc(sizeof(char *) , 4);
	i = 0;
	while (i < 4)
	{
		cub->texters[i] = ft_strdup(str[i]);
		free(str[i++]);
	}
	cub->texters[i] = NULL;
	free(str);
}

void	texter_check(t_struct *cub)
{
	int	h;
	int	w;

	h = 800;
	w = 586;
	if (cub->the_north->wall->height != 586
		|| cub->the_north->wall->width != 800
		|| cub->the_south->wall->height != 586
		|| cub->the_south->wall->width != 800
		|| cub->the_west->wall->height != 586
		|| cub->the_west->wall->width != 800
		|| cub->the_east->wall->height != 586
		|| cub->the_east->wall->width != 800)
	{
		printf("fix texters size\n");
		free_all_texters(cub);
		exit(1);
	}
}

void	texturee(t_struct *cub)
{
	cub->the_north = ft_calloc(sizeof(t_texture),1);
	cub->the_south = ft_calloc(sizeof(t_texture),1);
	cub->the_west = ft_calloc(sizeof(t_texture),1);
	cub->the_east = ft_calloc(sizeof(t_texture),1);
	cub->dor = ft_calloc(sizeof(t_texture),1);
	path_extract(cub, cub->texters);
	cub->the_north->wall = mlx_load_png(cub->texters[0]);
	cub->the_south->wall = mlx_load_png(cub->texters[1]);
	cub->the_west->wall = mlx_load_png(cub->texters[2]);
	cub->the_east->wall = mlx_load_png(cub->texters[3]);
	cub->dor->wall = mlx_load_png("./bonus/texture/dor.png");
	if (!cub->the_north->wall || !cub->the_south->wall || !cub->the_west->wall
		|| !cub->the_east->wall || !cub->dor->wall)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		free_all_texters(cub);
		exit(1);
	}
	texter_check(cub);
	store_pixels(&cub->the_north->color_buffer, cub->the_north->wall);
	store_pixels(&cub->the_south->color_buffer, cub->the_south->wall);
	store_pixels(&cub->the_west->color_buffer, cub->the_west->wall);
	store_pixels(&cub->the_east->color_buffer, cub->the_east->wall);
	store_pixels(&cub->dor->color_buffer, cub->dor->wall);

}
