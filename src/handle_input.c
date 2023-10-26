/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:43:58 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 20:43:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook_close_window(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(window->mlx);
	}
}