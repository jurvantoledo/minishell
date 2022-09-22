/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 12:28:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/22 13:58:09 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || \
			c == ' ' || c == '\\' || c == ';');
}
