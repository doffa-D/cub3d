/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:36:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:03 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	directions(t_struct *cub)
{
	int	x;
	int	y;

	x = (int)floor(cub->player.x / (TILE_SIZE * MINI_MAP));
	y = (int)floor(cub->player.y / (TILE_SIZE * MINI_MAP));
	if (cub->map[y][x] == 'N')
		cub->player.rotationAngle = (3 * M_PI / 2) + 0.1;
	if (cub->map[y][x] == 'S')
		cub->player.rotationAngle = (M_PI / 2) + 0.1;
	if (cub->map[y][x] == 'E')
		cub->player.rotationAngle = +0.1;
	if (cub->map[y][x] == 'W')
		cub->player.rotationAngle = M_PI + +0.1;
}

void	setup(t_struct *cub, char *path)
{
	cub->WINDOW_HEIGHT = 0;
	cub->WINDOW_WIDTH = 0;
	parccen_map(cub, path);
	init_position(cub);
	directions(cub);
}

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	else
	{
		if (ft_strncmp(ft_strchr(argv[1], '.'), ".cub",
				ft_strlen(ft_strchr(argv[1], '.'))) == 1)
		{
			printf("Error\n");
			exit(1);
		}
	}
}

void	initializewindow(t_struct *cub, char *path)
{
	setup(cub, path);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub->mlx)
	{
		printf("Error: initializing mlx\n");
		exit(1);
	}
	cub->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->image)
	{
		printf("Error: creating image window\n");
		exit(1);
	}
	mlx_image_to_window(cub->mlx, cub->image, 0, 0);
}

void	init_position(t_struct *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'S' || cub->map[y][x] == 'N'
				|| cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				cub->player.x = ((x * TILE_SIZE) + TILE_SIZE / 2) * MINI_MAP;
				cub->player.y = ((y * TILE_SIZE) + TILE_SIZE / 2) * MINI_MAP;
				break ;
			}
			x++;
		}
		if (cub->player.x || cub->player.y)
			break ;
		y++;
	}
}
