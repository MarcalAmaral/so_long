/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkingupdown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:13:07 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 19:13:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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