/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:39:30 by jsantann          #+#    #+#             */
/*   Updated: 2022/07/16 08:53:54 by mhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	a;

	a = 0;
	while (*c)
	{
		a++;
		c++;
	}
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)(c))
			return ((char *)s + i);
		else
			i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*cp_str;

	i = 0;
	while (s[i])
		i++;
	size = (i + 1);
	cp_str = (char *)malloc(size * sizeof(char));
	if (!cp_str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cp_str[i] = s[i];
		i++;
	}
	return (cp_str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	while (i < (size - 1) && i < len && src[i])
	{
		dest[i] = src;
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*n;
	unsigned int	j;
	unsigned int	i;
	size_t			totallen;

	if (!s1 || !s2)
		return (NULL);
	totallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	n = malloc(totallen);
	i = 0;
	j = 0;
	if (n == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		n[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		n[i + j] = s2[j];
		j++;
	}
	n[i + j] = '\0';
	return (n);
}
