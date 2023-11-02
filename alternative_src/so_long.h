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
# define SIZE_IMG 32

typedef struct s_map {
	char			content;
	char			dup_content;
	struct s_map	*next;
	struct s_map	*prev;
	struct s_map	*up;
	struct s_map	*down;
}	t_map;

typedef struct s_window {
	mlx_t			*mlx;
	mlx_texture_t	*w_texture;
	mlx_texture_t	*bd_texture;
	mlx_texture_t	*p_texture;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*c_texture;
	mlx_image_t		*bd_img;
	mlx_image_t		*w_img;
	mlx_image_t		*p_img;
	mlx_image_t		*e_img;
	mlx_image_t		*c_img;
	t_map			**map;
	int				*arr_map;
}	t_window;

typedef struct s_player {
	int		p_x;
	int		p_y;
	int		n_mov;
	t_map	*p_position;
}	t_player;

/*Handle linked list matrix*/
t_map	*ft_newnode_map(char content);
t_map	**ft_newline_map(t_map **head, t_map *node);
t_map	*ft_lstfirst_map(t_map *map);
t_map	*ft_lstlast_map(t_map *map);
void	ft_readmap(t_map **map, int fd);
void	ft_append_down_up_map(t_map **head, int *map_arr);
void	ft_append_prev_map(t_map **head);
void	ft_append_next_map(t_map **head, t_map *node);
void	ft_free_map(t_map **head);
/*Handle images*/
int		ft_create_textures_from_png(t_window *window);
void	ft_create_img_from_texture(t_window *window);
int		map_construct(t_window *window);
void	draw_map(t_window *window);
void	ft_map_to_window(t_window *window);
/* Misc functions */
void	hook_close_window(void *param);
int		*ft_mapsize(t_map **map);
int		game_init(void);

#endif