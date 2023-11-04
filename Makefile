# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 12:19:16 by hdagdagu          #+#    #+#              #
#    Updated: 2023/07/31 20:23:49 by nouakhro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
mlx_lib = MLX42/libmlx42.a
DEPENDENCIES = $(mlx_lib) -framework Cocoa -framework OpenGL -framework IOKit
INCLUDES = include/cub3d.h
NAME = cub3D
NAMEB = cub3D_bonus
CH = mand
CHB = bonus
LIBFT = libft
glfw = $(shell brew --prefix glfw)



FILES = $(addprefix mand/src/, main check_wall ft_Pixels initialize key_handler player parccen_map_utils parccen_map wall_utils Ray-Casting Ray_Casting_utils Ray_Casting_utils1 render wall texture free_all parccen_check_error parccen_map_v2)
SRC = $(FILES:=.c)
OBJE = $(SRC:.c=.o)


FILESB = $(addprefix bonus/src/, main check_wall draw_line draw_aim draw_map ft_Pixels parccen_map_utils initialize key_handler wall_utils player parccen_map Ray-Casting Ray_Casting_utils Ray_Casting_utils1 render wall texture free_all parccen_check_error parccen_map_v2)
SRCB = $(FILESB:=.c)
OBJEB = $(SRCB:.c=.o)


all: $(NAME)

$(NAME): $(OBJE) $(CH)/$(INCLUDES)
	@make -C $(CH)/$(LIBFT)
	@$(CC) $(CFLAGS) $(CH)/$(LIBFT)/libft.a -o $(NAME) $(OBJE) $(DEPENDENCIES) -lglfw -L "$(glfw)/lib"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

bonus: $(NAMEB)

$(NAMEB): $(OBJEB) $(CHB)/$(INCLUDES)
	@make -C $(CHB)/$(LIBFT)
	@$(CC) $(CFLAGS) $(CHB)/$(LIBFT)/libft.a -o $(NAMEB) $(OBJEB) $(DEPENDENCIES) -lglfw -L "$(glfw)/lib"

re: fclean
	@make all

clean:
	@rm -rf $(OBJE) $(OBJEB)
	@make -C $(CH)/$(LIBFT) clean
	@make -C $(CHB)/$(LIBFT) clean

fclean: clean
	@rm -rf $(NAME) $(NAMEB)

.PHONY: all re clean fclean
