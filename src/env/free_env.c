/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:50:47 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/24 18:08:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_list(t_env **head)
{
	t_env	*thead;
	t_env	*next;

	thead = *head;
	while (thead)
	{
		next = thead->next;
		free(thead->key);
		free(thead->value);
		free(thead);
		thead = next;
	}
	*head = NULL;
}
