/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/10 18:04:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	set_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	if (ft_strncmp(str, "<<", 3) == 0)
		*type = HERE_DOC;
	else if (ft_strncmp(str, ">>", 3) == 0)
		*type = OUTFILE_APPEND;
	else if (input[pos] == '|')
		*type = PIPE;
	else if (input[pos] == '<')
		*type = INFILE;
	else if (input[pos] == '>')
		*type = OUTFILE;
	else
		*type = COMMAND;
	free(str);
	return (1);
}

static int	add_to_list(t_lexer **head, int length, int pos, t_token_type type)
{
	t_lexer	*tmp;
	t_lexer	*new;

	new = ft_calloc(sizeof(t_lexer), 1);
	if (!new)
		return (0);
	new->length = length;
	new->index = pos;
	new->type = type;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	set_snorlexer(t_lexer **head, char *input, int len, int i)
{
	t_token_type	type;

	if (set_type(&type, input, i, len) == 0)
		return ;
	if (add_to_list(head, len, i, type) == 0)
		return ;
}

t_lexer	*ft_snorlexer(char *input)
{
	t_lexer				*head;
	int					i;
	int					len;

	head = NULL;
	i = 0;
	len = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		len = check_input(input, i);
		set_snorlexer(&head, input, len, i);
		i += len;
		len = 0;
		if (input[i] == '\"' || input[i] == '\'')
			i++;
	}
	post_process(input, head);
	print_list(head);
	return (head);
}

// kut "homo tieten" en andere "din gen :)"

// < infile grep "tieten" | je moer > out