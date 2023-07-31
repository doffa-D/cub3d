/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:58:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/20 19:51:40 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(void *param)
{
	t_struct	*cub;

	cub = (t_struct *)param;
	key_hendler(cub);
	cast_all_rays(cub);
	wall3d(cub);
	move_player(cub);
}
