/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:34:09 by marvin            #+#    #+#             */
/*   Updated: 2023/11/06 13:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_flood_fill(t_game *game, t_player *player, t_map *node)
{

	if (node->next == NULL || node->prev == NULL || node->down == NULL || node->up == NULL || node->dup_content == '1')
		return (FALSE);
	node->dup_content = '1';
	if (ft_flood_fill(game, player, node->next) || ft_flood_fill(game, player, node->prev) \
	|| ft_flood_fill(game, player, node->up) || ft_flood_fill(game, player, node->down))
	{
		return (TRUE);
	}
	return (0);
}

void	ft_print_map_y(t_game *game, int *xy)
{
	while (xy[1] < game->arr_map[1])
	{
		ft_printf("%c", game->temp->dup_content);
		if (game->temp->next == NULL)
		{
			ft_printf("\n");
			break ;
		}
		game->temp = game->temp->next;
		xy[1]++;
	}
	return ;
}

void	ft_print_map(t_game *game)
{
	int		x_y[2];

	x_y[0] = 0;
	x_y[1] = 0;
	game->temp = *(game->map);
	while (x_y[0] < game->arr_map[0])
	{
		ft_print_map_y(game, x_y);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		x_y[1] = 0;
		x_y[0]++;
	}
}

//int	ft_valid_route(t_game *game)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	y = 0;
//	game->temp = *(game->map);
//	while (x < game->arr_map[0])
//	{
//		while (y < game->arr_map[1])
//		{
//			if (game->temp->dup_content != '1' && game->temp->dup_content != '0')
//				return (FALSE);
//			game->temp = game->temp->next;
//			y++;
//		}
//		x++;
//	}
//	return (TRUE);
//}
//
//int	ft_valid_edges(t_game *game)
//{
//	int	x;
//	int	y;
//
//	x = 0;
//	y = 0;
//	game->temp = *(game->map);
//	while (x < game->arr_map[0])
//	{
//		if (game->temp->dup_content != '1' || game->temp->up->dup_content != '1')
//			return (FALSE);
//		while (y < game->arr_map[1])
//		{
//			if (game->temp->dup_content == '1' || game->temp->dup_content)
//			y++;
//		}
//		x++;
//	}
//	return (TRUE);
//}

void	validate_map(t_game *game, t_player *player)
{
	ft_flood_fill(game, player, player->p_position);
	ft_print_map(game);
	//if (!ft_valid_route(game) && !ft_valid_edges)
	//{
	//	ft_error("Error\n This map is invalid: it must be enclosed by walls" \
	//	"and the player must be able to collect and exit \n");
	//}
	//else
	return ;
}