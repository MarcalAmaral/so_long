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

int ft_flood_fill(t_game *game, t_map *node)
{

	if (node->next == NULL || node->prev == NULL || node->down == NULL || node->up == NULL || node->dup_content == '1')
		return (FALSE);
	node->dup_content = '1';
	if (ft_flood_fill(game, node->next) || ft_flood_fill(game, node->prev) \
	|| ft_flood_fill(game, node->up) || ft_flood_fill(game, node->down))
	{
		return (TRUE);
	}
	return (0);
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
//
int	flood_fill_map(t_game *game)
{
	p_position(game, game->player);
	ft_flood_fill(game, game->player->p_position);
	return (0);
}