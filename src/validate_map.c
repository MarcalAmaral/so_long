/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:20:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/05 12:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_map_is_rectangle(t_game *game);

int	ft_map_is_rectangle(t_game *game)
{
	if ((game->arr_map[0] != game->arr_map[1])
		&& validate_map_is_rectangle(game->map))
		return (FALSE);
	else
	{
		ft_printf("ERROR\n");
		ft_printf("- Map is not retangular, please input a retangular map.\n");
		return (TRUE);
	}
}

int	validate_map_is_rectangle(t_game *game)
{
	int		lenght;
	int		lenght_prev_line;

	game->temp = *(game->map);
	lenght = 0;
	lenght_prev_line = 0;
	while (game->temp)
	{
		if (game->temp->next == NULL)
		{
			if (lenght_prev_line == 0)
				lenght_prev_line = lenght;
			if (lenght_prev_line != lenght)
				break ;
			game->temp = ft_lstfirst_map(game->temp);
			if (game->temp->down != NULL)
				game->temp = game->temp->down;
			else
				return (TRUE);
			lenght = 0;
		}
		lenght++;
		game->temp = game->temp->next;
	}
	return (FALSE);
}

int	ft_validate_tileset(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->temp = *(game->map);
	while (x < game->arr_map[0])
	{
		while (y < game->arr_map[1])
		{
			if (game->temp->content != 'C' && game->temp->content != 'P'
				&& game->temp->content != '0' && game->temp->content != 'E'
				&& game->temp->content != '1')
				return (TRUE);
			if (game->temp->next == NULL)
				break ;
			game->temp = game->temp->next;
			y++;
		}
		game->temp = ft_lstfirst_map(game->temp);
		game->temp = game->temp->down;
		y = 0;
		x++;
	}
	return (FALSE);
}

int	ft_validate_types(t_game *game)
{
	int	types;

	types = ft_count_types(game, 'C');
	if (types < 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the map ");
		ft_printf("passed has at least one collectible.\n");
		return (TRUE);
	}
	types = ft_count_types(game, 'P');
	if (types < 1 || types > 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the map ");
		ft_printf("passed has at least one player.\n");
		return (TRUE);
	}
	types = ft_count_types(game, 'E');
	if (types < 1 || types > 1)
	{
		ft_printf("Error\n-Invalid map, please make sure the passed ");
		ft_printf("map has at least one exit and only one.\n");
		return (TRUE);
	}
	return (FALSE);
}

int	validate_args_map(t_game *game)
{
	if (!ft_map_is_rectangle(game) && !ft_validate_tileset(game)
		&& !ft_validate_types(game))
	{
		ft_printf("Error\n - The map must be rectangular have one player(P)" \
		"one exit(E) and at least one collectable(C)\n");
		return (TRUE);
	}
	else
		return (FALSE);
}
