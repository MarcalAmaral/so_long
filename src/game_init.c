/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:24:54 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/08 17:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_count_elem(t_game *game, char type)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->temp = *(game->map);
	while (x < game->arr_map[0])
	{
		while (y < game->arr_map[1])
		{
			if (game->temp->content == type)
				game->remain_c++;
			if (game->temp->next == NULL)
			{
				game->temp = ft_lstfirst_map(game->temp);
				break ;
			}
			game->temp = game->temp->next;
			y++;
		}
		game->temp = game->temp->down;
		x++;
		y = 0;
	}
}

int	ft_map_to_window(t_game *game)
{
	if (validate_map(game))
	{
		//flood_fill_map(game);
		ft_count_elem(game, 'C');
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
	}
	else
		ft_freegame_unit(&game);
	return (1);
}
