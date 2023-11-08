/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:04:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/08 15:48:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	lenght_line(t_map **head)
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
			{
				ft_printf("ERROR\n -This map is not rectangular, please, input a rectangle map.\n");
				break ;
			}
			node = ft_lstfirst_map(node);
			if (node->down != NULL)
				node = node->down;
			else	
				return ;
			lenght = 0;
		}
		lenght++;
		node = node->next;
	}
	return ;
}

void	ft_map(t_game *game, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		ft_printf("Error\n Check that the path to the file is correct.\n");
	game->map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_readmap(game->map, fd);
	game->arr_map = ft_mapsize(game->map);
	ft_append_down_up_map(game->map, game->arr_map);
	return ;
}

int	main(void)
{
	t_game game;

	ft_bzero(&game, sizeof(game));
	ft_map(&game, "./maps/map_bigger.ber");
	lenght_line(game.map);
	return (0);
}
