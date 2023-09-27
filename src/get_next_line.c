/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:01:20 by myokogaw          #+#    #+#             */
/*   Updated: 2023/07/05 20:40:44 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_vars	vars;

	if (vars.iter >= vars.bytes_read)
	{
		vars.iter = 0;
		while (vars.iter <= BUFFER_SIZE)
		{
			vars.buffer[vars.iter] = '\0';
			vars.iter++;
		}
		vars.iter = 0;
		vars.len = 0;
		vars.fd = fd;
		vars.bytes_read = read(vars.fd, vars.buffer, BUFFER_SIZE);
	}
	if (vars.bytes_read <= 0)
		return (NULL);
	return (ft_cpybuffer(&vars));
}
