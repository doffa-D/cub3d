/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:08:56 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 16:07:33 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_struct	cub;
	t_player	player;

	arg_check(argc, argv);
	cub.player = &player;
	initializewindow(&cub, argv[1]);
	texturee(&cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);
	free_all(&cub);
	system("leaks cub3d > file.txt && grep ROOT LEAK:");
	return (0);
}
