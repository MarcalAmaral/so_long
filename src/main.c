/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:21:12 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 19:21:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
int	    ft_create_texture_from_png(t_window *window);
int	    game_init(void);
int	    map_construct(t_window *window);
void	ft_create_img_from_texture(t_window *window);
void    get_size_window(t_window *window);
void	hook_close_window(void *param);
void	ft_error(char *error);
void	map_to_window(t_window *window, t_map **map);
void    ft_drawlayers(t_window *window, t_map **map, char type);
void	draw_map(t_window *window, t_map **map);

void    ft_drawlayers(t_window *window, t_map **map, char type)
{
	t_map   *temp;

	temp = *map;
	while (temp->next != NULL)
	{
		if (type == '0')
				mlx_image_to_window(window->mlx, window->background_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
			else if (temp->content == type)
			{
				if (type == 'P')
					mlx_image_to_window(window->mlx, window->player_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == 'C')
					mlx_image_to_window(window->mlx, window->collectable_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == '1')
					mlx_image_to_window(window->mlx, window->wall_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
				else if (type == 'E')
					mlx_image_to_window(window->mlx, window->exit_img, window->arr_map[0]-- * SIZE_IMAGE, window->arr_map[1] * SIZE_IMAGE);
			}
	}
	ft_drawlayers(window, &temp->down, type);
	return ;
}

void	draw_map(t_window *window, t_map **map)
{
	ft_drawlayers(window, map, '0');
	ft_drawlayers(window, map, '1');
	ft_drawlayers(window, map, 'C');
	ft_drawlayers(window, map, 'P');
}

int	map_construct(t_window *window)
{
	if (ft_create_texture_from_png(window))
	{
		ft_create_img_from_texture(window);
		return (1);
	}
	else
		return (0);
}

static int	map_to_window(t_window *window, t_map **map)
{
	if (1)
	{
		get_size_window(window);
		window->mlx = mlx_init(window->window_w, window->window_h, "So_long", true);
		if (!window->mlx)
			ft_error("Error\n - Fail to init the window\n");
		if (map_construct(window))
			draw_map(window, map);
		else
			ft_error("Error\n - Fail to construct the map\n");
		return (1);
	}
	else
		return (0);
}

int	game_init(void)
{
	t_map		**map;
	t_window	*window;
	int         fd;

	fd = open("../maps/map.ber", O_RDONLY);
	map = (t_map **) ft_calloc(1, sizeof(t_map **));
	window = (t_window *) ft_calloc(1, sizeof(t_window *));
	ft_readmap(map, fd);
	window->arr_map = ft_mapsize(map);
	map_to_window(window, map);
	mlx_loop_hook(window->mlx, &hook_close_window, window);
	mlx_loop(window->mlx);
	return (1);
}

void	ft_error(char *error)
{
	ft_printf("\n%s\n", error);
	exit(EXIT_FAIL);
}

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

void	hook_close_window(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(window->mlx);
	}
}

void    get_size_window(t_window *window)
{
	window->window_w = window->arr_map[0] * SIZE_IMAGE;
	window->window_w = window->arr_map[1] * SIZE_IMAGE;
}
 */
int	main(void)
{
	game_init();
	return (0);
}
