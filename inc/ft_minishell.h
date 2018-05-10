/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:48:54 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/11 18:55:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "libft.h"
# include <time.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>

# define MINISHELL_EXECUTABLE_NAME "minishell"

# define SHELL_MESSAGE IRED"Dorf's Shell "IGREEN"$$ Bills Ya'll $> "IWHITE
# define SHELL_Q_QUOTE ICYAN"Q> "IWHITE
# define SHELL_D_QUOTE ICYAN"DQ> "IWHITE
# define MINISHELL_BACKSPACE "\b \b"
# define MINISHELL_HISTORY_LENGTH 100

# define INC_ENV_VAR_NAME 1
# define BUILTIN_MINISHELL_COMMAND 1
# define EXECUTABLE_MINISHELL_COMMAND 2

# define IS_QUOTE (s[i] && (s[i] == '\'' || s[i] == '\"'))
# define ML m->line

# define E_4(a, b) ((a) == get_env_var(m, (b), INC_ENV_VAR_NAME))
# define ENV_4(a, b, c, d, e) (E_4(a, b) || E_4(a, c) || E_4(a, d) || E_4(a, e))

# define S_4(a, b) (ft_strequ((a), (b)))
# define SEQ_4(a, b, c, d, e) (S_4(a, b) || S_4(a, c) || S_4(a, d) || S_4(a, e))

# define C_4(a, b) ((a) == (b))
# define CE_4(a, b, c, d, e) (C_4(a, b) || C_4(a, c) || C_4(a, d) || C_4(a, e))

# define MAX(a, b) ((b) < (a) ? (a) : (b))
# define MIN(a, b) ((b) < (a) ? (b) : (a))

/*
** 1. WIFEXITED(status): child exited normally
** • WEXITSTATUS(status): return code when child exits
**
** 2. WIFSIGNALED(status): child exited because a signal was not caught
** • WTERMSIG(status): gives the number of the terminating signal
**
** 3. WIFSTOPPED(status): child is stopped
** • WSTOPSIG(status): gives the number of the stop signal
*/

/*
** #define  SIGHUP   1   Hangup the process
** #define  SIGINT   2   Interrupt the process
** #define  SIGQUIT  3   Quit the process
** #define  SIGILL   4   Illegal instruction
** #define  SIGTRAP  5   Trace trap
** #define  SIGABRT  6   Abort
*/

/*
** wait() takes the address of an integer variable,
** and returns the process ID of the completed process.
*/

typedef struct		s_histo
{
	char			*h;
	unsigned int	was_printed_already:1;
	struct s_histo	*next;
	struct s_histo	*prev;
}					t_histo;

typedef struct		s_autoc
{
	char			*name;
	size_t			len;
	struct s_autoc	*left;
	struct s_autoc	*right;
}					t_autoc;

struct s_autoc		*g_auto;
struct s_histo		*g_hist;
struct s_histo		*g_hist_head;
char				*g_input;
int					g_tracker;

typedef	struct		s_mini
{
	char			**environ;
	char			*line;
	char			*newline;
	char			**cmds;
	int				num_of_commands;
	char			**cmd;
	int				num_of_cmd;
	char			**c;
	int				num_of_c;
	char			*tmp;
	char			**temp;
	char			*cwd;
	unsigned int	byp:1;
	struct termios	old_tio;
	struct termios	new_tio;
}					t_mini;

void				print_time(void);
void				print_shell_message(void);
int					dorfshell_error(char *s);
void				*dorfshell_null(char *s);

char				*get_input(void);
int					parse_command_line(t_mini *m);
int					check_for_open_quotes(t_mini *m);
int					expand_environmental_variables(t_mini *m);
int					free_on_complete(t_mini *m, char *s);

int					run_executable_command(t_mini *m);
int					run_builtin_command(t_mini *m);
int					run_command(t_mini *m);
void				minishell(t_mini *m);

int					is_valid_builtin_command(t_mini *m);
int					is_valid_executable_command(t_mini *m);
int					is_relative_path(t_mini *m);

char				*get_env_var(t_mini *m, char *s, int i);
char				*set_env_var(t_mini *m, char *s, char *t, int i);
char				*create_new_env_var(t_mini *m, char *s, char *t);
char				**remove_env_var(t_mini *m, char *s);
void				print_env_var(t_mini *m, char *s, int i);

char				**split_by_semicolon(t_mini *m);
char				**split_by_and(t_mini *m, char *s);
char				**split_by_arg(t_mini *m, char *s);
int					move_to_next_index_with_char(char *s, int i, char c);

int					builtin_env(t_mini *m);
int					builtin_setenv(t_mini *m);
int					builtin_unsetenv(t_mini *m);
int					builtin_cd(t_mini *m);
int					builtin_echo(t_mini *m);
int					builtin_byp(t_mini *m);

void				main_signal_catcher(int i);
void				nothing_signal_catcher(int i);
void				command_signal_catcher(int i);

void				autocomplete_create_from_dir(char *s, char *p);
t_autoc				*transform_bin_tree_into_circularly_doubly_looped_list(
					t_autoc *n);
t_autoc				*bun_tree_to_cdll(t_autoc *n);
t_autoc				*add_auto_node(t_autoc *n, char *s);
t_autoc				*create_auto_node(char *s);
void				free_looped_list(void);

void				parse_last_given_dir_and_file_name(
					char **d, char **f, char *s);

void				handle_history(int r);
void				add_input_to_history(char *s);
void				delete_nth_history(void);

#endif
