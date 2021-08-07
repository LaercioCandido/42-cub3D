#include "../../includes/bonus/cub3d_bonus.h"

char	*type_define(int tex, int id)
{
	char	*type;
	char	*temp;

	type = ft_itoa(id);
	if (tex == SP)
		temp = ft_strjoin("./text/sprites/sprite", type);
	else if (tex == LIFE)
		temp = ft_strjoin("./text/textures/hud/hearts_", type);
	free(type);
	type = ft_strjoin(temp, ".xpm");
	free(temp);
	return (type);
}

void	load_sprite(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i < game->num_sprite)
	{
		type = type_define(SP, game->sprite[i].index);
		game->sprite[i].tex.img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->sprite[i].tex.tex_width,
				&game->sprite[i].tex.tex_height);
		if (!(game->sprite[i].tex.img))
			return_error(-22);
		game->sprite[i].tex.addr = mlx_get_data_addr(game->sprite[i].tex.img,
				&game->sprite[i].tex.bpp, &game->sprite[i].tex.l_len,
				&game->sprite[i].tex.endian);
		if (!(game->sprite[i].tex.addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}

void	load_life(t_game *game)
{
	int		i;
	char	*type;

	i = 0;
	while (i <= 3)
	{
		type = type_define(LIFE, i);
		game->life_tex[i].img = mlx_xpm_file_to_image(game->data.mlx, type,
				&game->life_tex[i].tex_width, &game->life_tex[i].tex_height);
		if (!(game->life_tex[i].img))
			return_error(-22);
		game->life_tex[i].addr = mlx_get_data_addr(game->life_tex[i].img,
				&game->life_tex[i].bpp, &game->life_tex[i].l_len,
				&game->life_tex[i].endian);
		if (!(game->life_tex[i].addr))
			return_error(-22);
		i++;
		free(type);
		type = NULL;
	}
}
