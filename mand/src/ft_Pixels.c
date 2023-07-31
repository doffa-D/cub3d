/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:39:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/29 12:40:10 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t	genirat_pixel(int32_t read, int32_t gren, int32_t blue, int32_t eff)
{
	return (read << 24 | gren << 16 | blue << 8 | eff);
}

void	store_pixels(t_texture *texture, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	texture->color_buffer = ft_calloc(texture->wall->height, sizeof(int32_t *));
	while (i < (int)texture->wall->height)
			texture->color_buffer[i++] = ft_calloc(texture->wall->width,
				sizeof(int32_t));
	i = 0;
	while (i < (int)(texture->wall->width
		* texture->wall->height * texture->wall->bytes_per_pixel))
	{
		texture->color_buffer[y][x] = genirat_pixel(texture->wall->pixels[i],
				texture->wall->pixels[i + 1], texture->wall->pixels[i + 2],
				texture->wall->pixels[i + 3]);
		x++;
		if (x >= (int)texture->wall->width)
		{
			x = 0;
			y++;
		}
		i += texture->wall->bytes_per_pixel;
	}
}
