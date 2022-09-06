/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:41:04 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:41:22 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	We gebruiken de get length functie om de lengthe van n te krijgen.
	Daarna mallocen we de length van n.
	als n 0 is returnen we 1 omdat 0 nog steeds 1 character is.
	n < 0 is voor min teken.
	gaat over n heen en dan geeft ie het resultaat daarvan
	dat store je weer in n dan increase je i iedere keer dat je over n gaat
	n = bijv: 1234
	n / 10 = 123
	n / 10 = 12
	n / 10 = 1
	n / 10 = 0
	nu is er 4x over n heen gegaan i = dus 4
*/

int	get_length(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/* 
	We gebruiken functie om te kijken of N een negatief getal is. 
	Als dat zo is doen we n * -1 om het weerk positief te maken.
*/

int	is_neg(int k)
{
	if (k < 0)
	{
		return (k * -1);
	}
	return (k);
}

/* 
	We mallocen dus de lengte van N + 1 voor de null terminator.
	Dan zeggen we dat str[get_length(n)] het einde van de string is.
	Itoa kijkt uiteindelijk of N lager is dan 0 als dat zo is word 
	de eerste index van str '-'
	Dan maken we een nieuwe int aan genaamd len en die doen we - 1 
	zodat we op 0 beginnen.

	While N lager is dan -9 of n hoger is dan 9 ga dan over de while loop heen.
	Dan zeggen we str[len] (zodat we de lengte van de string hebben) 
	is functie(n % 10) + '0' 
	(we zetten functie om de N % 10 heen om te kijken of het een min getal is,
	Daarna doen we nog + character 0 omdat 0 begint op getal 48 in ascii table.)

	daarna kijken we of we N kunnen delen door tien 10 en we doen len-- om 
	terug te tellen naar 0.
	Op het einde zeggen we dan nog str[len] = functie(n) + '0' zodat als het niet 
	door de while loop gaat N het getal is. 
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = malloc(get_length(n) + 1);
	if (str == NULL)
		return (0);
	str[get_length(n)] = '\0';
	len = get_length(n) - 1;
	if (n < 0)
		str[0] = '-';
	while (n < -9 || n > 9)
	{
		str[len] = is_neg(n % 10) + '0';
		n = n / 10;
		len--;
	}
	str[len] = is_neg(n) + '0';
	return (str);
}

// index:
// 0 1 2 3
// getallen:
// 5 0 8 6

// int	main()
// {
// 	int	n;
// 	int	i;

// 	n = 1234;
// 	i = 0;
// 	while (n != 0)
// 	{
// 		n = n / 10;
// 		i++;
// 		printf("beter dat je werkt: %d \n", n);
// 		printf("stink hond: %d \n", i);
// 	}
// }
