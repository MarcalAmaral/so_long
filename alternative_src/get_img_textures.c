/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:13:32 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/02 14:01:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_create_new_player_image(t_window *window)
{
	mlx_delete_texture(window->p_texture);
	mlx_delete_image(window->mlx, window->p_img);
	window->p_texture = mlx_load_png("textures/P/p_idle.png");
	window->p_img = mlx_texture_to_image(window->mlx,
			window->p_texture);
	mlx_resize_image(window->p_img, SIZE_IMG, SIZE_IMG);
	return (1);
}

int	ft_create_textures_from_png(t_window *window)
{
	window->w_texture = mlx_load_png("textures/1/wall.png");
	window->bd_texture = mlx_load_png("textures/0/ground.png");
	window->p_texture = mlx_load_png("textures/P/p_idle.png");
	window->c_texture = mlx_load_png("textures/C/coin.png");
	window->e_texture = mlx_load_png("textures/E/door.png");
	if (!window->bd_texture || !window->w_texture
		|| !window->p_texture || !window->c_texture
		|| !window->e_texture)
		return (0);
	return (1);
}

void	ft_create_img_from_texture(t_window *window)
{
	window->p_img = mlx_texture_to_image(window->mlx, window->p_texture);
	window->c_img = mlx_texture_to_image(window->mlx, window->c_texture);
	window->e_img = mlx_texture_to_image(window->mlx, window->e_texture);
	window->bd_img = mlx_texture_to_image(window->mlx, window->bd_texture);
	window->w_img = mlx_texture_to_image(window->mlx, window->w_texture);
	mlx_resize_image(window->p_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(window->c_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(window->e_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(window->bd_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(window->w_img, SIZE_IMG, SIZE_IMG);
}
