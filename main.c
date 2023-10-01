/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:55:38 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/01 02:11:23 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size);
static int	count_words(const char *s, char c);
static char	*substr_split(const char *s, int start, int end);
size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = -1;
	while (counter++, *s)
		s++;
	return (counter);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size == 0x0 || nmemb == 0x0)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
	{
		i = 0;
		while (i < (nmemb * size))
			{
				ptr[i] = 0x0;
				i++;
			}
	}
	return ((void *) ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	j;
	int		index;

	if (!s)
		return (0);
	ret = (char **) ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!ret)
		return (0);
	j = 0;
	i = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			ret[j++] = substr_split(s, index, i);
			index = -1;
		}
		i++;
	}
	return (ret);
}

static char	*substr_split(const char *s, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *) ft_calloc((end - start + 1), sizeof(char));
	while (start < end)
		ret[i++] = s[start++];
	return (ret);
}

static int	count_words(const char *s, char c)
{
	int		counter;
	int		target;

	counter = 0;
	target = 0;
	while (*s)
	{
		if (*s != c && target == 0)
		{
			target = 1;
			counter++;
		}
		else if (*s == c && target > 0)
			target = 0;
		s++;
	}
	return (counter);
}


char **ft_read_map(const char *path_map)
{
	char 	*line;
	char	*all_line;
	char	**map;
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (!fd)
		ft_printf("Deu merda");
	all_line = (char *) ft_calloc(1, sizeof(char));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		all_line = ft_strjoin(all_line, line);
		free(line);
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	close(fd);
	return (map);
}

int	main(int argc, char *argv[])
{
	char **map;

	map = ft_read_map(argv[1]);
	return (argc);
}