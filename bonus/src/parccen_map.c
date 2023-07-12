/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parccen_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouakhro <nouakhro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:50:00 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:03 by nouakhro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int calculat_linght(char *map_path)
{
    char *map;
    int i = 0;
    int fd = open(map_path, O_RDONLY);
    if(fd < 0)
    {
        perror("fd : ");
        exit(0);
    }
    while (1)
    {
        map = get_next_line(fd);
        if(!map)
            break;
        free(map);
        i++;
    }
    close(fd);
    return i;
}


void full_path(t_struct *cub,char *map_path)
{
    int i = 0;
    int j = 0;
    int fd = open(map_path, O_RDONLY);
    if(fd < 0)
    {
        perror("fd : ");
        exit(1);
    }
    char *trim;
    char *map_tmp;
    while (1)
    {
        map_tmp = get_next_line(fd);
        if(!map_tmp)
            break;
        trim = ft_strtrim(map_tmp," \n");
        if(*trim)
        {
            if(i <= 5)
            {
                cub->texters[i] = ft_strdup(map_tmp);
                if(i == 5)
                {
                    if(cub->texters[i][0] != 'C')
                    {
                        printf("not not\n");
                        exit(0);
                    }
                    else
                        cub->texters[i + 1] = 0;
                }
            }
            if(i > 5)
            {
                cub->map[j] = ft_strdup(map_tmp);
                j++;
            }
            i++;
        }
        free(trim);
        free(map_tmp);
    }
    cub->map[j] = 0;
    close(fd);
}

void    parccen_map(t_struct *cub,char *map_path)
{
    int i;
    int j;
    int index;
    char **split_space;
    int line = calculat_linght(map_path);
    cub->map = malloc(sizeof(char *) * line - 7);
    cub->texters = malloc(sizeof(char *) * 7);
    int player_is_exist = 0;
    full_path(cub,map_path);
    i = 0;
    while (cub->texters[i])
    {
        j = 0;
        split_space = ft_split(cub->texters[i], ' ');
        while (split_space[j])
        {
            if(i == 0 && j == 0 && ft_strncmp(split_space[j], "NO", 3))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 1 && j == 0 && ft_strncmp(split_space[j], "SO", 3))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 2 && j == 0 && ft_strncmp(split_space[j], "WE", 3))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 3 && j == 0 && ft_strncmp(split_space[j], "EA", 3))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 4 && j == 0 && ft_strncmp(split_space[j], "F", 2))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 5 && j == 0 && ft_strncmp(split_space[j], "C", 2))
            {
                printf("error : texters\n");
                exit(1);
            }
            if(i == 4 && j == 1)
            {
                char **textrs;
                int index = 0;
                if(split_space[j])
                {
                    textrs = ft_split(split_space[j], ',');
                    while (textrs[index])
                    {
                        if(ft_atoi(textrs[index]) > 255 || ft_atoi(textrs[index]) < 0)
                        {
                            printf("error : texters\n");
                            exit(1);
                        }
                        free(textrs[index]);
                        index++;
                    }
                    free(textrs);
                }
            }
            if(i == 5 && j == 1)
            {
                char **textrs;
                index = 0;
                if(split_space[j])
                {
                    textrs = ft_split(split_space[j], ',');
                    while (textrs[index])
                    {
                        if(ft_atoi(textrs[index]) > 255 || ft_atoi(textrs[index]) < 0)
                        {
                            printf("error : texters\n");
                            exit(1);
                        }
                        free(textrs[index]);
                        index++;
                    }
                    free(textrs);
                }
            }
            free(split_space[j]);
            j++;
        }
        free(split_space);
        i++;
    }
    // printf("%d\n",index);
    // exit(0);
    i = 0;
    while (cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(ft_strchr("NWESP", cub->map[i][j]))
            {
                // cub->player.x = ((j * TILE_SIZE) + TILE_SIZE / 2) * MINI_MAP;
                // cub->player.y = ((i * TILE_SIZE) + TILE_SIZE / 2) * MINI_MAP;
                if(cub->map[i][j + 1] == ' ' || cub->map[i][j + 1] == '\n' || cub->map[i][j + 1] == '\0')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                if(j == 0 || cub->map[i][j - 1] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                if(i == 0 || cub->map[i - 1][j] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                if(i + 1 == line - 8 || cub->map[i + 1][j] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                if((size_t)j >= ft_strlen(cub->map[i - 1]) - 1)
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                if(i + 1 < line - 8 && (size_t)j >= ft_strlen(cub->map[i + 1]) - 1)
                {
                    printf("%s\n",cub->map[i]);
                    printf("%d\n", j);
                    printf("player outside\n");
                    exit(1);
                }
                player_is_exist++;
            }
            if(player_is_exist > 1)
            {
                printf("%s\n", cub->map[i]);
                printf("%d\n", j);
                printf("%d\n", i);
                printf("double player\n");
                exit(1);
            }
            if(!ft_strchr("10NWESPD \n", cub->map[i][j]))
            {
                printf("%s\n", cub->map[i]);
                printf("%d\n", j);
                printf("%d\n", i);
                printf("another caracter\n");
                exit(1);
            }
            if(cub->map[i][j] == '0')
            {
                if(cub->map[i][j + 1] == ' ' || cub->map[i][j + 1] == '\n' || cub->map[i][j + 1] == '\0')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map1\n");
                    exit(1);
                }
                if(j == 0 || cub->map[i][j - 1] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map2\n");
                    exit(1);
                }
                if(i == 0 || cub->map[i - 1][j] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map3\n");
                    exit(1);
                }
                if(i + 1 == line - 8 || cub->map[i + 1][j] == ' ')
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map4\n");
                    exit(1);
                }
                if((size_t)j >= ft_strlen(cub->map[i - 1]) - 1)
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map6\n");
                    exit(1);
                }
                if(i + 1 < line - 8 && (size_t)j >= ft_strlen(cub->map[i + 1]) - 1)
                {
                    printf("%s\n", cub->map[i]);
                    printf("%d\n", j);
                    printf("map5\n");
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
    while(cub->map[cub->WINDOW_HEIGHT])
    {
        if(cub->WINDOW_WIDTH < (int)ft_strlen(cub->map[cub->WINDOW_HEIGHT]))
            cub->WINDOW_WIDTH = (int)ft_strlen(cub->map[cub->WINDOW_HEIGHT]);
        cub->WINDOW_HEIGHT++;
    }
    cub->map[cub->WINDOW_HEIGHT] = NULL;
    cub->WINDOW_WIDTH -= 1;
}