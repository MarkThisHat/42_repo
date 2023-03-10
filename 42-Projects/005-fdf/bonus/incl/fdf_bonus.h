/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:39:59 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/10 16:40:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../../libs/libft/incl/libft.h"
# include "/usr/local/include/mlx.h"
# include <fcntl.h>
# include <math.h>

# define ARW_U_K 65362
# define ARW_D_K 65364
# define ARW_L_K 65361
# define ARW_R_K 65363
# define BCKSPC 65288
# define P_KEY 112
# define G_KEY 103
# define B_KEY 98
# define U_KEY 117
# define J_KEY 106
# define I_KEY 105
# define K_KEY 107
# define O_KEY 111
# define L_KEY 108
# define R_KEY 114
# define Z_KEY 122
# define X_KEY 120
# define Q_KEY 113
# define W_KEY 119
# define E_KEY 101
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define N_PLU_K 65453
# define N_MIN_K 65451

void	reset_placement(t_mlxs *ms, int change);
int		adjust_ambit(t_mlxs *ms, int height, int width);
void	change_height(t_mlxs *ms, int change);
void	bonus_roll(t_mlxs *ms, int axis, double amount);
void	bonus_scale(t_mlxs *ms, int negative);
void	fad_toggle(t_mlxs *ms);
void	redraw_map(t_mlxs *ms);
void	top_menu(t_mlxs *ms);
void	bottom_menu(t_mlxs *ms);
void	cone_menu(t_mlxs *ms);
int		key_rotation(int keycode, t_mlxs *ms);
int		key_shift(t_mlxs *ms, int keycode);
int		key_anchor(t_mlxs *ms, int keycode);
void	project_cone(t_mlxs *ms, double cx, double cy, double cz);
int		mouse_group(int keycode, int x, int y, t_mlxs *ms);

#endif
