/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:04:46 by mverger           #+#    #+#             */
/*   Updated: 2023/01/13 15:40:42 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init(t_data *data)
{
	data->posx = 22;
	data->posy = 12;
	data->dirx = -1;
	data->diry = -1;
	data->planex = 0;
	data->planey = 0.66;
	data->time = 0;
	data->oldtime = 0;
	data->camerax = 0;
	data->raydirx = 0;
	data->raydiry = 0;
}


