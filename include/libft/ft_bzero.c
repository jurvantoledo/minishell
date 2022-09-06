/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:40:34 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:40:35 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	We set an 'n' amount of bytes to '0' on 'void *s'.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
