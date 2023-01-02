/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:48:02 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 14:57:11 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_fractol *data, int x, int y, int i)
{
	double		tmp;
	long double	x1;
	long double	y1;

	x1 = x / data->zoom + data->x1;
	y1 = y / data->zoom + data->y1;
	while ((x1 * x1 + y1 * y1) < 4 && i < data->it_max)
	{
		tmp = (x1 * x1) - (y1 * y1) + data->mouse_x;
		y1 = 2 * x1 * y1 + data->mouse_y;
		x1 = tmp;
		i++;
	}
	ft_put_pixel(data, x, y, i);
}

void	ft_mandelbrot(t_fractol *data, int x, int y, int i)
{
	double			tmp;
	long double		x1;
	long double		y1;
	long double		x2;
	long double		y2;

	x1 = 0;
	y1 = 0;
	x2 = x / data->zoom + data->x1;
	y2 = y / data->zoom + data->y1;
	while ((x1 * x1 + y1 * y1 < 4) && (i < data->it_max))
	{
		tmp = x1 * x1 - y1 * y1 + x2;
		y1 = 2 * x1 * y1 + y2;
		x1 = tmp;
		i++;
	}
	ft_put_pixel(data, x, y, i);
}

void	ft_bs(t_fractol *data, int x, int y, int i)
{
	double			tmp;
	long double		x1;
	long double		y1;
	long double		x2;
	long double		y2;

	x1 = 0;
	y1 = 0;
	x2 = x / data->zoom + data->x1;
	y2 = y / data->zoom + data->y1;
	while ((x1 * x1 + y1 * y1 < 4) && (i < data->it_max))
	{
		tmp = x1 * x1 - y1 * y1 + x2;
		y1 = fabsl(2 * x1 * y1 + y2);
		x1 = fabsl(tmp);
		i++;
	}
	ft_put_pixel(data, x, y, i);
}
