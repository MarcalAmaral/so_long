/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:38:11 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/12 20:41:08 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map	*ft_lstlastmap(t_map *map)
{
	while (map)
	{
		if (!map->next)
			return(map);
		map = map->next;
	}
	return (map);
}
