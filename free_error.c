
#include "MiniRT.h"


int	does_it_segf(char *str)
{
	int i;

	i = 0;

	while(str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		if (str[i] <= 9 && str[i] >= 0)
			i++;
		if (str[i] == 'A' || str[i] == 's' || str[i] == 'p' || str[i] == 'C' || str[i] == 'c' 
			|| str[i] == 'y' || str[i] == 'L' || str[i] == 'p' || str[i] == 'l' || str[i] == '-' || str[i] == '.' )
			i++;
		if (str[i] == '\0')
			return (0);
		else
		{
			printf("This line seems wrong : \n%s\n", str);
			return (-1);
		}
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
		
		if (ft_stoi(tab[i]) > 255 && ft_stoi(tab[i]) < 0)
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
