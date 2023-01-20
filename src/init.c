/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:04:46 by mverger           #+#    #+#             */
/*   Updated: 2023/01/19 17:33:57 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init(t_data *data)
{
	data->posx = 22;
	data->posy = 12;
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->time = 0;
	data->oldtime = 0;
	data->camerax = 0;
	data->raydirx = 0;
	data->raydiry = 0;
	data->draw_end = 0;
	data->draw_start = 0;
	data->texnum = 0;
	data->texx = 0;
}

