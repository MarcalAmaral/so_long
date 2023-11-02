/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:19 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/01 21:01:13 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_draw_ground(t_window *window)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < window->arr_map[0])
	{
		while (y < window->arr_map[1])
		{
			mlx_image_to_window(window->mlx, window->bd_img, \
			x * SIZE_IMG, y * SIZE_IMG);
			y++;
		}
		y = 0;
		x++;
	}
}

//void	draw_layers(t_window *window, char type)
//{	
//	t_map	*node;
//	int		x;
//	int		y;
//
//	x = -1;
//	y = 0;
//	node = *(window->map);
//	while (x++ < window->arr_map[0])
//	{
//		while (y++ < window->arr_map[1])
//		{
//			if (node->content == 'P')
//				mlx_image_to_window(window->mlx, window->p_img, \
//				x * SIZE_IMG, y * SIZE_IMG);
//			else if (node->content == 'C')
//				mlx_image_to_window(window->mlx, window->p_img, \
//				x * SIZE_IMG, y * SIZE_IMG);
//			else if (node->content == '1')
//				mlx_image_to_window(window->mlx, window->p_img, \
//				x * SIZE_IMG, y * SIZE_IMG);
//			else if (node->content == 'E')
//				mlx_image_to_window(window->mlx, window->p_img, \
//				x * SIZE_IMG, y * SIZE_IMG);
//			node = node->next;
//		}
//	}
//}

void	ft_draw_wall(t_window *window, mlx_image_t *img, char type)
{
	t_map	*node;
	int		x;
	int		y;

	x = 0;
	y = 0;
	node = *(window->map);
	while (x < window->arr_map[0])
	{
		while (y < window->arr_map[1])
		{
			if (node->content == type)
				mlx_image_to_window(window->mlx, img, \
			x * SIZE_IMG, y * SIZE_IMG);
			if (node->next == NULL)
			{
				node = ft_lstfirst_map(node);
				node = node->down;
				break ;
			}
			node = node->next;
			y++;
		}
		y = 0;
		x++;
	}
}

void	draw_map(t_window *window)
{
	ft_draw_ground(window);
	ft_draw_wall(window);
}

int	map_construct(t_window *window)
{
	if (ft_create_textures_from_png(window))
	{
		ft_create_img_from_texture(window);
		return (1);
	}
	else
		return (0);
}
