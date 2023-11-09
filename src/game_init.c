/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:24:54 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/08 22:02:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_to_window(t_game *game)
{
	if (validate_map(game) && flood_fill_map(game))
	{
		flood_fill_map(game);
		game->remain_c = ft_count_types(game, 'C');
		game->mlx = mlx_init(800, 600, "So_long", 1);
		if (!game->mlx)
			ft_error("Error\n Fail to init the window.\n");
		if (map_construct(game))
			draw_map(game);
		else
			ft_error("Error\n Fail to construct map.\n");
		return (TRUE);
	}
	else
		return (FALSE);
}

void	ft_map(t_game *game, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		ft_error("Error\n Check that the path to the file is correct.\n");
	game->map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_readmap(game->map, fd);
	game->arr_map = ft_mapsize(game->map);
	ft_append_down_up_map(game->map, game->arr_map);
	return ;
}

int	game_init(char *path)
{
	t_game		game;
	t_player 	player;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&player, sizeof(t_player));
	game.player = &player;
	ft_map(&game, path);
	ft_printf("MAPA CONTENT\n");
	ft_print_map_content(&game);
	ft_printf("\nMAPA DUP_CONTENT\n");
	ft_print_map(&game);
	if (ft_map_to_window(&game))
	{
		mlx_loop_hook(game.mlx, &ft_hook_close_window, &game);
		mlx_key_hook(game.mlx, &ft_hook_player_movement, &game);
		mlx_loop(game.mlx);
		ft_print_map(&game);
		ft_freegame(&game);
	}
	else
		ft_freegame_unit(&game);
	return (1);
}
