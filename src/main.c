/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:33:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/25 20:33:13 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 1000


t_map	ft_newnode_map(char content)
{
	t_map node;

	node.byte = content;
	node.dup_byte = content;
	return (node);
}

void	ft_append_next_map(t_map *node, char content)
{
	t_map	new_node;

	new_node = ft_newnode_map(content);
	new_node.prev = node;
	node->next = &new_node;
}

int	main(void)
{
	t_map	map;
	t_map	head;
	char	str[] = "lastline";;
	size_t	i = 0;

	head = ft_newnode_map('c');
	map = head;
	while (str[i])
		ft_append_next_map(&map, str[i]);
	while (head.next != NULL)
		printf("%c", head.byte);
	return (0);
}
