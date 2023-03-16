/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:48 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/16 11:56:08 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static const char	*skip_stuff(const char *str, int *neg)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		*neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

static float	end_stuff(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
	{
		printf("Error: invalid input string\n");
		return (0.0f);
	}
	return (1.0f);
}

float	ft_strtof(const char *str)
{
	float	result;
	int		is_negative;
	float	decimal_multiplier;

	result = 0.0f;
	is_negative = 1;
	decimal_multiplier = 0.1f;
	str = skip_stuff(str, &is_negative);
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
	return (result * is_negative * end_stuff(str));
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

int	ft_strinstr(const char *str, const char *substr)
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
