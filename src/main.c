/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:41:53 by jthibaul          #+#    #+#             */
/*   Updated: 2023/01/18 09:22:13 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cube.h"
int worldmap[MAPWIDTH][MAPHEIGHT]=
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
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str_malloc;

	i = 0;
	while (s1[i])
		i++;
	str_malloc = (char *) malloc((i + 1) * sizeof(char));
	if (str_malloc == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_malloc[i] = s1[i];
		i++;
	}
	str_malloc[i] = '\0';
	return (str_malloc);
}

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






void	hud_debug(t_data *data)
{
	char *x = ft_itoa(data->posx);
	char *y = ft_itoa(data->posy);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0x00fffff, "posx:");
	// printf("posx:%f\n", data->posx);
	mlx_string_put(data->mlx, data->mlx_win, 80, 10, 0x00fffff, x);
	mlx_string_put(data->mlx, data->mlx_win, 10, 30, 0x00fffff, "posy:");
	//printf("posy:%f\n", data->posy);
	mlx_string_put(data->mlx, data->mlx_win, 80, 30, 0x00fffff, y);
}

void	free_all(t_data *data)
{
	(void)data;
}

void	close_window(t_data *data)
{
	free_all(data);
	exit(0);
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
	while (y < SCREENHEIGHT)
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

	h = SCREENHEIGHT;
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

	w = SCREENWIDTH;
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
	hud_debug(data);

}

void	walk(t_data *data, int x, int y)
{
	// printf("OK0\n");
	// sleep(2);
	// printf("mlx:%p\n", data->mlx);
	// printf("new posx:%f\n", (data->posx + (data->dirx * x * MOVSPEED)));
	if (worldmap[(int)(data->posx + (data->dirx * x * MOVSPEED))][(int)(data->posy)] == 0)
	{
		printf("OK0.5\n");
		data->posx += data->dirx * MOVSPEED * x;
	}
	printf("OK1\n");
	if (worldmap[(int)(data->posx)][(int)(data->posy + (data->diry * y * MOVSPEED))] == 0) //Teamedfunsc3&
	{
		printf("OK1.5\n");
		data->posy += data->diry * MOVSPEED * y;
	}
	printf("OK2\n");
}

int main_loop(t_data *data)
{
	calculate_ray_pos(data);
	return (0);
}

int	action(int keycode, t_data *data)
{	
	printf("OK150 %d posx=%f\n", keycode, data->posx);
	if(keycode == ECHAP)
		close_window(data);
	if(keycode == KEY_W)
		walk(data, 1, 0);
	if(keycode == KEY_S)
		walk(data, -1, 0);
	if(keycode == KEY_D)
		walk(data, 0, -1);
	if(keycode == KEY_A)
		walk(data, 0 , 1);
	// if(keycode == KEY_RIGHT)
	// 	look(data, 1);
	// if(keycode == KEY_LEFT)
	// 	look(data, -1);
	main_loop(data);
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

int main()
{
	t_data	data;

	init(&data);
	img_init(&data);
	mlx_key_hook(data.mlx_win, action, &data);
	printf("mlx:%p\n", data.mlx);
	calculate_ray_pos(&data);
	// mlx_loop_hook(data.mlx, main_loop, &data);
	// int	i = 0;
	// while (i < 50)
	// {
	// 	sleep(1);
	// 	walk(&data, 1, 0);
	// 	calculate_ray_pos(&data);
	// 	i++;
	// }
	printf("posx:%f\n", data.posx);
	mlx_loop(data.mlx);
}
