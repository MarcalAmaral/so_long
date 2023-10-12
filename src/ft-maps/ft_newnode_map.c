/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:24:27 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/12 20:38:48 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map	*ft_newnode_map(char content)
{
	t_map	*new_node;

	new_node = (t_map *) ft_calloc (1, sizeof(t_map));
	new_node->content = content;
	new_node->dup_content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->up = NULL;
	new_node->down = NULL;
	return (new_node);
}
