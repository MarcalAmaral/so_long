/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:06:48 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:02 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_while_y_count_types(t_game *game, char type, int *xyi)
{
	while (xyi[1] < game->arr_map[1])
	{
		if (game->temp->content == type)
			xyi[2]++;
		if (game->temp->next == NULL)
			break ;
		game->temp = game->temp->next;
		xyi[1]++;
	}
	return ;
}

int	ft_count_types(t_game *game, char type)
{
	int	xyi[3];

	xyi[0] = 0;
	xyi[1] = 0;
	xyi[2] = 0;
	game->temp = *(game->map);
	while (xyi[0] < game->arr_map[0])
	{
		ft_while_y_count_types(game, type, xyi);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		xyi[1] = 0;
		xyi[0]++;
	}
	return (xyi[2]);
}
