/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:43:16 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:43:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
	Deze functie vraagt dus in principe:
	Iedere keer dat hij over s heen telt vraagt hij om functie f
	want striteri wijst naar adres van andere functie.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
