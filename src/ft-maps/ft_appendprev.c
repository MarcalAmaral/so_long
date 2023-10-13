/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:39:20 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/12 21:11:28 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_appendprev(t_map **head)
{
	t_map		*temp;
	t_map		*node;
	int			i;
	int			j;

	temp = *head;
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
		node = *head;
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
