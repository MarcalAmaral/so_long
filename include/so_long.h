/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:46:16 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 20:46:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_data {
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
} t_data;

mlx_texture_t	*ft_load_textures(const char *path);
mlx_image_t		*ft_texture_to_img(mlx_t* mlx, mlx_texture_t *texture);
char			**ft_read_map(const char *path_map);

#endif