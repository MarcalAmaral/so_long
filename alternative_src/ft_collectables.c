/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:42 by marvin            #+#    #+#             */
/*   Updated: 2023/11/02 17:37:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	collect(t_window *window, t_map *c_node)
{
	int	i;

	i = 0;
 	while (i < window->collectables)
 	{
 		if (c_node->content == 'C')
 		{
 			window->c_img->instances[i].enabled = 0;
			c_node->content = '0';
 			window->collectables -= 1;
 		}
 		i++;
 	}
 	if (window->collectables <= 0)
 		ft_draw(window, window->e_img,'E');
   return ;
}
