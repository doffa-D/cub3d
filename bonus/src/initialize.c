/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:36:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/08/01 10:34:33 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	directions(t_struct *cub)
{
	int	x;
	int	y;

	x = (int)floor(cub->player.x / (TILE_SIZE * MINI_MAP));
	y = (int)floor(cub->player.y / (TILE_SIZE * MINI_MAP));
	if (cub->map[y] && cub->map[y][x] == 'N')
		cub->player.rotation_angle = ((3 * M_PI) / 2);
	else if (cub->map[y] && cub->map[y][x] == 'S')
		cub->player.rotation_angle = (M_PI / 2);
	else if (cub->map[y] && cub->map[y][x] == 'E')
		cub->player.rotation_angle = 0;
	else if (cub->map[y] && cub->map[y][x] == 'W')
		cub->player.rotation_angle = M_PI;
	else
	{
		printf("Error\nPlayer\n");
		free_all(cub, 0);
		exit(1);
	}
}

void	setup(t_struct *cub, char *path)
{
	cub->old_x = 0;
	cub->mouse_mode = 0;
	cub->hide_map = 0;
	cub->window_height = 0;
	cub->window_width = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	parccen_map(cub, path);
	init_position(cub);
	directions(cub);
}

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\narg\n");
		exit(1);
	}
	else if (ft_strrchr(argv[1], '.')
		&& ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5))
	{
		printf("Error\narg\n");
		exit(1);
	}
}

void	initializewindow(t_struct *cub, char *path)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!cub->mlx)
	{
		printf("Error\nmlx_init\n");
		exit(1);
	}
	cub->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->image)
	{
		printf("Error\nmlx_new_image\n");
		exit(1);
	}
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) == -1)
	{
		printf("Error\nmlx_image_to_window\n");
		exit(1);
	}
	setup(cub, path);
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
				return ;
			}
			x++;
		}
		y++;
	}
}
