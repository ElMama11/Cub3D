/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:33:14 by mverger           #+#    #+#             */
/*   Updated: 2023/01/25 17:52:02 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// char	**get_map(char **av)
// {
// 	int		map_fd;
// 	char	buffer[2];
// 	char	**map;
// 	int		i;
// 	char	*line;

// 	map_fd = open(av[1], O_RDONLY);
// 	check_open(map_fd, av);
// 	i = read(map_fd, buffer, 1);
// 	if (i <= 0)
// 		return (map = NULL);
// 	line = ft_memallocexit(100);
// 	while (i > 0)
// 	{
// 		if (i != 0)
// 			line = ft_strjoin_custom(line, buffer);
// 		i = read(map_fd, buffer, 1);
// 	}
// 	map = ft_split(line, '\n');
// 	free(line);
// 	close(map_fd);
// 	return (map);
// }

// int	check_map(char **av)
// {
// 	char	**map;
// 	int		i;

// 	i = 0;
// 	map = get_map(av);
// 	if (map == NULL)
// 	{
// 		write(2, "Error: empty map\n", 17);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (check_wall(map) == 1)
// 		i = 1;
// 	if (check_item_exit_start(map) == 1)
// 		i = 1;
// 	if (check_map_shape(map) == 1)
// 		i = 1;
// 	ft_free_tab(map);
// 	return (i);
// }

void	check_filename(int map_fd, char **av)
{
	if (map_fd == -1 || ft_strstr(av[1], ".cub") != 1)
	{
		write(2, "Error: bad path or entry format\n", 32);
		exit(EXIT_FAILURE);
	}
}

char *skip_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	**free_tab_tex(char **str)
{
	if (str)
	{
		if (str[0])
			free(str[0]);
		if (str[1])
			free(str[1]);
		if (str[2])
			free(str[2]);
		if (str[3])
			free(str[3]);
	}
	return (NULL);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}



int	get_ceilor_floor_color(char *buf, t_data *data, char c)
{
	int	r;
	int	g;
	int	b;

	buf = skip_space(buf);
	if (ft_isdigit(*buf))
	{
		r = ft_atoi(buf);
	}
	else
		return (0);
	while (ft_isdigit(*buf))
		buf++;
	if (!(*buf == ','))
		return (0);
	buf++;
	if (ft_isdigit(*buf))
	{
		g = ft_atoi(buf);
	}
	else
		return (0);
	while (ft_isdigit(*buf))
		buf++;
	if (!(*buf == ','))
		return (0);
	buf++;
	if (ft_isdigit(*buf))
	{
		b = ft_atoi(buf);
	}
	else
		return (0);
	while (ft_isdigit(*buf))
		buf++;
	if (c == 'F')
		data->floor = create_trgb(0, r, g, b);
	if (c == 'C')
		data->ceiling = create_trgb(0, r, g, b);
	return (1);
}

char	*ft_strdup_custom(const char *s)
{
	int		i;
	int		i2;
	char	*dest;

	i = 0;
	i2 = ft_strlen(s);
	if (!(dest = (char*)malloc(sizeof(*dest) * i2 + 1)))
		return (NULL);
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	**get_path_name(char *buffer, char **path_tex, int tex_num)
{
	buffer = skip_space(buffer);
	if (!ft_strncmp(buffer, "./", 2))
	{
		if (path_tex[tex_num])
			return (free_tab_tex(path_tex));
		path_tex[tex_num] = ft_strdup_custom(buffer + 2);				
	}
	return(path_tex);
}

char **check_name_color(t_data *data, char *buffer, char **path_tex)
{
	if (!ft_strncmp(buffer, "NO ", 3))
		path_tex = get_path_name(buffer + 3, path_tex, 0);
	if (!ft_strncmp(buffer, "SO ", 3))
		path_tex = get_path_name(buffer + 3, path_tex, 1);
	if (!ft_strncmp(buffer, "WE ", 3))
		path_tex = get_path_name(buffer + 3, path_tex, 2);
	if (!ft_strncmp(buffer, "EA ", 3))
		path_tex = get_path_name(buffer + 3, path_tex, 3);
	if (!ft_strncmp(buffer, "F ", 2) || !ft_strncmp(buffer, "C ", 2))
	{
		if (!get_ceilor_floor_color(buffer + 2, data, *buffer))
			return (free_tab_tex(path_tex));
	}
	// else
	// {
		
	// }
	return (path_tex);	
}

char **get_path_tex_color(t_data *data, char *buffer, char **path_tex)
{
	int	i;
	
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (path_tex);
		else if (buffer[i] == ' ')
			i++;
		else
		{
			
			path_tex = check_name_color(data, buffer + i, path_tex);
			if (path_tex == 0)
				return (NULL);
			else
				return (path_tex);
		}
	}	
	return (path_tex);

}

char **parsing(t_data *data, int ac, char **av)
{
	int		mapfd;
	char	*buffer;                 
	char	**path_tex;

	mapfd = open(av[1], O_RDONLY);
	buffer = get_next_line(mapfd);
	check_filename(mapfd, av);
	path_tex = ft_calloc(sizeof(char *), 4);
	if (path_tex == 0)
		return (0);
	while (buffer != 0)
	{	
		path_tex = get_path_tex_color(data, buffer, path_tex);
		if (path_tex == 0)
		{
			if (!buffer)
				free(buffer);			
			return (NULL);
		}
		if (!buffer)
			free(buffer);
		buffer = get_next_line(mapfd);
	}
	if (!buffer)
		free(buffer);
	return (path_tex);
}