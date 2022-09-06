/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:43:24 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Plakt 2de zin achter 1ste zin.

	we pakken de lengte van s1 & s2. 

	Dan mallocen we de lengte van s1 en s2 + 1 voor de null terminator.
	dan tellen we over s1 heen voor het eerste woord.

	Daarna zetten we i weer naar 0 en tellen we over s2 heen voor de tweede string,
	en zetten we s1_len in s2 zodat we wel de lengte van s1 weten.
	
	Dan zeggen we dat ptr s1_len + s2_len het einde is zodat hij dan stopt.
	Daarna return ptr.
*/

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
