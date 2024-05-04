/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianadovhanych <marianadovhanych@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:48:31 by marianadovh       #+#    #+#             */
/*   Updated: 2024/02/27 18:50:39 by marianadovh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
//malloc free
# include <stdlib.h>
//read
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
//delete
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		strchr_num(const char *str, int c);
char	*read_file(int fd, char *buffer);
char	*send_line(char *buffer);
char	*div_line(char *buffer);

#endif