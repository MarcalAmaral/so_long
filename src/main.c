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

void	ft_print_map(t_map **map);
void	ft_free(t_map **map);

t_map	**ft_newline(t_map **head, t_map *node)
{
	t_map	*temp;

	if (!node)
		return (head);
	if (!*head)
	{
		*head = node;
		return (head);
	}
	temp = *head;
	while (temp->down)
		temp = temp->down;
	temp->down = node;
	return (&temp->down);
}

void	ft_readmap(t_map **map, int	fd)
{
	int		i;
	int		j;
	char 	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	if (line)
	{
		while (line[j])
		{
			if (j == 0)
			{
				map = ft_newline(map, ft_newnode_map(line[j]));
				j++;
			}
			if (line[j] == '\n' || line[j + 1] == '\0')
			{
				ft_appendprev(map);
				break ;
			}
			ft_appendnext(map, ft_newnode_map(line[j]));
			j++;
		}
		free(line);
		i++;
		ft_readmap(map, fd);
	}
	return ;
}

int	main(void)
{
	int		fd;
	t_map	**map;

	fd = open("/nfs/homes/myokogaw/Documents/so_long/maps/map.ber", O_RDONLY);
	map = (t_map **) ft_calloc(1, sizeof(t_map **));
	ft_readmap(map, fd);
	ft_print_map(map);
	ft_free(map);
	free(map);
	return (0);
}

void	ft_free(t_map **map)
{
	t_map	*temp;
	t_map	*temp1;

	temp = *map;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	return ;
}

void	ft_print_map(t_map **map)
{
	t_map	*temp;
	t_map	*node_down;
	t_map	*x2;

	temp = *map;
	node_down = temp->down;
	x2 = node_down->down;
	while (temp)
	{
		ft_printf("%c", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
	while (node_down)
	{
		ft_printf("%c", node_down->content);
		node_down = node_down->next;
	}
	ft_printf("\n");
	while (x2)
	{
		ft_printf("%c", x2->content);
		x2 = x2->next;
	}
}
