/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:38:56 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/03 17:51:03 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1280, 720, "Test", 1);
	if (!mlx)
		ft_printf("deu erro");
	img = mlx_new_image(mlx, 50, 50);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 200, 200);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 1000, 500);
	img->instances[1].enabled = 0;
	ft_printf("x of instance 0: %i, y of instance 0: %i\n", img->instances[0].x, img->instances[0].y);
	ft_printf("x of instance 1: %i, y of instance 1: %i\n", img->instances[1].x, img->instances[1].y);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
