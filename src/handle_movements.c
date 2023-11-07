/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:17:39 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 13:17:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_player_movement(t_game *game, t_player *player)
{
	ft_create_new_player_image(game);
	mlx_image_to_window(game->mlx, game->p_img,
		player->p_x * SIZE_IMG, player->p_y * SIZE_IMG);
	game->n_mov++;
	ft_printf("\n Number of player moves: %i \n", game->n_mov);
}

void	ft_player_move_up(t_game *game, t_player *player)
{
	if (player->p_position->prev->content != '1')
	{	
		player->p_y -= 1;
		if (player->p_position->prev->content == 'C')
			ft_collect(game, player->p_position->prev);
		player->p_position->content = '0';
		player->p_position->prev->content = 'P';
		player->p_position = player->p_position->prev;
		update_player_movement(game, player);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if (player->p_position->dup_content == 'E')
		{
			validate_map(game, player);
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_down(t_game *game, t_player *player)
{
	if (player->p_position->next->content != '1')
	{
		player->p_y += 1;
		if (player->p_position->next->content == 'C')
			ft_collect(game, player->p_position->next);
		player->p_position->content = '0';
		player->p_position->next->content = 'P';
		player->p_position = player->p_position->next;
		update_player_movement(game, player);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if (player->p_position->dup_content == 'E')
		{
			validate_map(game, player);
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_left(t_game *game, t_player *player)
{
	if (player->p_position->up->content != '1')
	{
		player->p_x -= 1;
		if (player->p_position->up->content == 'C')
			ft_collect(game, player->p_position->up);
		player->p_position->content = '0';
		player->p_position->up->content = 'P';
		player->p_position = player->p_position->up;
		update_player_movement(game, player);
	}
	if (game->remain_c <= 0  && game->e_img->instances[0].enabled == 1)
	{
		if (player->p_position->dup_content == 'E')
		{
			validate_map(game, player);
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}

void	ft_player_move_right(t_game *game, t_player *player)
{
	if (player->p_position->down->content != '1')
	{
		player->p_x += 1;
		if (player->p_position->down->content == 'C')
			ft_collect(game, player->p_position->down);
		player->p_position->content = '0';
		player->p_position->down->content = 'P';
		player->p_position = player->p_position->down;
		update_player_movement(game, player);
	}
	if (game->remain_c <= 0 && game->e_img->instances[0].enabled == 1)
	{
		if (player->p_position->dup_content == 'E')
		{
			validate_map(game, player);
			ft_freegame(game);
			exit(0);
		}
	}
	return ;
}
