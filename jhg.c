typedef struct s_player
{
	float			x;
	float			y;
	int				turnDirection;
	int				walkDirection;
	float			rotationAngle;
}					t_player;

typedef struct s_struct
{

	t_player		*player;

}					t_struct;
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_struct	cub;
	printf("vdfvdfvdfvdfdfvdf\n");
	cub.player->x = 0;
	cub.player->y = 0;
	return (0);
}
