/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:41:53 by jthibaul          #+#    #+#             */
/*   Updated: 2023/01/13 15:39:10 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"

int worldmap[mapWidth][mapHeight]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

double	ft_abs(double x)
{
	if (x < 0)
		return (x *= -1);
	return (x);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	calculate_step_init_sidedist(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->posx - data-> mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->posx) * data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->posy - data-> mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
	}
	
}

void	ray_calculation(t_data *data)
{
	data->mapx = (int)(data->posx); //which box of the map we're in
	data->mapy = (int)(data->posy);
	data->sidedistx = 0; //length of ray from current position to next x or y-side
	data->sidedisty = 0;
	if (data->raydirx == 0) //length of ray from one x or y-side to next x or y-side
		data->deltadistx = 1e30;
	else
		data->deltadistx = ft_abs(1 / data->raydirx);
	if (data->raydiry == 0) 
		data->deltadisty = 1e30;
	else
		data->deltadisty = ft_abs(1 / data->raydiry);
	data->perpwalldist = 0;
	data->stepy = 0;
	data->hit = 0;
	data->side = 0;
	calculate_step_init_sidedist(data); //calculate step and initial sideDist
}

void	print_vertical_line(int x, t_data *data, int draw_start, int draw_end)
{
	int	y;
	char	*dst;
	int	color;

	dst = 0;
	color = 0xffefd5; 
	y = 0;
	if (data->side == 1)
		color = 0xffefff;
	while (y < screenHeight)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		if (y > draw_start && y < draw_end)
			*dst = color;
		else
			*dst = 0x0;
		y++;
	}
}

void	calculate_wall_height(t_data *data, int x)
{
	int	line_height;
	int	h;
	int	draw_start;
	int	draw_end;

	h = screenHeight;
	line_height = (int)(h / data->perpwalldist); //Calculate height of line to draw on screen
	//calculate lowest and highest pixel to fill in current stripe
	draw_start = -line_height / 2 + h / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + h / 2;
	if (draw_end >= h)
		draw_end = h - 1;
	print_vertical_line(x, data, draw_start, draw_end);
}

void	perform_dda(t_data *data, int x)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (worldmap[data->mapx][data->mapy] > 0)
			data->hit = 1;
	}
	if (data->side == 0)
		data->perpwalldist = (data->sidedistx - data->deltadistx);
	else
		data->perpwalldist = (data->sidedisty - data->deltadisty);
	calculate_wall_height(data, x);

}

void	calculate_ray_pos(t_data *data)
{
	int	x;
	int	w;

	w = screenWidth;
	x = 0;
	while (x < w)
	{
		data->camerax = 2 * x / ((double)w - 1); //x-coordinate in camera space, calculate ray position and direction 3l+
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		// calcul de la distance du prochain mur pour le rayon
		ray_calculation(data);
		perform_dda(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	done()
{
	return (1);
}

void img_init(t_data *data)
{
	data->img = mlx_new_image(data->mlx, screenWidth, screenHeight);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int main()
{
	t_data	data;

	init(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Cube3D");
	img_init(&data);
	while (done())
	{
		calculate_ray_pos(&data);
	}
}
