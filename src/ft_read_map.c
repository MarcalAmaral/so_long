/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:03:24 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/01 00:18:58 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **ft_read_map(const char *path_map)
{
	char 	*line;
	char	*all_line;
	char	**map;
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (!fd)
		ft_printf("Deu merda");
	all_line = (char *) ft_calloc(1, sizeof(char));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break;
		}
		all_line = ft_strjoin(all_line, line);
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	close(fd);
	return (map);
}
