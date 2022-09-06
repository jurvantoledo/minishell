/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:41:36 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:41:37 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

/* 
	de vorige nieuwe list word doorgeschoven, en de nieuwe 
	list word vooraan als nieuwe list gezet.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	char *c1 = "ko";
// 	char *c2 = "koos";
// 	char *c3 = "kaas";

// 	t_list *l1 = ft_lstnew(c1);
// 	t_list *l2 = ft_lstnew(c2);
// 	t_list *l3 = ft_lstnew(c3);

// 	ft_lstadd_front(&l1, l2);
// 	ft_lstadd_front(&l2, l3);

// 	t_list *head = l3;
// 	// printf("%s \n", head->next->content);
// 	while (head)
// 	{
// 		printf("%s \n", head->content);
// 		head = head->next;
// 	}
// }

// [a]->[b]->[c]->[d]