/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:03:07 by marvin            #+#    #+#             */
/*   Updated: 2023/10/24 18:03:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_append_down_up_map(t_map **head, int *map_arr);
void	ft_append_prev_map(t_map **head);
void	ft_append_next_map(t_map **head, t_map *node);
void	ft_free_map(t_map **head);
int		*ft_mapsize(t_map **map);

void	ft_append_down_up_map(t_map **head, int *map_arr)
{
    t_map   *up;
    t_map   *down;
    int y;

    y = 0;
	if (*head == NULL)
		return ;
	if (map_arr[0]--)
	{
		up = *head;
		down = up->down;
	}
	while (y++ < map_arr[1] && down)
	{
		down->up = up;
		up->down = down;
		if (down->next)
			down = down->next;
		up = up->next;
	}
	down = ft_lstfirst_map(down);
    ft_append_down_up_map(&down, map_arr);
	return ;
}

void	ft_append_prev_map(t_map **map)
{
	t_map		*temp;
	t_map		*node;
	int			i;
	int			j;

	temp = *map;
	i = 0;
	if (i == 0)
	{
		temp->prev = NULL;
		i++;
	}
	temp = temp->next;
	j = -1;
	while (temp)
	{
		node = *map;
		while (j++, j <= i - 1)
			if	(i != 1)
				node = node->next;
		j = 0;
		temp->prev = node;
		i++;
		temp = temp->next;
	}
	return ;
}

void	ft_append_next_map(t_map **head, t_map *node)
{
	t_map	*temp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlast_map(*head);
	temp->next = node;
	return ;
}

void	ft_free_map(t_map **head)
{
	t_map	*temp;
	t_map	*temp1;

	if (!*head)
		return ;
	temp = *head;
	*head = temp->down;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	ft_free_map(head);
	return ;
}

int		*ft_mapsize(t_map **map)
{
	t_map	*temp;
	int		*arr;

	arr = (int *) ft_calloc(3, sizeof(int));
	arr[1] = 0;
	temp = *map;
	while (arr[1]++, temp->next)
		temp = temp->next;
	temp = *map;
	arr[0] = 0;
	while (arr[0]++, temp->down)
		temp = temp->down;
	arr[2] = arr[0] * arr[1];
	return (arr);
}
