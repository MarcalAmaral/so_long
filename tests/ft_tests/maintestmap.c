/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:24:56 by marvin            #+#    #+#             */
/*   Updated: 2023/10/24 18:24:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_printline_andprevline(t_map *node)
{
	t_map *node_prev;
    static int x;
 
    ft_printf("Print line %d -> next   ", x);
	while (node)
	{
		ft_printf("%c", node->content);
		node = node->next;
		if (node == NULL)
			break ;
		node_prev = node;
	}
	ft_printf("\n");
    ft_printf("Print line %d <- prev   ", x);
	while (node_prev)
	{
		ft_printf("%c", node_prev->content);
		node_prev = node_prev->prev;
	}
	ft_printf("\n");
    x++;
	return ;
}

void    ft_print_up_down(t_map *node)
{
    t_map *node_next;
    static int y;

    ft_printf("Print column %d -> down   ", y);
    while (node)
    {
        ft_printf("%c", node->content);
        node = node->down;
        if (node == NULL)
            break ;
        node_next = node;
    }
    ft_printf("\n");
    ft_printf("Print column %d -> up   ", y);
    while (node_next)
    {
        ft_printf("%c", node_next->content);
        node_next = node_next->up;
    }
    ft_printf("\n");
    y++;
    return ;
}

void    ft_print_column(t_map **map, int *arr)
{
    t_map	*p_y;

    p_y = *map;
    if (arr[1] == 0)
        return ;
    if (arr[1]--)
    {
        ft_print_up_down(p_y);
    }
    ft_print_column(&p_y->next, arr);
    return ;
}


void    ft_print_line(t_map **map, int *arr)
{
    t_map	*p_x;

    p_x = *map;
    if (arr[0] == 0)
        return ;
    if (arr[0]--)
    {
        ft_printline_andprevline(p_x);
    }
    ft_print_line(&p_x->down, arr);
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
	ft_append_down_up_map(head, arr);
    free(arr);
    arr = ft_mapsize(head);
    ft_print_line(head, arr);
    ft_print_column(head, arr);
	ft_free_map(head);
	free(head);
    return (0);
}
