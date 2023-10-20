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
void	ft_freemap(t_map **head);
void	ft_append_down_up(t_map **head, int *map);
void	ft_appendprev(t_map **head);
void	ft_print_map(t_map **map);
void	ft_appendnext(t_map **head, t_map *node);
t_map	**ft_newline(t_map **head, t_map *node);
t_map	*ft_newnode_map(char content);
t_map	*ft_lstlastmap(t_map *map);
t_map	*ft_lstfirstmap(t_map *map);

t_map	*ft_lstfirstmap(t_map *map)
{
	while (map)
	{
		if (!map->prev)
			return(map);
		map = map->prev;
	}
	return (map);
}

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

	arr = (int *) ft_calloc(3, sizeof(int));
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

void	ft_append_down_up(t_map **head, int *arr)
{
    t_map   *up;
    t_map   *down;
    int y;

    y = 0;
	if (*head == NULL)
		return ;
	if (arr[0]--)
	{
		up = *head;
		down = up->down;
	}
	while (y++ < arr[1] && down)
	{
		down->up = up;
		up->down = down;
		if (down->next)
			down = down->next;
		up = up->next;
	}
	down = ft_lstfirstmap(down);
    ft_append_down_up(&down, arr);
	return ;
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
	int		j;
	char 	*line;

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
			if (line[j] == '\n' || line[j] == '\0')
				break ;
			ft_appendnext(map, ft_newnode_map(line[j]));
			j++;
		}
		ft_appendprev(map);
		free(line);
		ft_readmap(map, fd);
	}
	return ;
}

int main(void)
{
	int		*arr;
    t_map	**head;
    int		fd;

    head = (t_map **) ft_calloc(1, sizeof(t_map **));
    fd = open("maps/map.ber", O_RDONLY);
	ft_readmap(head, fd);
	arr = ft_mapsize(head);
	ft_append_down_up(head, arr);
	free(arr);
//	ft_print_map(head);
	ft_freemap(head);
	free(head);
    return (0);
}

void	ft_printline_andprevline(t_map *node)
{
	t_map *node_prev;
 
	while (node)
	{
		ft_printf("%c", node->content);
		node = node->next;
		if (node == NULL)
			break ;
		node_prev = node;
	}
	ft_printf("\n");
	while (node_prev)
	{
		ft_printf("%c", node_prev->content);
		node_prev = node_prev->prev;
	}
	ft_printf("\n");
	return ;
}

void	ft_freemap(t_map **head)
{
	t_map	*temp;
	t_map	*temp1;

	if (!*head)
		return ;
	temp = *head;
	*head = temp->down;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	ft_freemap(head);
	return ;
}

void	ft_print_map(t_map **map)
{
	t_map	*p_x1;
//	t_map	*p_x2;
//	t_map	*p_x3;
//	t_map	*p_x4;
//	//t_map	*p_x5;
//
	p_x1 = *map;
//	p_x2 = p_x1->down;
//	p_x3 = p_x2->down;
//	p_x4 = p_x3->down;
//	//p_x5 = p_x4->down;
	ft_printline_andprevline(p_x1);
//	ft_printline_andprevline(p_x2);
//	ft_printline_andprevline(p_x3);
//	ft_printline_andprevline(p_x4);
	//ft_printline_andprevline(p_x5);
	//while (p_down1)
	//{
	//	ft_printf("%c", p_down1->content);
	//	p_down1 = p_down1->next;
	//	if (p_down1 == NULL)
	//		break ;
	//	p_down1_prev = p_down1;
	//}
	//ft_printf("\n");
	//while (p_down1_prev)
	//{
	//	ft_printf("%c", p_down1_prev->content);
	//	p_down1_prev = p_down1_prev->prev;
	//}
	//ft_printf("\n");
	//while (p_down2)
	//{
	//	ft_printf("%c", p_down2->content);
	//	p_down2 = p_down2->next;
	//	if (p_down2 == NULL)
	//		break ;
	//	p_down2_prev = p_down2;
	//}
	//ft_printf("\n");
	//while (p_down2_prev)
	//{
	//	ft_printf("%c", p_down2_prev->content);
	//	p_down2_prev = p_down2_prev->prev;
	//}
	//ft_printf("\n");
	//p_down = *map;
	//while (p_down->down)
	//{
	//	ft_printf("%c\n", p_down->content);
	//	p_down = p_down->down;
	//	if (p_down == NULL)
	//		break ;
	//	p_up = p_down;
	//}
	//ft_printf("\n");
	//while (p_up)
	//{
	//	ft_printf("%c\n", p_up->content);
	//	p_up = p_up->up;
	//}
	//return ;
}