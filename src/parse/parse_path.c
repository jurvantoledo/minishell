/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:51:53 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/28 13:45:32 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_builtin(char *command)
{
	if (ft_strncmp(command, "echo", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "pwd", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "export", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "unset", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "env", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "exit", ft_strlen(command)) == 0 || \
		ft_strncmp(command, "cd", ft_strlen(command)) == 0)
		return (1);
	return (0);
}

char	**find_path(char *cmd)
{
	char	**paths;

	paths = ft_split(get_env(g_shell.env, "PATH")->value, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*parse_path(char *cmd)
{
	int		i;
	char	**paths;
	char	*temp;
	char	*path;

	paths = ft_split(get_env(g_shell.env, "PATH")->value, ':');
	if (!paths)
		return (NULL);
	path = NULL;
	i = 0;
	while (paths && paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK & X_OK) != -1)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	ft_free_char(paths);
	return (path);
}

void	resolve_path(void)
{
	int	i;

	i = 0;
	while (i < g_shell.cmd_len)
	{
		if (!check_builtin(g_shell.command[i].arguments[0]))
		{
			g_shell.command[i].path = \
								parse_path(g_shell.command[i].arguments[0]);
			if (!g_shell.command[i].path)
				return ;
			printf("the path: %s\n", g_shell.command[i].path);
		}
		i++;
	}
}
