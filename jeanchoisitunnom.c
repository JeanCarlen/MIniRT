/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeanchoisitunnom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:00:46 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/15 10:32:44 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_light	*get_light_type(t_light *light, char type)
{
	while (light && light->type != type)
		light = light->next;
	return (light);
}

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
