/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:58:15 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:51 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	convert_tab(char **tab, t_data *data)
{
	int		x;

	x = 0;
	while (tab[x])
	{
		if (tab[x][0] == '\0')
		{
			x++;
			continue ;
		}
		if (contains_alpha(tab[x]))
		{
			convert_tab_2(tab[x], data, x);
			x++;
		}
	}
	free_tab(tab);
}

void	convert_tab_2(char *str, t_data *data, int x)
{
	if (ft_strinstr(str, "A"))
		ambiant(str, data);
	if (ft_strinstr(str, "C"))
		cam(str, data);
	if (ft_strinstr(str, "L"))
		light(str, x, data);
	if (ft_strinstr(str, "sp"))
		sphere(str, x, data);
	if (ft_strinstr(str, "cy"))
		cylindre(str, x, data);
	if (ft_strinstr(str, "pl"))
		plan(str, x, data);
}
