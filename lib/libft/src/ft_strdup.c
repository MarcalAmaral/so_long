/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:20:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/30 22:26:20 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t			i;
	size_t			lenght;
	char			*n_string;

	i = -1;
	lenght = ft_strlen(s);
	n_string = (char *) malloc(lenght * sizeof(char) + 1);
	if (!n_string)
		return (n_string);
	while (i++, i != lenght)
		n_string[i] = s[i];
	n_string[i] = '\0';
	return (n_string);
}
