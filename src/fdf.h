/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:39:49 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 17:39:25 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "mlx.h"
# include "key_def.h"

# define INT_MAX 		2147483647
# define INT_MIN 		-2147483648
# define HEIGHT			1080
# define WIDTH			1980
# define WHITE			"0xFFFFFF"
# define COLOR_WHITE	0xFFFFFF

typedef enum s_projection
{
	ISO,
	TOP
}	t_projection;

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
}						t_map;

typedef struct s_camera
{
	t_projection		projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map_info;
	t_camera	*camera;
	t_mouse		*mouse;
}				t_data;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

void			read_map(char **argv, t_map *map_info);
t_map			*ini_map(void);
int				close_window(int keycode, t_data *img);
int				close_window_x(t_data *img);
void			draw_image(t_map *map_info, t_data *img);
int				ft_abs(int x);
int				get_index(int x, int y, int width);
t_data			*img_init(t_map *map_info);
t_camera		*camera_init(t_data *img);
t_point			scale(t_point p, t_data *img);
int				key_press(int key, void *param);
void			move(int key, t_data *img);
void			controls(t_data *img);
int				get_height(char **line);
int				ft_atoi_base(const char *str, int base);
int				close_window_x(t_data *img);
void			read_colors(int fd, t_map *map_info);
int				get_color(t_point current, t_point start, \
								t_point end, t_point delta);
void			free_strsplit_arr(char **arr);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
int				ft_sign(int f, int s);
void			rotate(int key, t_data *img);
void			flatten(int key, t_data *img);
void			error_exit(char *str, t_data *img);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			draw_line(t_point start, t_point end, t_data *img);
void			free_all(t_data *img);
void			error_exit_map_info(char *str, t_map *map_info);
int				check_format(t_map *map_info, int x, char **line_coords);
int				ft_is_number(char *s);
void			rotate(int key, t_data *img);
int				mouse_move(int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_press(int button, int x, int y, void *param);
void			zoom(int key, t_data *img);
void			rotate_x(int *y, int *z, double alpha);
void			rotate_y(int *x, int *z, double beta);
void			rotate_z(int *x, int *y, double gamma);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			draw_thick_line(t_point start, t_point end, \
								int thickness, t_data *img);
void			draw_border(t_data *img);
void			print_instructions(t_data *img);

#endif
