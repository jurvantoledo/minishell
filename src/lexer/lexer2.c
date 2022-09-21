/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/21 17:29:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	set_type(char *input, int pos)
{
	if (ft_strncmp(input, "<<", 2) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (OUTFILE_APPEND);
	else if (input[pos] == '|')
		return (PIPE);
	else if (input[pos] == '<')
		return (INFILE);
	else if (input[pos] == '>')
		return (OUTFILE);
	else
		return (COMMAND);
}

static int	ft_wrlength(char *input)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	while (input[i + count] && !ft_isspace(input[i + count]))
		count++;
	return (count);
}

int	ft_pos(char *input)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (input[i])
	{
		i++;
	}
	return (pos);
}

int	add_to_list(t_lexer **head, int length, int pos, t_token_type type)
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

void	ft_snorlexer(char *input)
{
	t_lexer				*head;
	int					i;
	int					len;
	t_token_type		type;

	head = NULL;
	i = 0;
	len = 0;
	while (input[i])
	{
		len = ft_wrlength(&input[i]);
		printf("char: %c \n", input[i]);
		if (input[i] == '\"')
		{
			len = check_double_quotes(&input[i]);
			printf("len after double quotes function: %d\n", len);
			i++;
		}
		while (input[i] && ft_isspace(input[i]))
			i++;
		type = set_type(input, i);
		add_to_list(&head, len, i, type);
		i += len;
		i++;
	}
	while (head != NULL)
	{
		printf("index: %d\t lenght: %d\t type: %d\n", head->index, head->length, head->type);
		head = head->next;
	}
}


// kut "homo tieten" en andere "dingen :)"

// < infile grep "tieten" | je moer > out