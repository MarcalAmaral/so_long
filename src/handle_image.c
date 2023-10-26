/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:43:03 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/25 21:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_create_texture_from_png(t_window *window)
{
	window->background_texture = mlx_load_png("../textures/map_textures/128x128/Grass_01-128x128.png");
	window->wall_texture = mlx_load_png("../textures/map_textures/128x128/Bricks/Bricks_02-128x128.png");
	window->player_texture = mlx_load_png("../textures/player_idle/tile002.png");
	window->exit_texture = mlx_load_png("../textures/map_textures/128x128/Tile/Tile_24-128x128.png");
	window->collectable_texture = mlx_load_png("../textures/map_textures/128x128/Roofs/Roofs_02-128x128.png");
	if (!window->background_texture || !window->wall_texture
		|| !window->player_texture || !window->collectable_texture
		|| !window->exit_texture)
		return (0);
	return (1);
}

void	ft_create_img_from_texture(t_window *window)
{
	int	width;
	int	height;

	width = SIZE_IMAGE;
	height = SIZE_IMAGE;
	window->player_img = mlx_texture_to_image(window->mlx,
			window->player_texture);
	window->exit_img = mlx_texture_to_image(window->mlx, window->exit_texture);
	window->background_img = mlx_texture_to_image(window->mlx,
			window->background_texture);
	window->wall_img = mlx_texture_to_image(window->mlx, window->wall_texture);
	window->collectable_img = mlx_texture_to_image(window->mlx,
			window->collectable_texture);
	mlx_resize_image(window->player_img, width, height);
	mlx_resize_image(window->wall_img, width, height);
	mlx_resize_image(window->background_img, width, height);
	mlx_resize_image(window->collectable_img, width, height);
	mlx_resize_image(window->exit_img, width, height);
}
