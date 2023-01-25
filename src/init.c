/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:04:46 by mverger           #+#    #+#             */
/*   Updated: 2023/01/25 17:58:06 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
// void		img_to_tab(t_img *texture)
// {
// 	int		size;
// 	int		x;
// 	int		y;
// 	int		count;
// 	int		color;

// 	count = 0;
// 	y = -1;
// 	size = texture->texheight * texture->texwidth;
// 	texture->my_img = (unsigned int*)malloc(sizeof(int) * size);
// 	while (++y < texture->texheight)
// 	{
// 		x = -1;
// 		while (++x < texture->texwidth)
// 		{
// 			color = texture->addr[(y * texture->line_length +
// 					((x * texture->bits_per_pixel) / 8 + 2))];
// 			color = (color << 8) | texture->addr[(y * texture->line_length +
// 					((x * texture->bits_per_pixel) / 8 + 1))];
// 			color = (color << 8) | texture->addr[(y * texture->line_length +
// 					((x * texture->bits_per_pixel) / 8))];
// 			texture->my_img[count] = color;
// 			count++;
// 		}
// 	}
// }

void	init_textures(t_data *data, char **path_tex)
{
	data->img_tex[0].img = mlx_xpm_file_to_image(data->mlx, "textures/chair_shinji", &data->img_tex[0].texwidth, &data->img_tex[0].texheight);
	data->img_tex[0].addr = mlx_get_data_addr(data->img_tex[0].img, &data->img_tex[0].bits_per_pixel, &data->img_tex[0].line_length, &data->img_tex[0].endian);
	data->img_tex[1].img = mlx_xpm_file_to_image(data->mlx, path_tex[1], &data->img_tex[1].texwidth, &data->img_tex[1].texheight);
	printf("%pLA\n", data->img_tex[1].img);
	data->img_tex[1].addr = mlx_get_data_addr(data->img_tex[1].img, &data->img_tex[1].bits_per_pixel, &data->img_tex[1].line_length, &data->img_tex[1].endian);
	data->img_tex[2].img = mlx_xpm_file_to_image(data->mlx, path_tex[2], &data->img_tex[2].texwidth, &data->img_tex[2].texheight);
	data->img_tex[2].addr = mlx_get_data_addr(data->img_tex[2].img, &data->img_tex[2].bits_per_pixel, &data->img_tex[2].line_length, &data->img_tex[2].endian);
	data->img_tex[3].img = mlx_xpm_file_to_image(data->mlx, path_tex[3], &data->img_tex[3].texwidth, &data->img_tex[3].texheight);
	data->img_tex[3].addr = mlx_get_data_addr(data->img_tex[3].img, &data->img_tex[3].bits_per_pixel, &data->img_tex[3].line_length, &data->img_tex[3].endian);
	// img_to_tab(data->img_tex);
}

void	init(t_data *data, char **path_tex)
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
	init_textures(data, path_tex);
}

