/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:30:11 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/10 13:27:41 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	drow_aim(t_struct *cub)
{
	int	i;

	i = 0;
	while (i < 10 * 2)
	{
		mlx_put_pixel(cub->image, ((WIDTH / 2) - 10) + i, (HEIGHT / 2),
			0x33FF33FF);
		i++;
	}
	i = 0;
	while (i < 10 * 2)
	{
		mlx_put_pixel(cub->image, (WIDTH / 2), ((HEIGHT / 2) - 10) + i,
			0x33FF33FF);
		i++;
	}
}
