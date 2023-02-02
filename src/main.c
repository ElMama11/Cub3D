/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:41:53 by jthibaul          #+#    #+#             */
/*   Updated: 2023/02/02 16:59:03 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"
// int worldmap[MAPWIDTH][MAPHEIGHT]=
// {
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

static int	ft_count_digit(int n)
{
	int	nb_digit;

	nb_digit = 0;
	if (n < 0)
		nb_digit++;
	while (n != 0)
	{
		nb_digit++;
		n /= 10;
	}
	return (nb_digit);
}

static char	*malloc_str(char *str_output, int nb_digit)
{
	str_output = (char *)malloc(sizeof(char) * (nb_digit + 1));
	if (str_output == NULL)
		return (NULL);
	str_output[nb_digit] = '\0';
	return (str_output);
}

static char	*output_cpy(int n, int nb_digit, char *str_output, int neg)
{
	int	i;
	int	r;
	int	j;

	j = 0;
	i = 0;
	nb_digit -= 1;
	if (neg == 1)
		str_output[i++] = '-';
	while (n != 0)
	{
		r = n % 10;
		if (r < 0)
		{
			r *= -1;
		}
		str_output[nb_digit--] = r + '0';
		j++;
		n = n / 10;
	}
	return (str_output);
}

char	*ft_itoa(int n)
{
	char	*str_output;
	int		nb_digit;
	int		neg;

	str_output = NULL;
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nb_digit = ft_count_digit(n);
	str_output = malloc_str(str_output, nb_digit);
	if (str_output == NULL)
		return (NULL);
	str_output = output_cpy(n, nb_digit, str_output, neg);
	return (str_output);
}

// void	hud_debug(t_data *data)
// {
// 	char *x = ft_itoa(data->posx);
// 	char *y = ft_itoa(data->posy);
// 	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0x00fffff, "posx:");
// 	mlx_string_put(data->mlx, data->mlx_win, 80, 10, 0x00fffff, x);
// 	mlx_string_put(data->mlx, data->mlx_win, 10, 30, 0x00fffff, "posy:");
// 	mlx_string_put(data->mlx, data->mlx_win, 80, 30, 0x00fffff, y);
// }

void	free_all(t_data *data)
{
	free_worldmap(data);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_tex[0].img);
	mlx_destroy_image(data->mlx, data->img_tex[1].img);
	mlx_destroy_image(data->mlx, data->img_tex[2].img);
	mlx_destroy_image(data->mlx, data->img_tex[3].img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_all(data);
	exit(0);
	return (0);
}

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
}

void	print_vertical_line(int x, t_data *data)
{
	int	y;
	unsigned int	*dst;

	dst = 0;
	y = 0;
	while (y < SCREENHEIGHT)
	{
		dst = (unsigned int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));	
		*dst = data->buffer[y][x];
		y++;
	}
}

void	fill_buf(t_data *data, int x, int lineheight, int h)
{
	double			step;
	double			texpos;
	int				y;
	int				texy;
	unsigned int			*color;

	y = 0;
	step = 1.0 * TEXHEIGHT / lineheight;
	texpos = (data->draw_start - h / 2 + lineheight / 2) * step;
	while (y < SCREENHEIGHT)
	{
		while (y > data->draw_start && y < data->draw_end)
		{
			texy = (int)texpos & (TEXHEIGHT - 1);
			texpos += step;
			color = (unsigned int *)(data->img_tex[data->texnum].addr + ((texy * data->img_tex[data->texnum].line_length) + ((int)data->texx * (data->img_tex[data->texnum].bits_per_pixel / 8))));
			data->buffer[y][x] = *color;
			y++;
		}
		color = malloc(sizeof(char) * 1);
		if (y > SCREENHEIGHT / 2)
			*color = data->floor;
		else
			*color = data->ceiling;
		data->buffer[y][x] = *color;
		free(color);
		y++;
	}
}

void	wall_hitpoint(t_data *data)
{
	double	wallx;
	
	data->texx = 0;
	if (data->side == 0)
	{
		if(data->raydirx < 0)
		{
			data->texnum = 0;
		}
		else
		{
			data->texnum = 1;
		}
		wallx = data->posy + data->perpwalldist * data->raydiry;
	}
	else
	{
		if(data->raydiry < 0)
		{
			data->texnum = 2;

		}
		else
		{
			data->texnum = 3;
		}
		wallx = data->posx + data->perpwalldist * data->raydirx;
	}
	wallx -= floor((wallx));
	data->texx = (int)(wallx * (double)TEXWIDTH);
	if (data->side == 0 && data->raydirx > 0)
		data->texx = TEXWIDTH - data->texx - 1;
	else if (data->side == 1 && data->raydiry < 0)
	{
		data->texx = TEXWIDTH - data->texx - 1;
	}
	data->wallx = wallx;
}

void	calculate_wall_height(t_data *data)
{
	int	lineheight;
	int	h;
	
	h = SCREENHEIGHT;
	lineheight = (int)(h / data->perpwalldist); //Calculate height of line to draw on screen
	//calculate lowest and highest pixel to fill in current stripe
	data->draw_start = -lineheight / 2 + h / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = lineheight / 2 + h / 2;
	if (data->draw_end >= h)
		data->draw_end = h - 1;
}

void	perform_dda(t_data *data)
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
		if (data->worldmap[data->mapx][data->mapy] == '1')
			data->hit = 1;
	}
	if (data->side == 0)
		data->perpwalldist = (data->sidedistx - data->deltadistx);
	else
		data->perpwalldist = (data->sidedisty - data->deltadisty);
}

void	clear_buf(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREENHEIGHT)
	{
		while (x < SCREENWIDTH)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
		x = 0;
	}
}

void	calculate_ray_pos(t_data *data)
{
	int	x;

	x = 0;
	clear_buf(data);
	while (x < SCREENWIDTH)
	{
		data->camerax = 2 * x / (double)SCREENWIDTH - 1; //x-coordinate in camera space, calculate ray position and direction 3l+
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		// calcul de la distance du prochain mur pour le rayon
		ray_calculation(data);
		calculate_step_init_sidedist(data); //calculate step and initial sideDist
		perform_dda(data);
		calculate_wall_height(data);
		wall_hitpoint(data);
		fill_buf(data, x, SCREENHEIGHT/ data->perpwalldist, SCREENHEIGHT);
		print_vertical_line(x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	rotate(t_data *data, int direction)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(ROTSPEED * direction) - data->diry * sin(ROTSPEED * direction);
	data->diry = olddirx * sin(ROTSPEED * direction) + data->diry * cos(ROTSPEED * direction);
	oldplanex = data->planex;
	data->planex = data->planex	* cos(ROTSPEED * direction) - data->planey * sin(ROTSPEED * direction);
	data->planey = oldplanex * sin(ROTSPEED * direction) + data->planey * cos(ROTSPEED * direction);
}

void	walk_forward(t_data *data)
{
	if (data->worldmap[(int)(data->posx + (data->dirx * MOVSPEED))][(int)(data->posy)] == '0')
		data->posx += data->dirx * MOVSPEED;
	if (data->worldmap[(int)(data->posx)][(int)(data->posy + (data->diry * MOVSPEED))] == '0')
		data->posy += data->diry * MOVSPEED;
}

void	walk_backward(t_data *data)
{
	if (data->worldmap[(int)(data->posx - (data->dirx * MOVSPEED))][(int)(data->posy)] == '0')
		data->posx -= data->dirx * MOVSPEED;
	if (data->worldmap[(int)(data->posx)][(int)(data->posy - (data->diry * MOVSPEED))] == '0')
		data->posy -= data->diry * MOVSPEED;
}

void	walk_left(t_data *data)
{
	double	tempdirx;
	double	tempdiry;

	tempdirx = data->dirx;
	tempdiry = data->diry;
	
	tempdirx = data->dirx * cos(3.14/2) - data->diry * sin(3.14/2);
	tempdiry = data->dirx * sin(3.14/2) + data->diry * cos(3.14/2);
	if (data->worldmap[(int)(data->posx + (tempdirx * MOVSPEED))][(int)(data->posy)] == '0')
		data->posx += tempdirx * MOVSPEED;
	if (data->worldmap[(int)(data->posx)][(int)(data->posy + (tempdiry * MOVSPEED))] == '0')
		data->posy += tempdiry * MOVSPEED;
}

void	walk_right(t_data *data)
{
	double	tempdirx;
	double	tempdiry;

	tempdirx = data->dirx;
	tempdiry = data->diry;
	
	tempdirx = data->dirx * cos(-3.14/2) - data->diry * sin(-3.14/2);
	tempdiry = data->dirx * sin(-3.14/2) + data->diry * cos(-3.14/2);
	if (data->worldmap[(int)(data->posx + (tempdirx * MOVSPEED))][(int)(data->posy)] == '0')
		data->posx += tempdirx * MOVSPEED;
	if (data->worldmap[(int)(data->posx)][(int)(data->posy + (tempdiry * MOVSPEED))] == '0')
		data->posy += tempdiry * MOVSPEED;

}

int main_loop(t_data *data)
{
	calculate_ray_pos(data);
	return (0);
}

int	action(int keycode, t_data *data)
{
	if(keycode == ECHAP)
		close_window(data);
	if(keycode == KEY_W)
		walk_forward(data);
	if(keycode == KEY_S)
		walk_backward(data);
	if(keycode == KEY_D)
		walk_right(data);
	if(keycode == KEY_A)
		walk_left(data);
	if(keycode == KEY_RIGHT)
		rotate(data, -1);
	if(keycode == KEY_LEFT)
		rotate(data, 1);
	main_loop(data);
	return (0);
}

int	done()
{
	return (1);
}

void img_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, SCREENWIDTH, SCREENHEIGHT, "Cube3D");
	data->img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int main(int ac, char **av)
{
	t_data	data;
	char **path_tex;

	(void)av;
	if (ac != 2)
	{
		write(2, "Error\nFirst arg is missing\n", 22);
		exit(EXIT_FAILURE);
	}
    path_tex = parsing(&data, av);
	if (path_tex == 0)
		return (0);
	for(int i = 0; i < data.map_sizey; i++)
	{
		write(1, data.worldmap[i], data.map_sizex);
		write(1, "\n", 1);
	}
	img_init(&data);
	init(&data, path_tex);
	mlx_key_hook(data.mlx_win, action, &data);
	mlx_hook(data.mlx_win, 17, 0L, close_window, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
