/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:34:42 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/12 20:38:06 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_appendnext(t_map **head, t_map *node)
{
	t_map	*temp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlastmap(*head);
	temp->next = node;
	return ;
}
