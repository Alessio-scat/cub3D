/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascatama <ascatama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:46:54 by ascatama          #+#    #+#             */
/*   Updated: 2023/06/28 10:09:45 by ascatama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 119
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 97

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		gun;
	int		height;
	int		width;
}					t_data;

typedef struct s_texture
{
	uint32_t		rgb_f;
	uint32_t		rgb_c;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				i_no;
	int				i_so;
	int				i_we;
	int				i_ea;
	int				i_f;
	int				i_c;
}				t_texture;

typedef struct s_cub
{
	char		*l;
	char		*tmp;
	char		*gnl;
	char		**map;
	int			count;
	char		*lmap;
	int			i;
	t_texture	t;
}				t_cub;

typedef struct s_ray
{
	char		player;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
	double		wallx;
	double		step;
	double		texpos;
	int			texx;
	int			texy;
	int			text_num;
	t_data		data;
	t_data		texture[4];
	t_data		gun[2];
	t_cub		*cub;
}					t_ray;

int		parsing(char *av[], t_cub *cub);
void	ft_free_all(t_cub *cub);
void	ft_free(t_cub *cub, char *l, char *test1, int fd);
void	free_2d(char **s);
int		create_window(t_ray *ray);
int		move(int keycode, t_ray *ray);
int		close_win(t_ray *ray);
void	draw_mini_map(int i, int j, int color, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	raycasting_init(t_ray *ray);
int		reset_move(int keycode, t_ray *ray);
void	minimap(t_ray *ray);
void	move_w_s(t_ray *ray);
void	move_a_d(t_ray *ray);
void	rotate_right_left(t_ray *ray);
void	gun(t_ray *ray);
int		is_wall(t_data *data, int x, int y);
int		get_texture(t_ray *ray);
int		put_texture(t_ray *ray, int x);
void	print_gun(t_ray *ray);
int		mouse_move(int x, int y, t_ray *ray);
void	init_direction_player(t_ray *ray);
int		refresh(t_ray *ray);
int		ft_raycasting(t_ray *ray);
void	move_print(t_ray *ray);
void	ft_free_esc(t_ray *ray);

#endif