/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:35:23 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 13:29:45 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	escape(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}
