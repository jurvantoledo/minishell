/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:39 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:43:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Deze functie past de gegeven functie f toe op elk teken van de gegeven
	string om een ​​nieuwe string te maken die het resultaat is van functie
	f op string s. Het stuurt een 'nieuwe' kopie van de gewijzigde string 
	en index terug.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[j] = f(i, s[i]);
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
