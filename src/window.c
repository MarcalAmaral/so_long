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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "../include/so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

#define WIDTH 1000
#define HEIGHT 1000

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_hook(void* param)
{
	t_data *game;
	game  = (t_data *) param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->img->instances[0].x += 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->img->instances[0].x -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->img->instances[0].y -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->img->instances[0].y += 1;
}

int32_t	main(void)
{
	// Start mlx
	t_data	game;
	
	game.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game.mlx)
        error();

	game.texture = ft_load_textures("./textures/player_idle/tile000.png");
	game.img = ft_texture_to_img(game.mlx, game.texture);
	mlx_image_resize(game.img, 128, 128);
	mlx_image_to_window(game.mlx, game.img, 5, 5);

	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_texture(game.texture);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

/* int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Create a new image
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	if (!img)
		error();

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */