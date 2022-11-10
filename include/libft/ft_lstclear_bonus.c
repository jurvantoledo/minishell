/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:41:43 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:41:45 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Als wij iets verwijderen, verwijderen we daarbij het adres
// naar het volgende wat wij moeten verwijderen en daarom slaan wij
// dit op in t zodat wij het volgende kunnen verwijderen.

// *lst = t om lst op 0 te zetten.

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *t;

	while (*lst != NULL)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = t;
	}
}
