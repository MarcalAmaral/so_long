/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:56:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 12:56:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

void    ft_hook_close_window(void *param)
{
    t_window *window;

    window = (t_window *)param;
    if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(window->mlx);
    }
}

void    ft_hook_player_movement(mlx_key_data_t keydata, void *param)
{
    t_window *window;
    t_player *player;
    
    window = (t_window *) param;
	player = (t_player *) ft_calloc(1, sizeof(t_player *));
	p_position(window, player);
    if (((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP)) && keydata.action == MLX_PRESS)
        ft_player_move_up(window, player);
    if (((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN)) && keydata.action == MLX_PRESS)
        ft_player_move_down(window, player);
    if (((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT)) && keydata.action == MLX_PRESS)
        ft_player_move_left(window, player);
    if (((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT)) && keydata.action == MLX_PRESS)
        ft_player_move_right(window, player);
    return ;
}