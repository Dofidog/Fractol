/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:46:49 by tpaaso            #+#    #+#             */
/*   Updated: 2022/08/02 14:41:25 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractol *data)
{
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->fractol = 0;
	data->it_max = 100;
	data->zoom = 150;
	data->x1 = -2;
	data->y1 = -2;
	calc_fractal(data);
}

void	init_mandelbrot(t_fractol *data)
{
	data->it_max = 100;
	data->zoom = 150;
	data->x1 = -2;
	data->y1 = -2;
	data->fractol = 1;
	calc_fractal(data);
}

void	init_bs(t_fractol *data)
{
	data->it_max = 100;
	data->zoom = 150;
	data->x1 = -2;
	data->y1 = -2;
	data->fractol = 2;
	calc_fractal(data);
}

void	init_fractol(t_fractol *data, char *str)
{
	data->mlx_ptr = mlx_init();
	data->img_width = 600;
	data->img_height = 800;
	data->color_b = 0x30;
	data->color_g = 0x20;
	data->color_r = 0x50;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->img_width, data->img_height, "fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr,
			data->img_width, data->img_height);
	data->img_buf = mlx_get_data_addr(data->img_ptr, &data->pixel_bits,
			&data->line_bytes, &data->endian);
	if ((ft_strcmp("burningship", str) != 0)
		&& (ft_strcmp("mandelbrot", str) != 0)
		&& (ft_strcmp("julia", str) != 0))
		ft_exit("usage: ./fractol mandelbrot/julia/burningship");
	if (ft_strcmp("julia", str) == 0)
		init_julia(data);
	if (ft_strcmp("mandelbrot", str) == 0)
		init_mandelbrot(data);
	if (ft_strcmp("burningship", str) == 0)
		init_bs(data);
}
