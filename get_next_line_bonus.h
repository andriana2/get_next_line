/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianadovhanych <marianadovhanych@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:57 by marianadovh       #+#    #+#             */
/*   Updated: 2024/02/27 18:50:55 by marianadovh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
//malloc free
# include <stdlib.h>
//read
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
//delete
# include <stdio.h>
//LIMITS
# include <limits.h>

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