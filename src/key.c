/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:44:54 by tpaaso            #+#    #+#             */
/*   Updated: 2022/08/02 14:38:41 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	deal_key(int key, t_fractol *data)
{
	if (key == 53)
		exit(-1);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		move_xy(key, data);
	if (key == 18 || key == 19 || key == 20)
		change_fractol(key, data);
	if (key == 43 || key == 47 || key == 27 || key == 24)
		iterate_fractol(key, data);
	if (key == 15 || key == 5 || key == 11 || key == 3)
		change_color(key, data);
	calc_fractal(data);
	return (0);
}

void	change_color(int key, t_fractol *data)
{
	if (key == 15)
		data->color_r *= 2;
	if (key == 5)
		data->color_g *= 2;
	if (key == 11)
		data->color_b *= 2;
	if (key == 3)
	{
		data->color_b = 0x30;
		data->color_g = 0x20;
		data->color_r = 0x50;
	}
}

void	iterate_fractol(int key, t_fractol *data)
{
	if (key == 43)
		data->it_max -= 10;
	if (key == 47)
		data->it_max += 10;
	if (key == 27)
		data->it_max -= 1;
	if (key == 24)
		data->it_max += 1;
	if (data->it_max <= 0)
		data->it_max = 1;
}

void	change_fractol(int key, t_fractol *data)
{
	if (key == 18)
		init_mandelbrot(data);
	if (key == 19)
		init_julia(data);
	if (key == 20)
		init_bs(data);
}

void	move_xy(int key, t_fractol *data)
{
	if (key == 126)
		data->y1 -= 0.1;
	if (key == 125)
		data->y1 += 0.1;
	if (key == 123)
		data->x1 -= 0.1;
	if (key == 124)
		data->x1 += 0.1;
}
