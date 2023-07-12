/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:08:56 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:55:39 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				if (!((cub->map[i - 1][y] == '1' && cub->map[i + 1][y] == '1'
					&& (cub->map[i][y - 1] == '0' || cub->map[i][y
					+ 1] == '0')) || (cub->map[i][y - 1] == '1'
					&& cub->map[i][y + 1] == '1' && (cub->map[i
					- 1][y] == '0' || cub->map[i + 1][y] == '0'))))
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
	texturee(&cub);
	check_door(&cub);
	mlx_key_hook(cub.mlx, (mlx_keyfunc)key_press, &cub);
	mlx_cursor_hook(cub.mlx, (mlx_cursorfunc)mouse_handler, &cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);
	free_all(&cub);
	return (0);
}
