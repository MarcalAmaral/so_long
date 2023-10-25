/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:09:55 by marvin            #+#    #+#             */
/*   Updated: 2023/10/24 18:09:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_printline_andprevline(t_map *node);
void	ft_print_map(t_map **map);

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