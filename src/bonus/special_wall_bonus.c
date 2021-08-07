#include "../../includes/bonus/cub3d_bonus.h"

int	special_wall(t_game *game, int color)
{
	if (game->life == 1)
		color = 0x2C2C2C;
	if (game->life == 0)
		color = 0x0C0C0D;
	if (game->sprite->win == 1 && game->life != 0)
		color = 0x2BC3C9;
	return (color);
}

int	special_floor(t_game *game, int color)
{
	if (game->life == 1)
		color = 0x0a0a0a;
	if (game->life == 0)
		color = 0x0a0a0a;
	if (game->sprite->win == 1 && game->life != 0)
		color = 0xACFDFF;
	return (color);
}

int	special_ceiling(t_game *game, int color)
{
	if (game->life == 1)
		color = 0x000000;
	if (game->life == 0)
		color = 0x000000;
	if (game->sprite->win == 1 && game->life != 0)
		color = 0x36b0b4;
	return (color);
}
