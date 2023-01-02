/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:02:21 by tpaaso            #+#    #+#             */
/*   Updated: 2023/01/02 14:59:08 by tpaaso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct s_fractol
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					pixel_bits;
	int					line_bytes;
	int					endian;
	char				*img_buf;
	long double			x1;
	long double			y1;
	int					img_width;
	int					img_height;
	int					color_r;
	int					color_g;
	int					color_b;
	int					it_max;
	long double			zoom;
	int					fractol;
	double				mouse_x;
	double				mouse_y;
}				t_fractol;

void	calc_fractal(t_fractol *data);
void	init_fractol(t_fractol *data, char *str);
void	init_julia(t_fractol *data);
void	init_mandelbrot(t_fractol *data);
void	init_bs(t_fractol *data);
void	choose_algo(t_fractol *data, int x, int y);
void	ft_bs(t_fractol *data, int x, int y, int i);
void	ft_mandelbrot(t_fractol *data, int x, int y, int i);
void	ft_julia(t_fractol *data, int x, int y, int i);
void	ft_put_pixel(t_fractol *data, int x, int y, int i);
int		mouse(int x, int y, t_fractol *data);
int		deal_key(int key, t_fractol *data);
void	zoom_out(t_fractol *data, int x, int y);
void	zoom_in(t_fractol *data, int x, int y);
int		mouse_zoom(int key, int x, int y, t_fractol *data);
void	move_xy(int key, t_fractol *data);
void	change_fractol(int key, t_fractol *data);
void	iterate_fractol(int key, t_fractol *data);
void	change_color(int key, t_fractol *data);
void	hud(t_fractol *data);

#endif
