/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:43:03 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/01 00:00:29 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_texture_t *ft_load_textures(const char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_printf("Deu merda");
	return (texture);
}