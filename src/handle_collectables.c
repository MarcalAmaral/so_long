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

#include "../inc/so_long.h"

void	ft_collect(t_window *window, t_player *player, char *dir)
{
	t_map	*temp;
	int		i;

	i = 0;
	if (dir == "up")
		temp = player->p_position->up;
	else if (dir == "down")
		temp = player->p_position->down;
	else if (dir == "next")
		temp = player->p_position->next;
	else if (dir == "prev")
		temp = player->p_position->prev;
	while (i < window->collectables)
	{
		if (temp->content == 'C')
		{
			if (window->c_img->instances[i].x / SIZE_IMG == player->p_x && \
				window->c_img->instances[i].y / SIZE_IMG == player->p_y)
			{
				window->c_img->instances[i].enabled = 0;
				temp->content = '0';
				window->collectables -= 1;
			}
		}
		i++;
	}
	if (window->collectables <= 0)
		ft_draw(window, window->e_img, 'E');
	return ;
}
