/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:23:33 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 10:23:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		*ft_mapsize(t_map **map);
void	ft_append_down_up(t_map **head, int *map);
void	ft_appendprev(t_map **head);
void	ft_print_map(t_map **map);
void	ft_appendnext(t_map **head, t_map *node);
t_map	**ft_newline(t_map **head, t_map *node);
t_map	*ft_newnode_map(char content);
t_map	*ft_lstlastmap(t_map *map);

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

int		*ft_mapsize(t_map **map)
{
	t_map	*temp;
	int		*arr;

	arr = (int *) ft_calloc(1, sizeof(int *));
	arr[1] = 0;
	temp = *map;
	while (arr[1]++, temp->next)
		temp = temp->next;
	temp = *map;
	arr[0] = 0;
	while (arr[0]++, temp->down)
		temp = temp->down;
	arr[2] = arr[0] * arr[1];
	return (arr);
}

//void	ft_append_down_up(t_map **head, int *map)
//{
//	t_map	*temp;
//	t_map	*node;
//	t_map	*x;
//	int		ops;
//
//	temp = *head;
//	node = temp->down;
//	ops = (map[0] - 1) * (map[1] - 1);
//	while (node)
//	{
//		node->up = temp;
//		node = node->down;
//		temp = temp->down; 
//	}
//	node = temp->up;
//	while (ops--)
//	{
//		x = node->up;
//		if (node->next || temp->next == NULL)
//			node
//	}
//	return ;
//}

void    ft_append_down_up(t_map **head, int *arr)
{
    t_map   *temp;
    t_map   *node;
    int y;

    y = 0;
    if (arr[0]--)
    {
        temp = *head;
        node = temp->down;
        *head = node;
    }
    while (y++ < arr[1])
    {
        node->up = temp;
        temp->down = node;
        node = node->next;
        temp = temp->next;
    }
    ft_append_down_up(head, arr);
}

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
				if (line[j] == '\n')
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

int main(void)
{
    t_map	**head;
    int		fd;
	int		*arr;

    head = (t_map **) ft_calloc(1, sizeof(t_map **));
    fd = open("maps/map.ber", O_RDONLY);
	ft_readmap(head, fd);
	arr = ft_mapsize(head);
	ft_append_down_up(head, arr);
	ft_print_map(head);
    return (0);
}

void	ft_print_map(t_map **map)
{
	t_map	*p_next;
	t_map	*p_prev;
	t_map	*p_down;
	t_map	*p_up;
	t_map	*p_down1;
	t_map	*p_down1_prev;
	t_map	*p_down2;
	t_map	*p_down2_prev;

	p_next = *map;
	p_down1 = p_next->down;
	p_down2 = p_down1->down;
	while (p_next)
	{
		ft_printf("%c", p_next->content);
		p_next = p_next->next;
		if (p_next == NULL)
			break ;
		p_prev = p_next;
	}
	ft_printf("\n");
	while (p_prev)
	{
		ft_printf("%c", p_prev->content);
		p_prev = p_prev->prev;
	}
	ft_printf("\n");
	while (p_down1)
	{
		ft_printf("%c", p_down1->content);
		p_down1 = p_down1->next;
		if (p_down1 == NULL)
			break ;
		p_down1_prev = p_down1;
	}
	ft_printf("\n");
	while (p_down1_prev)
	{
		ft_printf("%c", p_down1_prev->content);
		p_down1_prev = p_down1_prev->prev;
	}
	ft_printf("\n");
	while (p_down2)
	{
		ft_printf("%c", p_down2->content);
		p_down2 = p_down2->next;
		if (p_down2 == NULL)
			break ;
		p_down2_prev = p_down2;
	}
	ft_printf("\n");
	while (p_down2_prev)
	{
		ft_printf("%c", p_down2_prev->content);
		p_down2_prev = p_down2_prev->prev;
	}
	ft_printf("\n");
	p_down = *map;
	while (p_down->down)
	{
		ft_printf("%c\n", p_down->content);
		p_down = p_down->down;
		if (p_down == NULL)
			break ;
		p_up = p_down;
	}
	ft_printf("\n");
	while (p_up)
	{
		ft_printf("%c\n", p_up->content);
		p_up = p_up->up;
	}
	return ;
}