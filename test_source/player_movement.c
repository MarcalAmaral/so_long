/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:37:50 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/01 18:25:15 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	p_position(t_window *window, t_player *player)
{
	player->p_position = *(window->map);
	while (player->p_x < window->arr_map[0])
	{
		while (player->p_y < window->arr_map[1])
		{
			if (player->p_position->content == 'P')
				return ;
			if (player->p_position->next == NULL)
			{
				player->p_position = ft_lstfirst_map(player->p_position);
				break ;
			}
			player->p_position = player->p_position->next;
			player->p_y++;
		}
		player->p_position = player->p_position->down;
		player->p_x++;
		player->p_y = 0;
	}
	ft_printf("P não encontrado, mapa inválido, encerrando execução do jogo.");
	return ;
}

//static	void	update_player_movement(t_window *window, t_player *player, char *path)
//{
//	create_new_player_image(window, path);
//	mlx_image_to_window(window->mlx, window->player_img, player->p_x * SIZE_IMAGE, player->p_y * SIZE_IMAGE);
//	player->n_mov++;
//	ft_printf("\n Number of player moves: %i \n", player->n_mov);
//}

//void	player_move_up(t_window *window, t_player *player)
//{
//	update_player_movement(window, player, "./textures/player_idle/up/tile000.png");
//	if (player->p_position->up->content == 'C')
//		collect(window, game);
//	else if (game->collectable_number <= 0
//			&& game->map[game->player_y][game->player_x] == 'E')
//	{
//		free_game(window, game);
//		exit(0);
//	}
//}
//
//void	player_move_down(t_window *window, t_player *player)
//{
//	update_player_movement(window, player, "./textures/player_idle/down/tile000.png");
//	if (player->p_position->down->content == 'C')
//		collect(window, game);
//	else if (game->collectable_number <= 0
//			&& game->map[game->player_y][game->player_x] == 'E')
//	{
//		free_game(window, game);
//		exit(0);
//	}
//}
//
//void	player_move_right(t_window *window, t_player *player)
//{
//	update_player_movement(window, player, "./textures/player_idle/right/tile000.png");
//	if (player->p_position->next->content == 'C')
//		collect(window, game);
//	else if (game->collectable_number <= 0
//			&& game->map[game->player_y][game->player_x] == 'E')
//	{
//		free_game(window, game);
//		exit(0);
//	}
//}
//
//void	player_move_left(t_window *window, t_player *player)
//{
//	update_player_movement(window, player, "./textures/player_idle/left/tile000.png");
//	if (player->p_position->prev->content == 'C')
//		collect(window, game);
//	else if (game->collectable_number <= 0
//			&& game->map[game->player_y][game->player_x] == 'E')
//	{
//		free_game(window, game);
//		exit(0);
//	}
//}

void	num_collectables(t_window *window, t_game *game)
{
	t_map		*node;
	static int	x;

	x = 0;
	node = *(window->map);
	while (x++ < (window->arr_map[0]))
	{
		if (node->next == NULL)
		{
			node = ft_lstfirst_map(node);
			node = node->down;
		}
		if (node->content == 'C')
			game->n_collectables++;
		node = node->next;
	}
	return ;
}

int	main(void)
{
	t_player	player;
	t_window	window;
	t_game		game;
	int			fd;

	fd = open("maps/map.ber", O_RDONLY);
	ft_bzero(&player, sizeof(t_player));
	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&window, sizeof(t_window));
	window.map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_readmap(window.map, fd);
	window.arr_map = ft_mapsize(window.map);
	ft_append_down_up_map(window.map, window.arr_map);
	p_position(&window, &player);
	num_collectables(&window, &game);
	ft_printf("Temos ao total %d coletaveis\n", game.n_collectables);
	//ft_printf("player x = %d, player y = %d", player.p_x, player.p_y);
	//ft_printf("\nchar %c\n", player.p_position->content);
	return (0);
}
