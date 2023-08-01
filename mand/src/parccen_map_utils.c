/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parccen_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:21:16 by nouakhro          #+#    #+#             */
/*   Updated: 2023/08/01 10:36:09 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_up_order_utils3(t_struct *cub, int i, char *str, int number)
{
	char	*trim;

	if (!ft_strncmp(cub->texters[number], str, ft_strlen(str)))
		print_error("Duplicate Character");
	trim = cub->texters[number];
	cub->texters[number] = cub->texters[i];
	cub->texters[i] = trim;
}

void	set_up_order_utils1(t_struct *cub, int *i)
{
	if (*i != 3 && !ft_strncmp(cub->texters[*i], "EA ", 3))
	{
		set_up_order_utils3(cub, *i, "EA ", 3);
		*i = 0;
	}
	if (*i != 4 && !ft_strncmp(cub->texters[*i], "F ", 2))
	{
		set_up_order_utils3(cub, *i, "F ", 4);
		*i = 0;
	}
	if (*i != 5 && !ft_strncmp(cub->texters[*i], "C ", 2))
	{
		set_up_order_utils3(cub, *i, "C ", 5);
		*i = 0;
	}
}

void	set_up_order_utils2(t_struct *cub, int *i)
{
	if (*i != 0 && !ft_strncmp(cub->texters[*i], "NO ", 3))
	{
		set_up_order_utils3(cub, *i, "NO ", 0);
		*i = 0;
	}
	if (*i != 1 && !ft_strncmp(cub->texters[*i], "SO ", 3))
	{
		set_up_order_utils3(cub, *i, "SO ", 1);
		*i = 0;
	}
	if (*i != 2 && !ft_strncmp(cub->texters[*i], "WE ", 3))
	{
		set_up_order_utils3(cub, *i, "WE ", 2);
		*i = 0;
	}
}

void	set_up_order(t_struct *cub)
{
	int	i;

	i = 0;
	while (cub->texters[i])
	{
		set_up_order_utils2(cub, &i);
		set_up_order_utils1(cub, &i);
		i++;
	}
}
