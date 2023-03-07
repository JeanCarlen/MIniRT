#include "MiniRT.h"

char	*readfile(char *filename)
{
	int		fd;
	char	buffer[BUFSIZE];
	char	*line;
	size_t	line_size;
	ssize_t	bytes_read;
	int		i;

	i = 0;
	line_size = 0;
	bytes_read = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("file : %s doesn't exist", filename);
		exit(0);
	}
	while ((bytes_read = read(fd, buffer, BUFSIZE)) > 0)
	{
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				line = ft_realloc_rt(line, line_size + i + 1);
				ft_memcpy(line + line_size, buffer, i);
				line[line_size + i] = '\0';
				line_size += i + 1;
				printf("%s\n", line);
				line_size = 0;
			}
			else
			{
				line = ft_realloc_rt(line, line_size + bytes_read - i);
				ft_memcpy(line + line_size, buffer + i, bytes_read - i);
				line_size += bytes_read - i;
				break ;
			}
			i++;
		}
		i = 0;
	}
	if (line_size > 0)
	{
		line = ft_realloc_rt(line, line_size + 1);
		ft_memcpy(line + line_size, "\0", 1);
	}
	close(fd);
	return (line);
}

char **split_string(const char *str, char sep)
{
	size_t count = 0;
	size_t i = 0;
	size_t j = 0;
	size_t len = 0;
	char **result = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		count += (str[i++] == sep);
	}
	result = (char **)malloc((count + 2) * sizeof(char *));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			i++;
			continue;
		}
		len = 0;
		while (str[i + len] != sep && str[i + len] != '\0')
		{
			len++;
		}
		result[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[j])
		{
			while (j-- > 0)
			{
				free(result[j]);
				result[j] = (NULL);
			}
			free(result);
			return (NULL);
		}
		ft_strncpy_rt(result[j], str + i, len);
		result[j][len] = '\0';
		i += len;
		j++;
	}
	result[j] = NULL;
	return (result);
}


char	**second_split(char *str)
{
	char	**words;
	int		word_count;
	char	*word_start;
	char	*word_end;
	int		word_length;
	int		i;

	words = NULL;
	word_count = 0;
	word_start = str;
	word_end = str;

	while (*word_end != '\0')
	{
		if (ft_isspace(*word_end))
		{
			word_start = word_end + 1;
			word_end = word_start;
			continue ;
		}
		word_end++;
		if (ft_isspace(*word_end) || *word_end == '\0')
		{
			words = (char **)ft_realloc_rt_tab(words, (word_count + 1) * sizeof(char *));
			word_length = word_end - word_start;
			words[word_count] = (char *)malloc((word_length + 1) * sizeof(char));
			if (!words[word_count])
			{
				i = 0;
				while(i < word_count)
				{
					free(words[i]);
					i++;
				}
				free(words);
				return NULL;
			}
			ft_strncpy_rt(words[word_count], word_start, word_length);
			words[word_count][word_length] = '\0';
			word_start = word_end + 1;
			word_count++;
		}
	}
	words = (char **)ft_realloc_rt_tab(words, (word_count + 1) * sizeof(char *));
	words[word_count] = NULL;
	return (words);
}


void	convert_tab(char **tab, t_data *data)
{
	int		x;
	x = 0;
	print_tab(tab);
	while (tab[x])
	{
		if (tab[x][0] == '\0')
		{
			x++;
			continue;
		}
		if (contains_alpha(tab[x]))
		{
			if (ft_strinstr(tab[x], "A"))
				ambiant(tab[x], data);
			if (ft_strinstr(tab[x], "C"))
				cam(tab[x], data);
			if (ft_strinstr(tab[x], "L"))
				light(tab[x], x, data);
			if (ft_strinstr(tab[x], "sp"))
				sphere(tab[x], x, data);
			if (ft_strinstr(tab[x], "cy"))
				cylindre(tab[x], x, data);
			if (ft_strinstr(tab[x], "pl"))
				plan(tab[x], x, data);
			x++;
		}
	}
	free_tab(tab);
}
