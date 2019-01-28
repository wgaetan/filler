/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 18:04:02 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:50:30 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include "../libft/includes/libft.h"

/*
** Parse states:
** 0 - get player Id
** 1 - get board dimensions
** 2 - get board data
** 3 - get piece dimensions
** 4 - get piece data
** 5 - parsing end
*/

# define TOKEN_1 'O'
# define TOKEN_1_NEW 'o'
# define TOKEN_2 'X'
# define TOKEN_2_NEW 'x'
# define PIECE_CHAR '*'

typedef struct	s_filler
{
	char		**board;
	char		**piece;
	int			**heatmap;
	float		*sqrt_table;
	int			parse_state;
	int			parse_board_line;
	int			parse_piece_line;
	int			b_width;
	int			b_height;
	int			p_width;
	int			p_height;
	int			send_x;
	int			send_y;
	int			stop;
	char		token[4];
}				t_filler;

t_filler		*get_filler(void);

void			get_data(void);
void			get_player_id(char *line);
void			get_board_dim(char *line);
void			get_board_data(char *line);
void			get_piece_dim(char *line);
void			get_piece_data(char *line);
void			think(void);
void			find_best_answer(void);
void			send_answer(void);

float			fast_sqrt(float n);
float			score(int i, int j, int x_diff, int y_diff);
int				is_placeable(t_filler *filler, int x, int y);

#endif
