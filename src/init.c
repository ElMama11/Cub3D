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

void	init_textures(t_data *data)
{
	data->img_tex = malloc(sizeof(t_img) * 4);
	// data->img_tex[0].texwidth = 128;
	// data->img_tex[0].texheight = 128;
	// data->img_tex[0].img = mlx_new_image(data->img_tex[0].mlx, TEXWIDTH, TEXHEIGHT);
	data->img_tex[0].img = mlx_xpm_file_to_image(data->mlx, "textures/chair_shinji", &data->img_tex[0].texwidth, &data->img_tex[0].texheight);

	data->img_tex[0].addr = mlx_get_data_addr(data->img_tex[0].img, &data->img_tex[0].bits_per_pixel, &data->img_tex[0].line_length, &data->img_tex[0].endian);
}

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
	init_textures(data);
}


