/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:17:12 by marvin            #+#    #+#             */
/*   Updated: 2023/11/08 16:17:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	ft_print_map_y_content(t_game *game, int *xy)
{
	while (xy[1] < game->arr_map[1])
	{
		ft_printf("%c", game->temp->content);
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

void	ft_print_map_content(t_game *game)
{
	int		x_y[2];

	x_y[0] = 0;
	x_y[1] = 0;
	game->temp = *(game->map);
	while (x_y[0] < game->arr_map[0])
	{
		ft_print_map_y_content(game, x_y);
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		x_y[1] = 0;
		x_y[0]++;
	}
}
