/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:32:45 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 17:56:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define OPTION_NONE 100
# define OPTION_N 200
# define MAX_WORKING_DIRECTORY_SIZE 1024
# define COLOR_BLUE "\033[34;1m"
# define COLOR_WHITE "\033[37m"
# define COLOR_CYAN "\033[36m"
# define END_COLOR "\033[0m"
# define SPERATOR 1
# define ERROR_NONE 0
# define ERR_QUOTE "minishell: Invalid quote syntax\n"

# define LEFT_REDIRECT 1
# define RIGHT_REDIRECT 2
# define LLEFT_REDIRECT 3
# define RRIGHT_REDIRECT 4
# define PIPE 5
# define READ 0
# define WRITE 1

# define COMMAND_NOT_FOUND 127

#endif