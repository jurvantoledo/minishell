/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 14:41:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/29 15:55:35 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_file_list(t_file *head)
{
	while (head != NULL)
	{
		printf("the infile: %s\n", head->infile);
		head = head->next;
	}
}

//1. itereer door linkedlist die de input line heeft getokenized
//2. zoeken naar alle tokentype = 0
//3. woord achter de '<' opslaan in een node voor elke tokentype = 0 die je tegenkomt
//4. hiervan een linkedlist maken (ft_lst_addback)

// TODO:
// lst_addback fixen net als bij de lexer
static int	add_to_list(t_file **head, char *infile)
{
	t_file	*tmp;
	t_file	*new;

	new = ft_calloc(sizeof(t_file), 1);
	if (!new)
		return (0);
	printf("infile in add to list function: %s\n", infile);
	new->infile = infile;
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

void	ft_redirections(char *input, t_lexer *lexer)
{
	t_file	*file;
	int		i;
	char	*infile;

	file = NULL;
	while (lexer != NULL)
	{
		i = 0;
		if (lexer->type == 0)
		{
			infile = ft_substr(input, lexer->next->index, lexer->next->length);
			if (add_to_list(&file, infile) == 0)
				return ;
		}
		lexer = lexer->next;
	}
	free(infile);
	print_file_list(file);
}

void	ft_parser(char *input, t_lexer *lexer)
{
	ft_redirections(input, lexer);
}

// PARSEN

// Redirect infile(<):
// - Zoekt naar de file die achter “<“ staat en gebruikt dat als input
// - Als we < sla woord achter < op / zelfde voor outfile

// Redirect outfile(>):
// - Maakt een file aan en pleurt de data naar die file toe

// Redirect here_doc(<<):
// - zorgt ervoor dat je prompt krijgt totdat de delimiter wordt geschreven in de prompt. Het argument achter “<<“ is de delimiter.
// - Wanneer << here_doc woorden achter << (dubbele redirection) opslaan.

// Redirect outfile append(>>):
// - Zoekt naar de file die achter “>>” komt en overwrite data die erin staat met de gegeven data in de command line

// Commands:
// - Zorgen ervoor dat de commands worden gegroepeerd indien dat nodig is, bijv bij een “command + optie” en dat vervolgens op te slaan. Dit zorgt ervoor dat je daarna de commands kan executen.
// - Maak lijst van alle opties die komen na een command zodat je die in exec kan pleuren
// -      execve(const char *path, char *const argv[], char *const envp[]);
// *Path is de relatieve pad (/bin/ls) of (${PWD}/bin/ls)
// Const *argv[] = alle opties(dus dubbele array)