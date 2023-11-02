/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:24:54 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/01 20:46:52 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

	fd = open("/nfs/homes/myokogaw/Documents/so_long/maps/map.ber", O_RDONLY);
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
	ft_map_to_window(&window);
	mlx_loop(window.mlx);
	return (1);
}
