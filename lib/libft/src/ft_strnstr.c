/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:21:50 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/30 22:26:50 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t	len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len < 1)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len-- >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
