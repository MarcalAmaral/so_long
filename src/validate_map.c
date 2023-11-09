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

int	lenght_line(t_map **head);

int ft_map_is_rectangle(t_game *game)
{
	if ((game->arr_map[0] != game->arr_map[1]) && lenght_line(game->map))
		return (FALSE);
	else
	{
		ft_error("ERROR\n Map is not retangular, please input a retangular map.\n");
		return (TRUE);
	}
}

int	lenght_line(t_map **head)
{
	t_map 	*node;
	int		lenght;
	int		lenght_prev_line;

	node = *head;
	lenght = 0;
	lenght_prev_line = 0;
	while (node)
	{
		if (node->next == NULL)
		{
			if (lenght_prev_line == 0)
				lenght_prev_line = lenght;
			if (lenght_prev_line != lenght)
				break ;
			node = ft_lstfirst_map(node);
			if (node->down != NULL)
				node = node->down;
			else	
				return (TRUE);
			lenght = 0;
		}
		lenght++;
		node = node->next;
	}
	return (FALSE);
}

int     ft_count_types(t_game *game, char type)
{
	int		x;
	int		y;
	int     i;

	x = 0;
	y = 0;
	i = 0;
	game->temp = *(game->map);
	while (x < game->arr_map[0])
	{
		while (y < game->arr_map[1])
		{
			if (game->temp->content == type)
				i++;
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
	return (i);
}

int     ft_validate_tileset(t_game *game)
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
			if (game->temp->content != 'C' && game->temp->content != 'P' && game->temp->content != '0' && game->temp->content != 'E' && game->temp->content != '1')
			{
				ft_printf("Error\n Invalid map, an invalid character (%c) was found inserted in the map at position (%d, %d)\n", game->temp->content, x+1, y+1);
				return (TRUE);
			}
			if (game->temp->next == NULL)
				break;
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

int    ft_validate_types(t_game *game)
{
	int types;

	types =	ft_count_types(game, 'C');
	if (types < 1)
	{
		ft_error("Error\n Invalid map, please make sure the map passed has at least one collectible.");
		return (TRUE);
	}
	types =	ft_count_types(game, 'P');
	if (types < 1 || types > 1)
	{
		ft_error("Error\n Invalid map, please make sure the map passed has at least one player.");
		return (TRUE);
	}
	types =	ft_count_types(game, 'E');
	if (types < 1 || types > 1)
	{
		ft_error("Error\n Invalid map, please make sure the passed map has at least one exit and only one.");
		return (TRUE);
	}
	return (FALSE);
}

int	validate_map(t_game *game)
{
	
	if (!ft_map_is_rectangle(game) && !ft_validate_tileset(game) && !ft_validate_types(game))
		return (TRUE);
	else
		return (FALSE);
}
