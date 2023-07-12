/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:39:43 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 19:03:24 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	store_pixels(t_texture *texture)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	texture->color_buffer = ft_calloc(texture->wall->height , sizeof(int32_t *));
	while (i < (int)texture->wall->height)
		texture->color_buffer[i++] = ft_calloc(texture->wall->width , sizeof(int32_t));
	i = 0;
	while (i < (int)(texture->wall->width * texture->wall->height \
			* texture->wall->bytes_per_pixel))
	{
		texture->color_buffer[y][x] = ft_pixel(texture->wall->pixels[i], texture->wall->pixels[i + 1],
				texture->wall->pixels[i + 2], texture->wall->pixels[i + 3]);
		x++;
		if (x >= (int)texture->wall->width)
		{
			x = 0;
			y++;
		}
		i += texture->wall->bytes_per_pixel;
	}
}
