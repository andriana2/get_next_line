/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianadovhanych <marianadovhanych@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:48:29 by marianadovh       #+#    #+#             */
/*   Updated: 2024/03/05 18:44:56 by marianadovh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*my_array;
	int		i;

	i = 0;
	my_array = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (my_array == NULL)
		return (NULL);
	while (s[i])
	{
		my_array[i] = s[i];
		i++;
	}
	my_array[i] = '\0';
	return (my_array);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_;
	int		s2_;
	int		i;

	if (!s1)
		s1 = "\0";
	s1_ = ft_strlen(s1);
	s2_ = ft_strlen(s2);
	i = 0;
	str = (char *)malloc((s1_ + s2_ + 1));
	if (!str || !s2)
		return (NULL);
	while (s1_--)
	{
		str[i] = s1[i];
		i++;
	}
	s1_ = i;
	i = 0;
	while (s2_--)
		str[s1_++] = s2[i++];
	str[s1_] = '\0';
	return (str);
}

int	strchr_num(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0' && str[i] == '\0')
		return (i);
	return (-1);
}
