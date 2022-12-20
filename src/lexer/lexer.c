/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/20 16:18:10 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	set_type(t_token_type *type, char *input, int pos, int len)
{
	char	*str;
	bool	expand;

	str = ft_substr(input, pos, len);
	if (!str)
		return (0);
	expand = ft_idk(input, str);
	if (ft_strncmp(str, "<<", 3) == 0 && expand)
		*type = HERE_DOC;
	else if (ft_strncmp(str, ">>", 3) == 0 && expand)
		*type = OUTFILE_APPEND;
	else if (input[pos] == '|' && expand)
		*type = PIPE;
	else if (input[pos] == '<' && expand)
		*type = INFILE;
	else if (input[pos] == '>' && expand)
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

static void	set_snorlexer(t_lexer **head, char *input, int len, int i)
{
	t_token_type	type;

	if (set_type(&type, input, i, len) == 0)
		return ;
	if (add_to_list(head, len, i, type) == 0)
		return ;
}

t_lexer	*ft_gluttony(t_lexer *head, char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i] == '\"' || input[i] == '\'')
		{
			i++;
			len = check_quotes(search_end_quote(&input[i]));
		}
		else if (special_chars(input[i]) == 0)
			len = ft_lexer_wrlength(&input[i]);
		else
			len = ft_symbol_len(&input[i]);
		if (len == 0)
			continue ;
		set_snorlexer(&head, input, len, i);
		i += len;
		len = 0;
	}
	return (head);
}

t_lexer	*ft_snorlexer(char *input)
{
	t_lexer	*head;

	head = NULL;
	head = ft_gluttony(head, input);
	post_process(input, head);
	print_list(head);
	return (head);
}

// kut "homo tieten" en andere "din gen :)"

// < infile grep "tieten" | je moer > out