/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 22:15:34 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/12/20 22:15:34 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	if (c == '\0')
		return (str + gnl_strlen(s));
	while (*str)
	{
		if (c == *str)
			return (str);
		str++;
	}
	return (NULL);
}

char	*gnl_strdup(const char *str)
{
	int		i;
	int		len;
	char	*newstr;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	newstr = malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*gnl_strcat(char *joined, char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		joined[i] = str2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*joined;

	if (!str1 || !str2)
		return (NULL);
	len1 = 0;
	while (str1[len1])
		len1++;
	len2 = 0;
	while (str2[len2])
		len2++;
	len1 = len1 + len2 + 1;
	joined = malloc(len1 * sizeof(char));
	if (joined == NULL)
		return (NULL);
	return (gnl_strcat(joined, str1, str2));
}
