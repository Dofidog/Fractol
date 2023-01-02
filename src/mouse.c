/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:45:06 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 14:45:44 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int x, int y, t_fractol *data)
{
	if (data->fractol == 0)
	{
		data->mouse_x = x / data->zoom + data->x1;
		data->mouse_y = y / data->zoom + data->y1;
		calc_fractal(data);
	}
	return (0);
}

void	zoom_in(t_fractol *data, int x, int y)
{
	double	scale;

	scale = data->zoom * 1.3;
	data->x1 = ((double)x / data->zoom + data->x1) - (scale / 2);
	data->x1 += (scale / 2) - ((double)x / scale);
	data->y1 = ((double)y / data->zoom + data->x1) - (scale / 2);
	data->y1 += (scale / 2) - ((double)y / scale);
	data->zoom *= 1.3;
	data->it_max += 2;
}

void	zoom_out(t_fractol *data, int x, int y)
{
	double	scale;

	if (data->it_max <= 0)
		return ;
	scale = data->zoom * 0.8;
	data->x1 = ((double)x / data->zoom + data->x1) - (scale / 2);
	data->x1 += (scale / 2) - ((double)x / scale);
	data->y1 = ((double)y / data->zoom + data->x1) - (scale / 2);
	data->y1 += (scale / 2) - ((double)y / scale);
	data->zoom *= 0.8;
	data->it_max -= 2;
}

int	mouse_zoom(int key, int x, int y, t_fractol *data)
{
	if (key == 1 || key == 4)
		zoom_in(data, x, y);
	if (key == 2 || key == 5)
		zoom_out(data, x, y);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	calc_fractal(data);
	return (1);
}
