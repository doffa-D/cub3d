/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parccen_map_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:27:16 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/08/01 10:36:59 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	calculat_linght(char *map_path)
{
	char	*map;
	int		i;
	int		fd;
	char	*trim;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_error("fd");
	while (1)
	{
		map = get_next_line(fd);
		if (!map && i == 0)
			print_error("Empty");
		trim = ft_strtrim(map, " \n");
		if (!map)
			break ;
		if (*trim)
			i++;
		free(map);
		free(trim);
	}
	close(fd);
	return (i);
}

void	fill_map_texters(t_struct *cub, char *map_tmp, int *i, int *j)
{
	if (cub->map_separeate == 1)
		print_error("map separet by newline");
	if (*i <= 5)
	{
		cub->texters[*i] = ft_strdup(map_tmp);
		if (ft_strncmp(cub->texters[*i], "NO ", 3) \
		&& ft_strncmp(cub->texters[*i], "SO ", 3) \
		&& ft_strncmp(cub->texters[*i], "WE ", 3) \
		&& ft_strncmp(cub->texters[*i], "EA ", 3) \
		&& ft_strncmp(cub->texters[*i], "F ", 2) \
		&& ft_strncmp(cub->texters[*i], "C ", 2))
		{
			print_error("worng Character");
		}
	}
	if ((*i) > 5)
	{
		cub->map[*j] = ft_strdup(map_tmp);
		(*j)++;
	}
	(*i)++;
}

void	full_path(t_struct *cub, char *map_path)
{
	int		i;
	int		j;
	int		fd;
	char	*trim;
	char	*map_tmp;

	i = 0;
	j = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_error("fd");
	while (1)
	{
		map_tmp = get_next_line(fd);
		if (!map_tmp)
			break ;
		trim = ft_strtrim(map_tmp, " \n");
		if (*trim)
			fill_map_texters(cub, map_tmp, &i, &j);
		if (!*trim && cub->map[0])
			cub->map_separeate = 1;
		free(trim);
		free(map_tmp);
	}
	close(fd);
}

void	calculate_with_height(t_struct *cub)
{
	int	i;

	i = 0;
	while (cub->map[cub->window_height])
	{
		if (cub->window_width < (int)ft_strlen(cub->map[cub->window_height]))
			cub->window_width = (int)ft_strlen(cub->map[cub->window_height]);
		cub->window_height++;
	}
	cub->map[cub->window_height] = NULL;
	cub->window_width -= 1;
	if (cub->window_width * (TILE_SIZE * MINI_MAP) > WIDTH \
	|| cub->window_height * (TILE_SIZE * MINI_MAP) > HEIGHT)
	{
		while (cub->map[i])
			free(cub->map[i++]);
		i = 0;
		while (cub->texters[i])
			free(cub->texters[i++]);
		print_error("Size ");
	}
}
