/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_to_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:52:45 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/01 00:00:39 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t*	ft_texture_to_img(mlx_t* mlx, mlx_texture_t *texture)
{
	mlx_image_t *img;

	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_printf("Deu merda");
	return (img);
}