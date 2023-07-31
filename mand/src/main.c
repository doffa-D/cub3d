/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:08:56 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/31 20:06:55 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_struct	cub;

	arg_check(argc, argv);
	initializewindow(&cub, argv[1]);
	texturee(&cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);
	free_all(&cub, 1);
	return (0);
}
