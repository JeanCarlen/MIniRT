/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:58:15 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/16 16:24:18 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

char	**second_split(char *str)
{
	char	**w;
	char	*word_start;
	char	*word_end;
	int		w_len;

	w_len = 0;
	w = NULL;
	word_start = str;
	word_end = str;
	w = second_split_2(w, word_end, word_start, w_len);
	return (w);
}

char	**second_split_free(int w_count, char **words)
{
	int	i;

	i = 0;
	while (i < w_count)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**second_split_2(char **w, char *word_end, char *word_start, int w_len)
{
	int		w_count;

	w_count = 0;
	while (*word_end != '\0')
	{
		while (ft_isspace(*word_end))
		{
			word_start = word_end + 1;
			word_end = word_start;
		}
		word_end++;
		if (ft_isspace(*word_end) || *word_end == '\0')
		{
			w = (char **)ft_realloc_rt_tab(w, (w_count + 1) * sizeof(char *));
			w_len = word_end - word_start;
			w = second_split_3(w, w_count, w_len);
			ft_strncpy_rt(w[w_count], word_start, w_len);
			w[w_count][w_len] = '\0';
			word_start = word_end + 1;
			w_count++;
		}
	}
	w = (char **)ft_realloc_rt_tab(w, (w_count + 1) * sizeof(char *));
	w[w_count] = NULL;
	return (w);
}

char	**second_split_3(char **w, int w_count, int w_len)
{
	w[w_count] = (char *)malloc((w_len + 1));
	if (!w[w_count])
		return (second_split_free(w_count, w));
	return (w);
}
