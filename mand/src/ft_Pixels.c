/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:39:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/11 15:56:33 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	store_pixels(int32_t ***color, mlx_texture_t *texture)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	(*color) = ft_calloc(texture->height , sizeof(int32_t *));
	while (i < (int)texture->height)
		(*color)[i++] = ft_calloc(texture->width , sizeof(int32_t));
	i = 0;
	while (i < (int)(texture->width * texture->height \
			* texture->bytes_per_pixel))
	{
		(*color)[y][x] = ft_pixel(texture->pixels[i], texture->pixels[i + 1],
				texture->pixels[i + 2], texture->pixels[i + 3]);
		x++;
		if (x >= (int)texture->width)
		{
			x = 0;
			y++;
		}
		i += texture->bytes_per_pixel;
	}
}
