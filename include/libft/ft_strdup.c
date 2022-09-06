/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:12 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:43:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
