/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:28:13 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/16 16:16:50 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <ctype.h>

// t_token_type	set_type(char *input)
// {
// 	if (ft_strncmp(input, "<<", 3) == 0)
// 		return (HERE_DOC);
// 	else if (ft_strncmp(input, ">>", 3) == 0)
// 		return (OUTFILE_APPEND);
// 	else if (ft_strncmp(input, "|", 2) == 0)
// 		return (PIPE);
// 	else if (ft_strncmp(input, "<", 2) == 0)
// 		return (INFILE);
// 	else if (ft_strncmp(input, ">", 2) == 0)
// 		return (OUTFILE);
// 	else
// 		return (COMMAND);
// }

// int	ft_get_word(char *input, int pos, t_lexer *lexer)
// {
// 	char	*str;

// 	while (ft_isspace(input[pos]) == 0 && input[pos])
// 	{
// 		str[pos] = input[pos];
// 		pos++;
// 	}
// 	return (pos);
// // loop door het woord heen
// // zet het in head->input
// // zet len in head->length
// // vul in head->idx
// // mee geven waar positie is na het itereren
// }

// int	ft_wrlength(char *input, t_lexer *lexer)
// {
// 	int	idx;
// 	int	len;

// 	idx = 0;
// 	len = 0;
// 	while (input[idx])
// 	{
// 		if (special_chars(input) == 1)
// 		{
// 			lexer->length = 1;
// 			lexer->input = input[idx];
// 			lexer->index = idx;
// 		}
// 		else // hier is het een woord
// 		{
// 			// loop door het woord heen
// 			// zet het in head->input
// 			// zet len in head->length
// 			// vul in head->idx
// 		}
// 		len = 0;
// 		idx++;
// 	}
// }

// void	get_type(t_lexer *lexer)
// {
// 	t_lexer	*head;
// 	int		i;

// 	head = ft_calloc(sizeof(t_lexer), 1);
// 	head = lexer;
// 	i = 0;
// 	while (lexer->input[i])
// 	{
// 		lexer->length = ft_wrlength(lexer->input);
// 		if (lexer->length)
// 		{
// 			lexer->next = lexer;
// 		}
// 		i++;
// 	}
// 	printf("input: %s\n", head->input);
// 	printf("length of word: %d\n", head->next->length);
// }

// void	init_snorlexer(char *input)
// {
// 	t_lexer	*lexer;

// 	lexer = ft_calloc(sizeof(t_lexer), 1);
// 	lexer->input = input;
// 	lexer->next = NULL;
// 	lexer->index = 0;
// 	lexer->length = 1;
// 	get_type(lexer);
// }

// // 1. door de input itereren
// // 2. woordlengte vinden
// // 3. indexeren van elk argument
// // 4. token bepalen op woordlengte
// // 5. token in t_lexer gooien
// void	snorlexer(char *input, t_lexer *head)
// {
// 	int	idx;

// 	idx = 0;
// 	while (input[idx])
// 	{
// 		// bepalen wat het karakter is
// 		head->length = ft_wrlength(input, head);
// 		// bepalen lengte + geven idx
// 		// token bepalen op woordlengte en idx
// 		// token in t_lexer
// 		idx++;
// 	}
// }
