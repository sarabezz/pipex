/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:07:51 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/06 14:16:45 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_pipex
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	char	**envp;
}	t_pipex;

// --- Funciones de validación ---
int		open_file(const char *filename, int flags, mode_t mode);

// --- Funciones del fd ---
void	ft_error(char *str);
void	ft_free(char **ptr);

// --- Función de ejecución ---
void	execute_command(char *cmd, char **envp);

// --- PIPEX ---
void	child_process(t_pipex *px, int *pipefd);
void	child_process2(t_pipex *px, int *pipefd);
void	run_pipex(t_pipex *px);
int		main(int argc, char **argv, char **envp);

#endif