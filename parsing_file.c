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
			char **temp_words = (char **)ft_realloc_rt_tab(words, (word_count + 1) * sizeof(char *));
			if (!temp_words)
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
			words = temp_words;
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
	char **temp_words = (char **)ft_realloc_rt_tab(words, (word_count + 1) * sizeof(char *));
	if (!temp_words)
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
	words = temp_words;
	words[word_count] = NULL;
	return words;
}


void	convert_tab(char **tab, t_data *data)
{
	int		x;
	char	**ret;
	char	**vector;
	(void)data;

	vector = NULL;
	ret = NULL;
	x = 0;
	printf("tab is = \n");
	print_tab(tab);
	printf("-------------------\n");
	while (tab[x])
	{
		if (tab[x][0] == '\0')
		{
			x++;
			continue;
		}
		if (contains_alpha(tab[x]))
		{
//			printf("%d = x, string = %s\n", x, tab[x]);
			if (ft_strinstr(tab[x], "A"))
			{
				t_light	*new_l;
				t_light	*last;
				new_l = init_light();
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
				print_tab(ret);
				new_l->type = *ret[0];
				new_l->ratio = ft_strtof(ret[1]);
				vector = split_string(ret[2], ',');
				if (tab_check_rgb(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);;
				}
				new_l->color.x = ft_strtof(vector[0]);
				new_l->color.y = ft_strtof(vector[1]);
				new_l->color.z = ft_strtof(vector[2]);
				if (data->light == NULL)
					data->light = new_l;
				else
				{
					last = last_light(data);
					last->next = new_l;
				}
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "C"))
			{
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
print_tab(ret);
				vector = split_string(ret[1], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}				
				data->camera.pos.x = ft_strtof(vector[0]);
				data->camera.pos.y = ft_strtof(vector[1]);
				data->camera.pos.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				data->camera.orient.x = ft_strtof(vector[0]);
				data->camera.orient.y = ft_strtof(vector[0]);
				data->camera.orient.z = ft_strtof(vector[0]);
				data->camera.fov = ft_stoi(ret[3]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "L"))
			{
				t_light	*new_l;
				t_light	*last;
				new_l = init_light();
				new_l->id = (x + 1);
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
print_tab(ret);
				new_l->type = *ret[0];
				vector = split_string(ret[1], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_l->coord.x = ft_strtof(vector[0]);
				new_l->coord.y = ft_strtof(vector[1]);
				new_l->coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				new_l->ratio = ft_strtof(ret[2]);
				vector = split_string(ret[3], ',');
				if (tab_check_rgb(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);;
				}
				new_l->color.x = ft_strtof(vector[0]);
				new_l->color.y = ft_strtof(vector[1]);
				new_l->color.z = ft_strtof(vector[2]);
				if (data->light == NULL)
					data->light = new_l;
				else
				{
					last = last_light(data);
					last->next = new_l;
				}
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "sp"))
			{
				t_form	*new_f;
				t_form	*last;
				new_f = init_form();
				new_f->id = (x+1);
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
				print_tab(ret);
				new_f->type = 'S';
				vector = split_string(ret[1], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_f->coord.x = ft_strtof(vector[0]);
				new_f->coord.y = ft_strtof(vector[1]);
				new_f->coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				new_f->sphere_rad = (ft_strtof(ret[2]) / 2);
				vector = split_string(ret[3], ',');
				if (tab_check_rgb(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				new_f->color.x = ft_strtof(vector[0]);
				new_f->color.y = ft_strtof(vector[1]);
				new_f->color.z = ft_strtof(vector[2]);
				if (data->object == NULL)
					data->object = new_f;
				else
				{
					last = last_obj(data);
					last->next = new_f;
				}
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "pl"))
			{
				t_form	*new_f;
				t_form	*last;
				new_f = init_form();
				new_f->id = (x+1);
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
print_tab(ret);
				new_f->type = 'P';
				vector = split_string(ret[1], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_f->coord.x = ft_strtof(vector[0]);
				new_f->coord.y = ft_strtof(vector[1]);
				new_f->coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_f->orient.x = ft_strtof(vector[0]);
				new_f->orient.y = ft_strtof(vector[1]);
				new_f->orient.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[3], ',');
				if (tab_check_rgb(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);;
				}
				new_f->color.x = ft_strtof(vector[0]);
				new_f->color.y = ft_strtof(vector[1]);
				new_f->color.z = ft_strtof(vector[2]);
				if (data->object == NULL)
					data->object = new_f;
				else
				{
					last = last_obj(data);
					last->next = new_f;
				}
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "cy"))
			{
				t_form	*new_f;
				t_form	*last;
				new_f = init_form();
				new_f->id = (x+1);
				if (does_it_segf(tab[x]) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				ret = second_split(tab[x]);
print_tab(ret);
				new_f->type = 'C';
				vector = split_string(ret[1], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_f->coord.x = ft_strtof(vector[0]);
				new_f->coord.y = ft_strtof(vector[1]);
				new_f->coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				if (tab_check(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}	
				new_f->orient.x = ft_strtof(vector[0]);
				new_f->orient.y = ft_strtof(vector[1]);
				new_f->orient.z = ft_strtof(vector[2]);
				free_tab(vector);
				new_f->cyl_dia = ft_strtof(ret[3]);
				new_f->cyl_height = ft_strtof(ret[4]);
				vector = split_string(ret[5], ',');
				if (tab_check_rgb(vector) < 0)
				{
					if (ret)
						free_tab(ret);
					if (vector)
						free_tab(vector);
					close_window(data);
				}
				new_f->color.x = ft_strtof(vector[0]);
				new_f->color.y = ft_strtof(vector[1]);
				new_f->color.z = ft_strtof(vector[2]);
				if (data->object == NULL)
					data->object = new_f;
				else
				{
					last = last_obj(data);
					last->next = new_f;
				}
				free_tab(vector);
				free_tab(ret);
			}
			x++;
		}
	}
	free_tab(tab);
}
