/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parccen_check_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:28:54 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/31 19:56:44 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}

void	printf_error_v2(t_struct *cub)
{
	printf("Error\n");
	free_all(cub, 0);
	exit(1);
}

void	check_error_texters(char **split_texters, int j, int i)
{
	if (i == 0 && j == 0 && ft_strncmp(split_texters[j], "NO", 4))
		print_error();
	if (i == 1 && j == 0 && ft_strncmp(split_texters[j], "SO", 4))
		print_error();
	if (i == 2 && j == 0 && ft_strncmp(split_texters[j], "WE", 4))
		print_error();
	if (i == 3 && j == 0 && ft_strncmp(split_texters[j], "EA", 4))
		print_error();
	if (i == 4 && j == 1)
		check_color(split_texters, j);
	if (i == 5 && j == 1)
		check_color(split_texters, j);
	free(split_texters[j]);
}

void	check_map_error(t_struct *cub, int i, int j)
{
	static int	count_player;

	while (cub->map[i][++j])
	{
		if (ft_strchr("NWES0", cub->map[i][j]))
		{
			if (ft_strchr("NWES", cub->map[i][j]))
				count_player++;
			if (i == 0 || j == 0 || i == calculat_map(cub) - 1
				|| count_player > 1 || (size_t)j >= ft_strlen(cub->map[i - 1]) \
				- 1 || (size_t)j >= ft_strlen(cub->map[i + 1]) - 1)
				print_error();
			if (cub->map[i][j + 1] == ' ' || cub->map[i][j + 1] == '\n'
				|| cub->map[i][j + 1] == '\0' || cub->map[i][j - 1] == ' '
				|| cub->map[i - 1][j] == ' ' || cub->map[i + 1][j] == ' ')
				print_error();
		}
		else if (!ft_strchr("NWES01 \n", cub->map[i][j]))
			print_error();
	}
}
