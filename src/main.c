/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:18:38 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 14:59:02 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_pixel(t_fractol *data, int x, int y, int i)
{
	if (x < data->img_width && y < data->img_height && i == data->it_max)
	{
		data->img_buf[(x * 4) + (y * data->line_bytes)] = 0x00;
		data->img_buf[(x * 4) + (y * data->line_bytes) + 1] = 0x00;
		data->img_buf[(x * 4) + (y * data->line_bytes) + 2] = 0x00;
	}
	else if (x < data->img_width && y < data->img_height)
	{
		data->img_buf[(x * 4) + (y * data->line_bytes)]
			= data->color_b + (i * 2);
		data->img_buf[(x * 4) + (y * data->line_bytes) + 1]
			= data->color_g + (i * 3);
		data->img_buf[(x * 4) + (y * data->line_bytes) + 2]
			= data->color_r + (i * 4);
	}
}

void	choose_algo(t_fractol *data, int x, int y)
{
	if (data->fractol == 0)
		ft_julia(data, x, y, 0);
	if (data->fractol == 1)
		ft_mandelbrot(data, x, y, 0);
	if (data->fractol == 2)
		ft_bs(data, x, y, 0);
}

void	calc_fractal(t_fractol *data)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < data->img_width)
		{
			choose_algo(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	hud(data);
}

int	main(int av, char **argc)
{
	t_fractol	data;

	if (av != 2)
		ft_exit("usage: ./fractol mandelbrot/julia/burningship");
	init_fractol(&data, argc[1]);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_mouse_hook(data.win_ptr, mouse_zoom, &data);
	mlx_hook(data.win_ptr, 6, 1L >> 6, mouse, &data);
	mlx_loop(data.mlx_ptr);
	free(&data);
	return (0);
}
