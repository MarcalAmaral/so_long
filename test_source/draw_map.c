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

//void    ft_drawlayers(t_window *window, t_map **map, char type)
//{
//    t_map   *temp;
//	int		x;
//	int		y;
//
//    temp = *map;
//	x = window->arr_map[0];
//	y = window->arr_map[1];
//	while (x--)
//	{
//		while (temp)
//		{
//			if (temp->content == '1')
//				mlx_image_to_window(window->mlx, window->background_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
//			else if (temp)
//			{
//				if (temp->content == 'P')
//					mlx_image_to_window(window->mlx, window->player_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
//				else if (temp->content == 'C')
//					mlx_image_to_window(window->mlx, window->collectable_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
//				else if (temp->content == '1')
//					mlx_image_to_window(window->mlx, window->wall_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
//				else if (temp->content == 'E')
//					mlx_image_to_window(window->mlx, window->exit_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
//            }
//			y--;
//			temp = temp->next;
//		}
//		
//    }
//    return ;
//}

void	ft_drawlayers(t_window *window, t_map **map, char type)
{
	t_map	*node;
	int		x;
	int		y;

	node = *map;
	x = window->arr_map[0];
	y = window->arr_map[1];
	while (x)
	{
		while (y > 0)
		{
			if (type == '0')
				mlx_image_to_window(window->mlx, window->background_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
			else
			{
				if (node->content == 'P' && type == 'P')
					mlx_image_to_window(window->mlx, window->player_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
				else if (node->content == 'C' && type == 'C')
					mlx_image_to_window(window->mlx, window->collectable_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
				else if (node->content == '1' && type == '1')
					mlx_image_to_window(window->mlx, window->wall_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
				else if (node->content == 'E' && type == 'E')
					mlx_image_to_window(window->mlx, window->exit_img, x * SIZE_IMAGE, y * SIZE_IMAGE);
			}
			if (node->next == NULL)
				break ;
			node = node->next;
			y--;
		}
		node = ft_lstfirst_map(node);
		node = node->down;
		y = window->arr_map[1];
		x--;
	}
	return ;
}

void	draw_map(t_window *window, t_map **map)
{
	ft_drawlayers(window, map, '0');
	ft_drawlayers(window, map, '1');
	ft_drawlayers(window, map, 'C');
	ft_drawlayers(window, map, 'P');
	ft_drawlayers(window, map, 'E');
}

int	map_construct(t_window *window)
{
	if (ft_create_texture_from_png(window))
	{
		ft_create_img_from_texture(window);
		return (1);
	}
	else
		return (0);
}
