/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 10:02:50 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 10:02:52 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1000000

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*ptr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 1);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[s1_len + i] = s2[i];
		i++;
	}
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}

// copy_sentence is for everything before \n
// ft_remainder is for everything behind \n to store.

static char	*ft_print_sentence(int fd, char **remainder, int read_val)
{
	char	*temp;

	if (ft_strchr(*remainder, '\n'))
	{
		temp = copy_sentence(*remainder);
		if (!temp)
			return (temp);
		*remainder = ft_remainder(*remainder);
		return (temp);
	}
	else if (read_val != 0)
		return (get_next_line(fd));
	temp = *remainder;
	*remainder = NULL;
	return (temp);
}

static char	*ft_join_string(int fd, char **remainder, char *buf, int read_val)
{
	char	*temp;

	if (*remainder == NULL && read_val == 0)
		return (NULL);
	if (*remainder == NULL && read_val)
	{
		*remainder = ft_strdup(buf);
		if (!*remainder)
			return (NULL);
	}
	else
	{
		temp = ft_strjoin(*remainder, buf);
		if (!temp)
			return (NULL);
		free(*remainder);
		*remainder = temp;
	}
	return (ft_print_sentence(fd, &*remainder, read_val));
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	int			read_val;

	read_val = read(fd, buf, BUFFER_SIZE);
	if (read_val < 0)
		return (0);
	buf[read_val] = '\0';
	return (ft_join_string(fd, &remainder, buf, read_val));
}
