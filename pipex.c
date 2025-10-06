/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 02:25:55 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/06 13:47:15 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *px, int *pipefd)
{
	int	infile;

	infile = open(px->file1, O_RDONLY);
	if (infile < 0)
		ft_error("Error opening input file");
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	execute_command(px->cmd1, px->envp);
}

void	child_process2(t_pipex *px, int *pipefd)
{
	int	outfile;

	outfile = open(px->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error("Error opening output file");
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	close(outfile);
	execute_command(px->cmd2, px->envp);
}

void	run_pipex(t_pipex *px)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		ft_error("Pipe creation failed");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Fork failed");
	if (pid1 == 0)
		child_process(px, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Fork failed");
	if (pid2 == 0)
		child_process2(px, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		ft_error("Invalid arguments");
	px.file1 = argv[1];
	px.cmd1 = argv[2];
	px.cmd2 = argv[3];
	px.file2 = argv[4];
	px.envp = envp;
	run_pipex(&px);
	return (0);
}
