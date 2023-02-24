/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:35:23 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 11:28:15 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	close_window(t_data *data)
{
	exit(0);
	return (0);
}

int	escape(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}
