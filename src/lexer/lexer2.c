/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/20 17:13:05 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	set_type(char *input)
{
	if (ft_strncmp(input, "<<", 2) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (OUTFILE_APPEND);
	else if (input[0] == '|')
		return (PIPE);
	else if (input[0] == '<')
		return (INFILE);
	else if (input[0] == '>')
		return (OUTFILE);
	else
		return (COMMAND);
}

// static int	ft_wrlength(char *input)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (input[i])
// 	{
// 		if (!ft_isspace(input[i]))
// 		{
// 			count++;
// 			printf("%d\n", count);
// 		}
// 		else
// 			count = 0;
// 		i++;
// 	}
// 	return (count);
// }

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

int	add_to_list(t_lexer **head, int length)
{
	t_lexer	*tmp;
	t_lexer	*new;

	new = ft_calloc(sizeof(t_lexer), 1);
	if (!new)
		return (0);
	new->length = length;
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
	t_lexer	*head;
	int		i;
	int		len;

	head = NULL;
	i = 0;
	while (input[i])
	{
		len = ft_wrlength(&input[i]);
		printf("len %d \n", len);
		add_to_list(&head, len);
		while (input[i] && ft_isspace(input[i]))
			i++;
		i += len;
		i++;
	}
	printf("the length of lexer: %d\n", head->length);
}

// void	ft_snorlexer(char *input)
// {
// 	t_lexer	*lexer;
// 	t_lexer	*head;
// 	int		i;

// 	head = NULL;
// 	lexer = ft_calloc(sizeof(t_lexer), 1);
// 	if (!lexer)
// 		return ;
// 	head = lexer;
// 	lexer->length = ft_wrlength(input);
// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i])
// 		{
// 			lexer->next = ft_calloc(sizeof(t_lexer), 1);
// 			lexer = lexer->next;
// 		}
// 		i++;
// 	}
// 	printf("the length of lexer: %d\n", head->length);
// }
