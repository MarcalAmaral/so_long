/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:43:03 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/26 19:23:07 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/so_long.h>
#include <../lib/MLX42/include/MLX42/MLX42.h>

mlx_texture_t *ft_load_textures(const char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
		error();
	return (texture);
}