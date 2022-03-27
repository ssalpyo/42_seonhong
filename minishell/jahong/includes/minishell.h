/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:57:27 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/24 17:02:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "define.h"
# include "types.h"
# include "../library/includes/libft.h"
# include "../library/includes/get_next_line.h"

int		g_exit_status;

void	ft_echo(char **commands, char **envs);
void	ft_env(char **envs);
void	ft_pwd(char **cmd);
int		ft_cd(char **cmd, char ***envs_addr);
void	ft_export(char **cmd, char ***envs_addr, int global);
int		ft_unset(char **cmd, char ***envs_addr);
void	ft_exit(char **cmd);
void	ft_strjoin_char(char **dst, char ch);
char	**normalize_inputs(char **inputs, char **envs);
char	*find_value_in_envs(char *key, char **envs);
int		remove_char(char *str, char c);

char	**init_envs(char **env);
char	*read_input(char **input);
void	init_signal(void (*handler)(int));
void	signal_handler(int signo);
int		check_input(char *input);
void	free_strs(char **str);
char	**ft_split_ms(char const *s, char c);
void	execute_cmd(char **cmd, char ***envs_addr);
void	set_env_var(char *key, char *cwd, char ***envs_addr);
char	*get_env_var(char *var, char **envs);
int		change_dir(char *path, int print_path, char ***envs_addr);
int		ft_isdigit_str(char *str);
int		find_env_var(char *var, char **envs);
char	**realloc_env(int new_size, char ***envs);

void	run_redipe(char **cmd);
int		print_error(char *target, char *msg, char *arg);
char	*extract_key(char *str);
void	normalize_input(char **normalized, char *src, char **envs);
int		right_redirect(char **cmd, int i, int flag);
int		left_redirect(char **cmd, int i);
int		lleft_redirect(char **cmd, int i);
int		ms_pipe(char **cmd, int i);
char	*ft_strjoin_ref(char **ref, char *str);
int		exec_builtins(char **cmd, char ***envs_addr);
int		is_redipe(char *str);
void	signal_none_handler(int signo);

#endif