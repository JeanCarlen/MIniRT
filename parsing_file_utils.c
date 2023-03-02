#include "MiniRT.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		printf("\n");
		++i;
	}
}

int	ft_stoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (0);
	++i;
	}
	return (sign * result);
}

float	ft_strtof(const char* str)
{
	float	result;
	int		is_negative;
	float	decimal_multiplier;

	result = 0.0f;
	is_negative = 0;
	decimal_multiplier = 0.1f;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0f + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result += decimal_multiplier * (*str - '0');
			decimal_multiplier *= 0.1f;
			str++;
		}
	}
	if (is_negative)
		result = -result;
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
	{
		printf("Error: invalid input string\n");
		return (0.0f);
	}
	return (result);
}

int ft_strinstr(const char *str, const char *substr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == substr[0])
		{
			j = 1;
			k = i + 1;
			while (substr[j] != '\0')
			{
				if (str[k] != substr[j])
					break ;
				j++;
				k++;
			}
			if (substr[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	contains_alpha(char* str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

int	ft_isspace(int c)
{
	return ((c == ' ') || (c >= '\t' && c <= '\r'));
}

t_light	*last_light(t_data *data)
{
	t_light *curr;

	curr = data->light;
	if (curr == NULL)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

t_form	*last_obj(t_data *data)
{
	t_form *curr;

	curr = data->object;
	if (curr == NULL)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

char *ft_strncpy_rt(char *dest, const char *src, size_t n)
{
	size_t i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


void *ft_realloc_rt(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size;

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(size);
		return new_ptr;
	}
	old_size = ft_strlen(ptr);
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}
	ft_memcpy(new_ptr, ptr, old_size < size ? old_size : size);
	free(ptr);

	return (new_ptr);
}

void *ft_realloc_rt_tab(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(size);
		return new_ptr;
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);

	return (new_ptr);
}