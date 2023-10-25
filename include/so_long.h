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
# define EXIT_FAIL	1

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
t_map			*ft_newnode_map(char content);
t_map			**ft_newline_map(t_map **head, t_map *node);
t_map			*ft_lstfirst_map(t_map *map);
t_map			*ft_lstlast_map(t_map *map);
void			ft_readmap(t_map **map, int	fd);
void			ft_append_down_up_map(t_map **head, int *map_arr);
void			ft_append_prev_map(t_map **head);
void			ft_append_next_map(t_map **head, t_map *node);
void			ft_free_map(t_map **head);
int				*ft_mapsize(t_map **map);


#endif