/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:15:06 by hmiyake           #+#    #+#             */
/*   Updated: 2019/09/01 13:13:41 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	now_in_str(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*mallocandcopy(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (str)
	{
		while (s[i] != '\0' && s[i] != c)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		now;

	i = 0;
	if (!s)
		return (0);
	now = now_in_str(s, c);
	arr = (char **)malloc(sizeof(char *) * (now + 1));
	if (arr)
	{
		while (i < now)
		{
			while (*s == c)
				s++;
			if (*s)
				arr[i] = mallocandcopy(s, c);
			while (*s && *s != c)
				s++;
			i++;
		}
		arr[i] = 0;
	}
	return (arr);
}
