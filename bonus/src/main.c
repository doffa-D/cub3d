/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:08:56 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/08/01 14:41:10 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	dorr(t_struct *cub, int i, int y, char c)
{
	if (!((cub->map[i - 1][y] == '1' && cub->map[i + 1][y] == '1'
		&& (cub->map[i][y - 1] == c || cub->map[i][y + 1] == c))
			|| (cub->map[i][y - 1] == '1' && cub->map[i][y + 1] == '1'
				&& (cub->map[i - 1][y] == c || cub->map[i + 1][y] == c))))
		return (1);
	return (0);
}

void	check_door(t_struct *cub)
{
	int	i;
	int	y;

	i = -1;
	y = -1;
	while (cub->map[++i])
	{
		y = -1;
		while (cub->map[i][++y])
		{
			if (cub->map[i][y] == 'D')
			{
				if (dorr(cub, i, y, '0') && dorr(cub, i, y,
						cub->map[(int)(cub->player.y / (TILE_SIZE
								* MINI_MAP))][(int)(cub->player.x / (TILE_SIZE
						* MINI_MAP))]))
				{
					printf("Error dor\n");
					exit(1);
				}
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_struct	cub;

	arg_check(argc, argv);
	initializewindow(&cub, argv[1]);
	check_door(&cub);
	texturee(&cub);
	mlx_key_hook(cub.mlx, (mlx_keyfunc)key_press, &cub);
	mlx_cursor_hook(cub.mlx, (mlx_cursorfunc)mouse_handler, &cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);
	free_all(&cub, 1);
	return (0);
}
