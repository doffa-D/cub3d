/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:58:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 15:06:32 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(void *param)
{
	t_struct	*cub;

	cub = (t_struct *)param;
	key_hendler(cub);
	castAllRays(cub);
	Wall3D(cub);
	move_player(cub);
}
