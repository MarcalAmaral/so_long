/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:24:54 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/02 22:59:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_count_elem(t_window *window, char type)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	window->temp = *(window->map);
	while (x < window->arr_map[0])
	{
		while (y < window->arr_map[1])
		{
			if (window->temp->content == type)
				window->collectables++;
			if (window->temp->next == NULL)
			{
				window->temp = ft_lstfirst_map(window->temp);
				break ;
			}
			window->temp = window->temp->next;
			y++;
		}
		window->temp = window->temp->down;
		x++;
		y = 0;
	}
}

void	ft_map_to_window(t_window *window)
{
	window->mlx = mlx_init(1280, 720, "So_long", 1);
	if (map_construct(window))
		draw_map(window);
	else
		ft_printf("Fail to construct map");
	return ;
}

void	ft_map(t_window *window)
{
	int		fd;

	fd = open("maps/map.ber", O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Verificar se o path para o arquivo está correto");
		return ;
	}
	window->map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_readmap(window->map, fd);
	window->arr_map = ft_mapsize(window->map);
	ft_append_down_up_map(window->map, window->arr_map);
	return ;
}

int	game_init(void)
{
	t_window	window;

	ft_bzero(&window, sizeof(t_window));
	ft_map(&window);
	ft_count_elem(&window, 'C');
	ft_map_to_window(&window);
	mlx_loop_hook(window.mlx, &ft_hook_close_window, &window);
	mlx_key_hook(window.mlx, &ft_hook_player_movement, &window);
	mlx_loop(window.mlx);
	return (1);
}
