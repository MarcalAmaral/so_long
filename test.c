/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:15:29 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/07 19:27:26 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	ft_draw_ground(mlx_t *mlx, mlx_image_t *img)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 5)
	{
		while (x < 10)
		{
			mlx_image_to_window(mlx, img, x * 32, y * 32);
			x++;
		}
		y++;
		x = 0;
	}
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*bd_texture;
	mlx_image_t		*bd_img;

	mlx = mlx_init(1280, 720, "So_long", 1);
	bd_texture = mlx_load_png("textures/0/ground.png");
	bd_img = mlx_texture_to_image(mlx, bd_texture);
	mlx_resize_image(bd_img, 32, 32);
	ft_draw_ground(mlx, bd_img);
	mlx_loop(mlx);
	return (0);
}
