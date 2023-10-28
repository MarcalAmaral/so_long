/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:40:43 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 20:40:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_size_window(t_window *window)
{
	window->window_w = window->arr_map[0] * SIZE_IMAGE;
	window->window_h = window->arr_map[1] * SIZE_IMAGE;
}
