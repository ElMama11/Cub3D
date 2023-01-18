/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:05:30 by mverger           #+#    #+#             */
/*   Updated: 2023/01/17 16:13:31 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
 
# define SCREENWIDTH 800
# define SCREENHEIGHT 600

#define MAPWIDTH 24
#define MAPHEIGHT 24

# define MOVSPEED 1
# define ROTSPEED 0.2

/* KEY */
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 122
# define KEY_S 115
# define KEY_D 100
# define KEY_A 113
# define ECHAP 1

// Teamedfunsc3&

// # ifndef MAP
// #  define MAP
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
// # endif
typedef struct s_data
{
	double	posx; //x and y start position
	double	posy;
	double	dirx; //initial direction vector
	double	diry;
	double	planex; //the 2d raycaster version of camera plane
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	
	double	time; //time of current frame
	double	oldtime; //time of previous frame

	int		mapx; //which box of the map we're in
	int		mapy;
	double	sidedistx; //length of ray from current position to next x or y-side
	double	sidedisty;
	double	deltadistx; //length of ray from one x or y-side to next x or y-side
	double	deltadisty;
	double	perpwalldist;
	int		stepx; //what direction to step in x or y-direction (either +1 or -1)
	int		stepy;
	int		hit; //was there a wall hit?
	int		side; //was a NS or a EW wall hit?
	
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}			t_data;

void	init(t_data *data);
void	free_all(t_data *data);
/* hook.c */
int		action(int keycode, t_data *data);
void	set_hook(t_data *data);
#endif
