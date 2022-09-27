/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/27 17:17:01 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	set_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	if (ft_strncmp(input, "<<", 3) == 0)
		*type = HERE_DOC;
	else if (ft_strncmp(input, ">>", 3) == 0)
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

static int	ft_wrlength(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i] && !ft_isspace(input[i]) && !special_chars(input[i]))
	{
		// if (input[i] == '\"' || input[i] == '\'')
		// {
		// 	return (check_quotes(&input[i]));
		// }
		i++;
	}
	return (len);
}

static int	ft_symbol_len(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i]))
	{
		if ((input[i] == '<' && input[i + 1] == '<') || \
		(input[i] == '>' && input[i + 1] == '>'))
			return (2);
		else if (special_chars(input[i]))
			return (1);
	i++;
	}
	return (0);
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

t_lexer	*ft_snorlexer(char *input)
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
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (!special_chars(input[i]))
			len = ft_wrlength(&input[i]);
		else
			len = ft_symbol_len(&input[i]);
		if (set_type(&type, input, i, len) == 0)
			return (NULL);
		if (add_to_list(&head, len, i, type) == 0)
			return (NULL);
		i += len;
		len = 0;
	}
	print_list(head);
	return (head);
}

// kut "homo tieten" en andere "din gen :)"

// < infile grep "tieten" | je moer > out