/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:50:41 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/28 17:41:55 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 
	--------------> getcwd() <----------------
	Determines the path name of the working directory and stores it in buffer.
*/

int	builtin_cd(int argc, char **argv)
{
	t_env	*dir;
	char	path[MAX_PATH];
	char	cwd[MAX_PATH];
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_strlcpy(path, argv[i], ft_strlen(argv[i]) + 1);
		i++;
	}
	if (path[0] != '/')
	{
		getcwd(cwd, sizeof(cwd));
		ft_strlcat(cwd, "/", 2);
		ft_strlcat(cwd, path, ft_strlen(path));
		chdir(argv[1]);
	}
	else
		chdir(argv[1]);
	return (0);
}
