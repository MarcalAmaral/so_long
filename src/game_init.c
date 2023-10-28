/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:29:32 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 20:29:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_to_window(t_window *window, t_map **map)
{
	if (1)
	{
		get_size_window(window);
		window->mlx = mlx_init(1280, 720, "So_long", true);
		if (!window->mlx)
			ft_error("Error\n - Fail to init the window\n");
		if (map_construct(window))
			draw_map(window, map);
		else
			ft_error("Error\n - Fail to construct the map\n");
		return (1);
	}
	else
		return (0);
}

int	game_init(void)
{
	t_map		**map;
	t_window	window;
	int			fd;

	fd = open("maps/map.ber", O_RDONLY);
	map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_bzero(&window, sizeof(t_window));
	ft_readmap(map, fd);
	window.arr_map = ft_mapsize(map);
	ft_append_down_up_map(map, window.arr_map);
	map_to_window(&window, map);
	mlx_loop_hook(window.mlx, &hook_close_window, &window);
	mlx_loop(window.mlx);
	return (1);
}
