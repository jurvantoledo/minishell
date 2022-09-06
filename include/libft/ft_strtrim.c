/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:58 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:44:00 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- First we check the srtlen
	- Then we trim the left side of the string by counting over the string.
	  Then if we find a similar character and trim from that character.
	  If we dont find that character we return count.
	
	- Then we trim the right side but first we take the lenght,
	  of th string and then we count back till we find the character.

	- Then we use the substr function and return: 
	  the string, the trimmed left side and the trimmed right side.
*/

int	ft_trim_left(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (!set[j])
			return (count);
		i++;
	}
	return (count);
}

int	ft_trim_right(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (!set[j])
			return (count);
		i--;
	}
	return (count + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	right = 0;
	left = ft_trim_left(s1, set);
	if (left != ft_strlen(s1))
		right = ft_trim_right(s1, set);
	return (ft_substr(s1, left, ft_strlen(s1) - right - left));
}
