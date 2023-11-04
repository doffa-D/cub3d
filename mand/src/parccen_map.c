/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parccen_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:50:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/31 20:25:59 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_color(char **split_texters, int j)
{
	int		index;
	char	**color;

	index = 0;
	if (split_texters[j])
	{
		color = ft_split(split_texters[j], ',');
		while (color[index])
		{
			if (3 <= ft_strlen(color[index]) && \
			(ft_atoi(color[index]) > 255 || ft_atoi(color[index]) < 0))
				print_error();
			free(color[index]);
			index++;
		}
		free(color);
	}
}

void	check_texters(t_struct *cub)
{
	int		i;
	int		j;
	char	**split_texters;

	i = 0;
	j = 0;
	while (cub->texters[i])
	{
		j = 0;
		split_texters = ft_split(cub->texters[i], ' ');
		while (split_texters[j])
		{
			check_error_texters(split_texters, j, i);
			j++;
		}
		free(split_texters);
		i++;
	}
}

int	calculat_map(t_struct *cub)
{
	int	j;

	j = 0;
	while (cub->map[j])
		j++;
	return (j);
}

void	check_map(t_struct *cub)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		check_map_error(cub, i, j);
	}
}

void	parccen_map(t_struct *cub, char *map_path)
{
	int	line;

	line = calculat_linght(map_path);
	if (line <= 5 || line * (MINI_MAP * TILE_SIZE) > HEIGHT)
		print_error();
	cub->map = ft_calloc(sizeof(char *), line - 5);
	cub->texters = ft_calloc(sizeof(char *), 7);
	full_path(cub, map_path);
	set_up_order(cub);
	check_texters(cub);
	check_map(cub);
	calculate_with_height(cub);
}
