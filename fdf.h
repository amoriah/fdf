/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:34:06 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 16:38:43 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

//Error
# define ERR		"Error"
//# define MALLOC	(x == NULL)

# define WIDTH			1000
# define HEIGHT			800

//keys
# define ESC			53
# define ENT			36
# define P_KEY			35
# define I_KEY			34
# define DOWN			125
# define S_KEY			1
# define UP				126
# define W_KEY			13
# define LEFT			123
# define A_KEY			0
# define RIGHT			124
# define D_KEY			2
# define MINUS			78
# define PLUS			69
# define KEYPRESS		2
# define FIGURE_UP		116
# define FIGURE_DOWN	121

//Colors
//-----earth_color--------------
# define SNOW			0xE8E6E1
# define ROCKS			0x2E2B27
# define KHAKI			0x367A57
# define DIRTY_GREEN	0x1E4F36
# define DIRTY_YELLOW	0x92AD40
# define DARK_BLUE		0x444CC6
# define DARK_BLUE2		0x2A2EAE
# define GRAY_BLUE		0x3D497C
# define VERY_DARK_BLUE	0x05093d
//-------blue_pink--------------
# define YELLOW			0xffff66
# define YELLOW1		0xffcc66
# define YELLOW2		0xff9966
# define YELLOW3		0x94e0f0
# define PINK			0xff7366
# define PINK1			0xff5966
# define PINK2			0xff3366
# define BLUE			0x9952a3
# define BLUE1			0x667ac2
# define BLUE2			0x19b8f0
# define BLUE3			0x00ccff
# define GREEN			0x33cccc

typedef struct s_position
{
	float		x;
	float		y;
	int			z;
	int			z1;
}			t_position;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	char	*pix_arr;
	int		width;
	int		height;
	int		**z_matrix;
	int		color;
	int		shift_x;
	int		shift_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		proj_flag;
	int		zoom_flag;
	double	zoom;
	double	figure_height;
}			t_fdf;

//main.c
void			my_mlx_pixel_put(t_fdf *data, int x, int y, int color);

//checks.c
void			ft_error(char *str);
void			check_alloc(int **a);
void			check_fd(int i);
void			check_struct(t_fdf *data);

//read_file.c
void			read_file(char *file_name, t_fdf *data);
void			malloc_matrix(t_fdf *data);
void			fill_metrix(t_fdf *data, int *z_line, char *line);
int				get_width(char *file_name);
int				get_height(char *file_name);

//free_memory.c
void			delete_leaks(char **line, int len);
void			free_map(int **array);

//draw.c
void			draw(t_fdf *data);
void			bresenham(t_position pos, float x1, float y1, t_fdf *data);
void			count_step_and_pixel_put(t_fdf *data, t_position pos,
					float x1, float y1);

//position.c
void			look_for_position(t_fdf **data, t_position *pos,
					float *x1, float *y1);
int				choose_position(t_fdf **data);
void			get_position(t_position *pos, float *x1, float *y1, int pos_x);
void			get_zoom(t_fdf **data, t_position *pos, float *x1, float *y1);

//color.c
unsigned int	get_color(t_fdf *data, t_position pos);
unsigned int	blue_pink(int h);
unsigned int	earth_color(int h);

//utils.c
float			ft_mod(float a);
float			ft_max(float a, float b);

//projections.c
void			isometric(float *x, float *y, int z);
void			parallel(float *x, float *y, int *z);
void			projection(t_fdf *data, float *x, float *y, int *z);

//key_hook.c
int				esc_key(t_fdf *data);
int				deal_key(int key, t_fdf *data);
void			clear_screen_sh(void);
void			hooks(t_fdf *data);

#endif