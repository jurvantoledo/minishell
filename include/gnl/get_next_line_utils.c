/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 10:01:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 10:02:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	i = 0;
	cdst = (char *)dst;
	csrc = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (0);
	ft_memcpy(dst, src, len);
	return (dst);
}

char	*copy_sentence(char *string)
{
	int		i;
	int		size;
	char	*sentence;

	size = ft_strchr(string, '\n') - string;
	sentence = malloc(sizeof(char) * (size + 2));
	if (!sentence)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sentence[i] = string[i];
		i++;
	}
	sentence[i] = '\n';
	sentence[i + 1] = '\0';
	return (sentence);
}

char	*ft_remainder(char *string)
{
	char	*temp;

	temp = ft_strchr(string, '\n') + 1;
	if (*temp)
	{
		temp = ft_strdup(temp);
		if (!temp)
			return (0);
		free(string);
		return (temp);
	}
	free(string);
	return (0);
}
