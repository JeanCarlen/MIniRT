/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:51:25 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:23 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

char	**split_string(const char *str, char sep)
{
	size_t	count;
	char	**result;

	count = set_count(str, sep);
	if (count < 0)
		return (NULL);
	result = (char **)malloc((count + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	result = split_string_2(str, sep, result);
	return (result);
}

char	**split_string_2(const char *str, char sep, char **result)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		len = 0;
		while (str[i + len] != sep && str[i + len] != '\0')
			len++;
		result[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[j])
			return (split_string_free(j, result));
		ft_strncpy_rt(result[j], str + i, len);
		result[j][len] = '\0';
		i += len;
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**split_string_free(size_t j, char **result)
{
	while (j-- > 0)
	{
		free(result[j]);
		result[j] = (NULL);
	}
	free(result);
	return (NULL);
}

size_t	set_count(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		count += (str[i++] == sep);
	return (count);
}
