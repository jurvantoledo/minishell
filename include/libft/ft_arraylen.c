/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraylen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:53:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/26 10:54:50 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arraylen(char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}
