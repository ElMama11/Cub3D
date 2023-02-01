#include "cube.h"

int	check_space(t_data *data, char **worldmap, int y, int x)
{
	int	i;

	i = 0;
	if (y == data->map_sizey || x == data->map_sizex || y == 0 || x == 0) // if crash see here first
		return (1);
	while (y + i < data->map_sizey && worldmap[y + i][x] == ' ')
	{
		if (y + i == data->map_sizey - 1)
			return (1);
		i++;
	}
	i = 0;
	while (y - i < data->map_sizey && worldmap[y - i][x] == ' ')
	{
		if (y - i == 0)
			return (1);
		i++;
	}
	i = 0;
	while (x + i < data->map_sizex && worldmap[y][x + i] == ' ')
	{
		if (x + i == data->map_sizex - 1)
			return (1);
		i++;
	}
	i = 0;
	while (x - i < data->map_sizex && worldmap[y][x - i] == ' ')
	{
		if (x - i == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_wall(t_data *data, char **worldmap, int y, int x)
{
	if ((y - 1 >= 0) && (worldmap[y - 1][x] == '1' || worldmap[y - 1][x] == '0'))
		return (1);
	if (y + 1 < data->map_sizey && (worldmap[y + 1][x] == '1' || worldmap[y + 1][x] == '0'))
		return (1);
	if (x - 1 >= 0 && (worldmap[y][x - 1] == '1' || worldmap[y][x - 1] == '0'))
		return (1);
	if (x + 1 < data->map_sizex && (worldmap[y][x + 1] == '1' || worldmap[y][x + 1] == '0'))
		return (1);
	return (0);
}

int	is_floor_wall_direction(char c)
{
	if (c == '1' || c == '0' || is_direction(c))
		return (1);
	return (0);
}

int	check_floor(t_data *data, char **worldmap, int y, int x)
{
	if (y == data->map_sizey || x == data->map_sizex || y == 0 || x == 0)
		return (0);
	if (!is_floor_wall_direction(worldmap[y + 1][x]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y + 1][x + 1]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y  + 1][x - 1]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y - 1][x]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y - 1][x + 1]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y - 1][x - 1]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y][x + 1]))
		return (0);
	if (!is_floor_wall_direction(worldmap[y][x - 1]))
		return (0);
	return (1);
}

int	is_floor_wall(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

void	init_direction(t_data *data, char c)
{



	if (c == 'N')
	{
		data->dirx = -1;
		data->diry = 0;
		data->planex = 0;
		data->planey = 0.66;
	}
	else if (c == 'S')
	{
		data->dirx = 1;
		data->diry = 0;
		data->planex = 0;
		data->planey =  -0.66;
	}
	else if (c == 'E')
	{
		data->dirx = 0;
		data->diry = 1;
		data->planex =  0.66;
		data->planey =  0;
	}
	else if (c == 'W')
	{
		data->dirx = 0;
		data->diry = -1;
		data->planex =  -0.6;
		data->planey =  0;
	}
}

int	check_direction(t_data *data, char **worldmap, int y, int x)
{
	if (data->posx != 0 || data->posy != 0)
		return (0);
	if (y == data->map_sizey || x == data->map_sizex || y == 0 || x == 0)
		return (0);
	if (!is_floor_wall(worldmap[y + 1][x]))
		return (0);
	if (!is_floor_wall(worldmap[y + 1][x + 1]))
		return (0);
	if (!is_floor_wall(worldmap[y  + 1][x - 1]))
		return (0);
	if (!is_floor_wall(worldmap[y - 1][x]))
		return (0);
	if (!is_floor_wall(worldmap[y - 1][x + 1]))
		return (0);
	if (!is_floor_wall(worldmap[y - 1][x - 1]))
		return (0);
	if (!is_floor_wall(worldmap[y][x + 1]))
		return (0);
	if (!is_floor_wall(worldmap[y][x - 1]))
		return (0);
	data->posx = y + 0.5;
	data->posy = x + 0.5;
	init_direction(data, worldmap[y][x]);
	worldmap[y][x] = '0';
	return (1);
}

int	check_map_square(t_data *data, char **worldmap, int y, int x)
{
	if (!(worldmap[y][x] == ' ' || is_floor_wall_direction(worldmap[y][x])))
		return (0);
	if (worldmap[y][x] == ' ')
	{
		if (!check_space(data, worldmap, y, x))
			return (0);
	}
	else if (worldmap[y][x] == '1')
	{
		if (!check_wall(data, worldmap, y, x))
			return (0);
	}
	else if (worldmap[y][x] == '0')
	{
		if (!check_floor(data, worldmap, y, x))
			return (0);
	}
	else if (is_direction(worldmap[y][x]))
	{
		if (!check_direction(data, worldmap, y, x))
			return (0);

	}
	else
		return (0);
	return (1);
}

int check_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	data->posx = 0;
	data->posy = 0;
	while (y < data->map_sizey)
	{
		while (x < data->map_sizex)
		{
			if (!check_map_square(data, data->worldmap, y, x))
			{
				printf("Error\nInvalid map\n");
				return (0);
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (data->posx == 0)
	{
		printf("Error\nInvalid map no start position\n");
		return (0);
	}
	return (1);
}