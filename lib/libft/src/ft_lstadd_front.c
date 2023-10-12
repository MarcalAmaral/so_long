/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:50:42 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/10 21:00:57 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;
	
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		temp = *lst;
		new->next = temp;
		*lst = new;
	}
	return ;
}
