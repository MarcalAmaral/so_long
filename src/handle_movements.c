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

void	ft_player_move_up(t_window *window, t_player *player);
void	ft_player_move_down(t_window *window, t_player *player);
void	ft_player_move_left(t_window *window, t_player *player);
void	ft_player_move_right(t_window *window, t_player *player);

void	update_player_movement(t_window *window, t_player *player)
{
	ft_create_new_player_image(window);
	mlx_image_to_window(window->mlx, window->p_img,
		player->p_x * SIZE_IMG, player->p_y * SIZE_IMG);
	window->n_mov++;
	ft_printf("\n Number of player moves: %i \n", window->n_mov);
}

void	ft_player_move_up(t_window *window, t_player *player)
{
	if (player->p_position->prev->content != '1')
	{	
		player->p_y -= 1;
		if (player->p_position->prev->content == 'C')
			ft_collect(window, player, "prev");
		player->p_position->content = '0';
		player->p_position->prev->content = 'P';
		player->p_position = player->p_position->prev;
		update_player_movement(window, player);
	}
	else
		return ;
}

void	ft_player_move_down(t_window *window, t_player *player)
{
	if (player->p_position->next->content != '1')
	{
		player->p_y += 1;
		if (player->p_position->next->content == 'C')
			ft_collect(window, player, "next");
		player->p_position->content = '0';
		player->p_position->next->content = 'P';
		player->p_position = player->p_position->next;
		update_player_movement(window, player);
	}
	else
		return ;
}

void	ft_player_move_left(t_window *window, t_player *player)
{
	if (player->p_position->up->content != '1')
	{
		player->p_x -= 1;
		if (player->p_position->up->content == 'C')
			ft_collect(window, player, "up");
		player->p_position->content = '0';
		player->p_position->up->content = 'P';
		player->p_position = player->p_position->up;
		update_player_movement(window, player);
	}
	else
		return ;
}

void	ft_player_move_right(t_window *window, t_player *player)
{
	if (player->p_position->down->content != '1')
	{
		player->p_x += 1;
		if (player->p_position->down->content == 'C')
			ft_collect(window, player, "down");
		player->p_position->content = '0';
		player->p_position->down->content = 'P';
		player->p_position = player->p_position->down;
		update_player_movement(window, player);
	}
	else
		return ;
}
