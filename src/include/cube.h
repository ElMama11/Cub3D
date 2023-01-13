/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:05:30 by mverger           #+#    #+#             */
/*   Updated: 2023/01/13 15:40:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>

# define screenWidth 800
# define screenHeight 600

#define mapWidth 24
#define mapHeight 24

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


#endif
