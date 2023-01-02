/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:12:03 by tpaaso            #+#    #+#             */
/*   Updated: 2022/08/02 14:43:08 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hud(t_fractol *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		680, 0xFFFFFF, "Move: arrowkeys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		700, 0xFFFFFF, "Change iterations: -/+ and </> for larger change");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		720, 0xFFFFFF, "Change colors: R/G/B  & F to reset colors");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		740, 0xFFFFFF, "zoom: mouse1/mouse2 & wheel");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		620, 0xFFFFFF, "mandelbrot: 1");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		640, 0xFFFFFF, "julia: 2");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		660, 0xFFFFFF, "burningship: 3");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50,
		760, 0xFFFFFF, "exit: esc");
}
