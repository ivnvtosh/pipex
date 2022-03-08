/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:01:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 20:01:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	child_first(char *command, char **envp, char *in, int fifo[2]);
void	child_last(char *command, char **envp, char *out, int fifo[2]);
void	child(char *command, char **envp, int in, int out);

size_t	ft_strlen(const char *string);
void	ft_putstr_fd(const char *string, int fd);
int		ft_strncmp(const char *string1, const char *string2, size_t n);
void	ft_strcpy(const char *string_from, char *string_in);
char	*ft_strjoin(char const *string_1, char const *string_2);
void	ft_strlcpy(const char *string_from, char *string_in, size_t length);
char	*ft_substr(char const *string, size_t start, size_t length);
char	**ft_split(char const *s, char c);
void	ft_free(char **pointer);
void	ft_close(int fifo[2]);
void	terminate(const char *string);

#endif
