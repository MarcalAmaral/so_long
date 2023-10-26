/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:27:06 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 19:27:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_drawlayers(t_window *window, t_map **map, char type)
{
    t_map   *temp;

    temp = *map;
	while (temp->next != NULL)
	{
        if (type == '0')
				mlx_image_to_window(window->mlx, window->background_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
			else if (temp->content == type)
			{
				if (type == 'P')
					mlx_image_to_window(window->mlx, window->player_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == 'C')
					mlx_image_to_window(window->mlx, window->collectable_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == '1')
					mlx_image_to_window(window->mlx, window->wall_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == 'E')
					mlx_image_to_window(window->mlx, window->exit_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
            }
    }
    ft_drawlayers(window, &temp->down, type);
    return ;
}

void	draw_map(t_window *window, t_map **map)
{
	ft_drawlayers(window, map, '0');
	ft_drawlayers(window, map, '1');
	ft_drawlayers(window, map, 'C');
	ft_drawlayers(window, map, 'P');
}

int	map_construct(t_window *window)
{
	if (create_texture_from_png(window))
	{
		create_img_from_texture(window);
		return (1);
	}
	else
		return (0);
}
