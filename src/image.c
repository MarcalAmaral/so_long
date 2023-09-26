/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:52:45 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/25 21:25:43 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/so_long.h>
#include <../lib/MLX42/include/MLX42/MLX42.h>


mlx_image_t*	texture_to_img(mlx_t* mlx, mlx_texture_t *texture)
{
	//mlx_image_t *img;

	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	// img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	return (img);
}