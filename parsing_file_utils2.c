#include "MiniRT.h"

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
	t_light	*curr;

	curr = data->light;
	if (curr == NULL)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

t_form	*last_obj(t_data *data)
{
	t_form	*curr;

	curr = data->object;
	if (curr == NULL)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

char	*ft_strncpy_rt(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
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
