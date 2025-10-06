/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:32:29 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/06 14:47:25 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env(char **envp, const char *var_name)
{
	size_t	len;
	int		i;

	len = ft_strlen(var_name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

static char	**get_paths(char **envp)
{
	char	*path_value;
	char	**paths;

	path_value = get_env(envp, "PATH");
	if (!path_value)
	{
		perror("PATH not found");
		exit(EXIT_FAILURE);
	}
	paths = ft_split(path_value, ':');
	if (!paths)
	{
		perror("ft_split failed");
		exit(EXIT_FAILURE);
	}
	return (paths);
}

static char	*find_command_path(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd, '/'))
    {
        if (access(cmd, X_OK) == 0)
            return strdup(cmd);
        return (NULL);
    }
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_command(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;
	char	**args;

	paths = get_paths(envp);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_free(paths);
		ft_error("Invalid command");
	}
	cmd_path = find_command_path(paths, args[0]);
	if (!cmd_path)
	{
		ft_free(paths);
		ft_free(args);
		ft_error("Command not found");
	}
	printf("DEBUG: cmd_path = '%s'\n", cmd_path);
	execve(cmd_path, args, envp);
	perror("exceve failed");
	ft_free(args);
	free(cmd_path);
	ft_free(paths);
	exit(EXIT_FAILURE);
}
