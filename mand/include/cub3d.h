/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:56:36 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/31 20:26:19 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# define MAP_NUM_ROWS 20
# define MAP_NUM_COLS 30
# define WIDTH 1500
# define HEIGHT 1000
# define NUM_RAYS 1500
# define HORIZOMNTAL 0
# define VERTICAL 1

typedef struct s_player
{
	float			x;
	float			y;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
}					t_player;

typedef struct s_wall_3d
{
	float			final_dist;
	float			x_wall_cordinate;
	float			x_dor_cordinate;
	float			started_point;
	float			px_img_px_wind;
	float			error_wall;
	float			y_pixel_cordinate;
}					t_wall_3d;

typedef struct s_steps
{
	float			x;
	float			y;
	float			start_x;
	float			start_y;
	float			horz_wall_hit;
	float			horz_y;
	float			horz_x;
	float			is_wal;
	float			vert_wall_hit;
	float			vert_y;
	float			vert_x;
	float			horz_distance;
	float			vert_distance;
}					t_steps;

typedef struct s_drow_line
{
	int				checkx;
	int				checky;
	float			x;
	float			y;
	int				dx;
	int				dy;
	int				steps;
	int				dor_x;
	int				dor_y;
}					t_drow_line;
typedef struct s_Ray
{
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				was_hit_vertical;
	int				facing_up;
	int				facing_down;
	int				facing_right;
	int				facing_left;
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
	double			old_x;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		player;
	t_rays			rays[NUM_RAYS];
	t_texture		the_north;
	t_texture		the_south;
	t_texture		the_west;
	t_texture		the_east;
	int				window_width;
	int				window_height;
	int				map_separeate;
	char			**map;
	char			**texters;

	t_drow_line		line;
}					t_struct;

int32_t				genirat_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int					has_wall_at(t_struct *cub, float posX, float posY);
void				vertical_horizontal(t_struct *cub);
void				draw_wall(t_struct *cub, int x, int y, int color);
void				move_player(t_struct *cub);
void				store_pixels(t_texture *texture, int i);
void				setup(t_struct *cub, char *PATH);
void				initializewindow(t_struct *cub, char *PATH);
void				init_position(t_struct *cub);
float				distance_points(float x, float y);
float				normalize_angle(float angle);
void				cast_ray(t_struct *cub, float ray_angle, int strip_id);
void				cast_all_rays(t_struct *cub);
void				render(void *param);
void				background(t_struct *cub);
void				wall3d(t_struct *cub);
void				texturee(t_struct *cub);
void				parccen_map(t_struct *cub, char *map_path);
void				arg_check(int argc, char **argv);
void				free_all_texters(t_struct *cub);
void				key_hendler(t_struct *cub);
void				free_back(char **back);
void				free_all(t_struct *cub, int x);
void				calculate_with_height(t_struct *cub);
void				full_path(t_struct *cub, char *map_path);
int					calculat_linght(char *map_path);
void				check_map_error(t_struct *cub, int i, int j);
void				check_error_texters(char **split_texters, int j, int i);
void				print_error(void);
void				set_up_order_utils3(t_struct *cub, \
					int i, char *str, int number);
void				set_up_order_utils2(t_struct *cub, int *i);
void				check_color(char **split_texters, int j);
void				set_up_order(t_struct *cub);
void				set_up_order_utils1(t_struct *cub, int *i);
void				check_texters(t_struct *cub);
int					calculat_map(t_struct *cub);
void				instialation_varables(t_struct *cub, t_wall_3d *var_3d_wall,
						int i);
void				check_map(t_struct *cub);
void				clacul_steps(t_struct *cub, int strip_id, t_steps *step,
						int check_ver_horz);
void				calculate_start_cordinate(t_struct *cub, int strip_id,
						t_steps *step, int check_ver_horz);
void				set_up_face(t_struct *cub, float ray_angle, int strip_id);
int					open_close_horz_dor(t_struct *cub, int strip_id,
						t_steps *vars);
int					vert_dor_close(t_struct *cub, int strip_id, t_steps *vars);
int					horz_dor_close(t_struct *cub, int strip_id, t_steps *vars);
void				instialation_cord_pixel(t_struct *cub,
						t_wall_3d *var_3d_wall, int i);
int					open_close_vert_dor(t_struct *cub, int strip_id,
						t_steps *vars);
int					hit_horz_wall(t_struct *cub, t_steps *vars, int strip_id);
void				horz_img(t_struct *cub, t_wall_3d var_3d_wall, int i,
						int j);
void				verical_img(t_struct *cub, t_wall_3d var_3d_wall, int i,
						int j);
int					hit_vert_wall(t_struct *cub, t_steps *vars, int strip_id);
void				printf_error_v2(t_struct *cub);

#endif