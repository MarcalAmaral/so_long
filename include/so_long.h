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
# include "../lib/libft/inc/libft.h"
# include <fcntl.h>

typedef struct s_data {
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	const char		**map;
} t_data;

typedef struct s_map {
	char			content;
	char			dup_content;
	struct s_map	*next;
	struct s_map	*prev;
	struct s_map	*up;
	struct s_map	*down;
}	t_map;

mlx_texture_t	*ft_load_textures(const char *path);
mlx_image_t		*ft_texture_to_img(mlx_t* mlx, mlx_texture_t *texture);
const char		**ft_read_map(const char *path_map);
t_map			*ft_lstlastmap(t_map *map);
t_map			*ft_newnode_map(char content);
void			ft_appendnext(t_map **head, t_map *node);
void			ft_appendprev(t_map **head);

#endif