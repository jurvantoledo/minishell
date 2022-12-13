/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 15:40:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/13 17:07:32 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_replace_part(char *before, char *oldsub, \
						char *newsub, char *after)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(before))
	{
		if (ft_strnstr(&before[i], oldsub, ft_strlen(oldsub)) == &before[i])
		{
			ft_strlcpy(&after[j], newsub, ft_strlen(newsub) + 1);
			i += ft_strlen(oldsub);
			j += ft_strlen(newsub);
		}
		else
		{
			after[j] = before[i];
			i++;
			j++;
		}
	}
	after[j] = '\0';
	return (after);
}

static int	ft_replace_loop(char *before, char *oldsub)
{
	int		i;
	int		before_length;
	int		old_length;
	int		occurrences;

	i = 0;
	occurrences = 0;
	before_length = ft_strlen(before);
	old_length = ft_strlen(oldsub);
	while (i < before_length)
	{
		if (ft_strnstr(&before[i], oldsub, ft_strlen(oldsub)) == &before[i])
		{
			occurrences++;
			i += old_length;
		}
		else
			i++;
	}
	return (occurrences);
}

static int	ft_replace_after(char *before, int occurrences, int sub_diff)
{
	int	after_length;
	int	before_length;

	before_length = ft_strlen(before);
	after_length = before_length;
	after_length += occurrences * sub_diff;
	return (after_length);
}

char	*ft_replace(char *before, char *oldsub, char *newsub)
{
	char	*after;
	int		before_length;
	int		new_length;
	int		old_length;
	int		sub_diff;

	old_length = ft_strlen(oldsub);
	new_length = ft_strlen(newsub);
	before_length = ft_strlen(before);
	if (old_length == new_length)
	{
		after = malloc((before_length + 1) * sizeof(char));
		if (!after)
			return (NULL);
	}
	else
	{
		sub_diff = new_length - old_length;
		after = malloc((ft_replace_after(before, \
			ft_replace_loop(before, oldsub), sub_diff) + 1) * sizeof(char));
		if (!after)
			return (NULL);
	}
	return (ft_replace_part(before, oldsub, newsub, after));
}
