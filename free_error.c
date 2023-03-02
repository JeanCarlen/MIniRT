
#include "MiniRT.h"


int	does_it_segf(char *str)
{
	int i;

	i = 0;

	while(str[i])
	{
		if (ft_isspace(str[i]))
		{
			i++;
			continue;	
		}
		if (str[i] <= '9' && str[i] >= '0')
		{
			i++;
			continue;
		}
		if (str[i] == 'A' || str[i] == 's' || str[i] == 'p' || str[i] == 'C' || str[i] == 'c' 
			|| str[i] == 'y' || str[i] == 'L' || str[i] == 'P' || str[i] == 'l' || str[i] == '-' || str[i] == '.' || str[i] == ',' )
		{
			i++;
			continue ;
		}
		if (str[i] == '\0' || str[i] ==  '\n')
			return (0);
		printf("This line seems wrong : \n%s, wrong char: %c\n", str, str[i]);
		return (-1);
	}
	return (0);
}

int	tab_check(char **tab)
{
	int i;

	i = 0;

	while(tab[i])
		i++;
	if (i != 3)
	{
		printf ("there is over/under 3 values\n");
		return (-1);
	}
	return (0);
}

int	tab_check_rgb(char **tab)
{
	int i;

	i = 0;

	while(tab[i])
	{
		
		if (ft_stoi(tab[i]) > 255 || ft_stoi(tab[i]) < 0)
		{
			printf("rgb value are not in range (0-255)\n");
			return (-1);
		}
		i++;
	}
	if (i != 3)
	{
		printf ("there is over/under 3 rbg values\n");
		return (-1);
	}
	return (0);
}

void	free_struc(t_data *data)
{
	t_form	*current;
	t_form	*next;

	current = data->object;
	next = current;
	while (next)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(data->object);
}

void	free_light(t_data *data)
{
	t_light	*current;
	t_light	*next;

	current = data->light;
	next = current;
	while (next)
	{
		next = current->next;
		free(current);
		current = next;
	}
}