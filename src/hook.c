/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:58:34 by jthibaul          #+#    #+#             */
/*   Updated: 2023/01/17 08:44:33 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	close_window(t_data *data)
{
	free_all(data);
	exit(0);
}

void	hook(int keycode, t_data *data)
{
	if(keycode == ECHAP)	
		close_window(data);
	if(keycode == KEY_W)
		walp_up(data);
	if(keycode == KEY_S)
		walk_down(data);
	if(keycode == KEY_D)
		walk_right(data);
	if(keycode == KEY_A)
		walk_left(data);
	if(keycode == KEY_RIGHT)
		look_right(data);
	if(keycode == KEY_LEFT)
		look_left(data);
}

void set_hook(t_data *data)
{
	
	mlx_key_hook(data->mlx_win, hook, data);
	// mlx_hook(data->mlx_win, 17, 0L, close_window, data);	// RED_CROSS / DESTROY / MAC
}