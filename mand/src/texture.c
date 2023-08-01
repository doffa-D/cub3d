/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:14:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/08/01 10:38:46 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_back(char *str, t_struct *cub)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	if (str[1] != ' ')
		printf_error_v2(cub);
	str = ft_strtrim(&str[1], " ");
	while (str && str[++i] && str[i] != '\n')
	{
		if ((!ft_isdigit(str[i]) && str[i] != ',') || \
		(str[i] == ',' && str[i + 1] == ','))
			printf_error_v2(cub);
		if (str[i] == ',' && i > 0 \
		&& ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1]))
			x++;
	}
	if (x < 2 || x > 2)
		printf_error_v2(cub);
	free(str);
	return (1);
}

void	background_buffer(char **path, t_struct *cub, char **str, int j)
{
	char	**back;
	int		x;

	x = -1;
	while (path[++x])
	{
		if (ft_strchr(path[x], '.'))
			str[++j] = ft_strtrim(ft_strchr(path[x], '.'), "\n");
		if (ft_strchr(path[x], 'F') && check_back(ft_strchr(path[x], 'F'), cub))
		{
			back = ft_split(ft_strchr(path[x], 'F') + 2, ',');
			cub->up[0] = ft_atoi(back[0]);
			cub->up[1] = ft_atoi(back[1]);
			cub->up[2] = ft_atoi(back[2]);
			free_back(back);
		}
		if (ft_strchr(path[x], 'C') && check_back(ft_strchr(path[x], 'C'), cub))
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
	str = ft_calloc(sizeof(char *), 5);
	cub->up = ft_calloc(sizeof(int), 4);
	cub->down = ft_calloc(sizeof(int), 4);
	background_buffer(path, cub, str, -1);
	while (cub->texters[++i])
		free(cub->texters[i]);
	free(cub->texters);
	cub->texters = ft_calloc(sizeof(char *), 5);
	i = 0;
	while (i < 4 && str[i])
	{
		cub->texters[i] = ft_strdup(str[i]);
		free(str[i++]);
	}
	free(str);
}

void	texter_check(t_struct *cub)
{
	int	h;
	int	w;

	h = 800;
	w = 586;
	if (cub->the_north.wall->height != 586 || cub->the_north.wall->width != 800
		|| cub->the_south.wall->height != 586
		|| cub->the_south.wall->width != 800
		|| cub->the_west.wall->height != 586 || cub->the_west.wall->width != 800
		|| cub->the_east.wall->height != 586
		|| cub->the_east.wall->width != 800)
	{
		h = 0;
		while (cub->texters[h])
			free(cub->texters[h++]);
		free(cub->texters);
		printf("Error height 586 && width 800\n");
		exit(1);
	}
}

void	texturee(t_struct *cub)
{
	path_extract(cub, cub->texters);
	cub->the_north.wall = mlx_load_png(cub->texters[0]);
	cub->the_south.wall = mlx_load_png(cub->texters[1]);
	cub->the_west.wall = mlx_load_png(cub->texters[2]);
	cub->the_east.wall = mlx_load_png(cub->texters[3]);
	if (!cub->the_north.wall || !cub->the_south.wall || !cub->the_west.wall
		|| !cub->the_east.wall)
	{
		printf("error\n%s\n", mlx_strerror(mlx_errno));
		free_all(cub, 0);
		exit(1);
	}
	texter_check(cub);
	store_pixels(&cub->the_north, 0);
	store_pixels(&cub->the_south, 0);
	store_pixels(&cub->the_west, 0);
	store_pixels(&cub->the_east, 0);
}
