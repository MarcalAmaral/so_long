/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:42:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/07/05 19:29:18 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	char			byte;
	struct s_node	*next;
}	t_byte;

typedef struct s_vars {
	t_byte		*str;
	char		buffer[BUFFER_SIZE];
	int			fd;
	long long	iter;
	long long	len;
	long long	bytes_read;
}	t_vars;

char	*get_next_line(int fd);
t_byte	*ft_newnode(char content);
void	ft_addend_list(t_byte **head, t_byte *new);
char	*ft_cpybuffer(t_vars *vars);
char	*ft_returnline(t_vars *vars);

#endif