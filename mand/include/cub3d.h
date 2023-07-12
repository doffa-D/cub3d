/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:56:36 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 19:02:58 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_h
# define CUB3D_h

# include "../../MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 50
# define MINI_MAP 0.3
# define FOV_ANGLE (60 * (M_PI / 180))

# define MAP_NUM_ROWS 20
# define MAP_NUM_COLS 30
# define WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
# define NUM_RAYS WIDTH

typedef struct s_player
{
	float			x;
	float			y;
	int				turnDirection;
	int				walkDirection;
	float			rotationAngle;
}					t_player;

typedef struct s_Ray
{
	float			rayAngle;
	float			wallHitX;
	float			wallHitY;
	float			distance;
	int				wasHitVertical;
	int				facing_up;
	int				facing_down;
	int				facing_right;
	int				facing_left;
	int				wallHitContent;
}					t_rays;

typedef struct s_texture
{
	int32_t			**color_buffer;
	mlx_texture_t	*wall;
}					t_texture;

typedef struct s_struct
{
	int				*up;
	int				*down;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		player;
	t_rays			rays[NUM_RAYS];
	t_texture		the_north;
	t_texture		the_south;
	t_texture		the_west;
	t_texture		the_east;
	int				WINDOW_WIDTH;
	int				WINDOW_HEIGHT;
	char			**map;
	char			**texters;
}					t_struct;

int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int					has_wall_at(t_struct *cub, float posX, float posY);
void				draw_line(t_struct *cub, int x0, int y0, int x1, int y1,
						int color);
void				vertical_horizontal(t_struct *cub);
void				draw_wall(t_struct *cub, int x, int y, int color);
void				move_player(t_struct *cub);
void	store_pixels(t_texture *texture);
void				setup(t_struct *cub, char *PATH);
void				initializewindow(t_struct *cub, char *PATH);
void				init_position(t_struct *cub);
// float				distancePoints(float x1, float y1, float x2, float y2);
float				distancePoints(float x, float y);
float				normalizeAngle(float angle);
void				castRay(t_struct *cub, float rayAngle, int stripId);
void				castAllRays(t_struct *cub);
void				render(void *param);
void				background(t_struct *cub);
void				Wall3D(t_struct *cub);
void				texturee(t_struct *cub);
void				parccen_map(t_struct *cub, char *map_path);
void				arg_check(int argc, char **argv);
void				free_all_texters(t_struct *cub);
void				key_hendler(t_struct *cub);
void	free_back(char **back);
void	free_all(t_struct *cub);
#endif