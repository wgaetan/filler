/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_data.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 18:10:01 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:42:21 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		limit_move(void)
{
	t_filler	*filler;
	int			i;
	int			j;
	int			found;

	filler = get_filler();
	i = 0;
	found = 0;
	while (i < filler->b_height && found == 0)
	{
		j = 0;
		while (j < filler->b_width && found == 0)
		{
			if (filler->board[i][j] == filler->token[3])
				found++;
			j++;
		}
		i++;
	}
	if (found == 0 && filler->stop == 0)
		filler->stop = 1;
}

static void		dispatch_line(char *line)
{
	t_filler	*filler;

	filler = get_filler();
	if (filler->parse_state == 0)
		get_player_id(line);
	else if (filler->parse_state == 1)
		get_board_dim(line);
	else if (filler->parse_state == 2)
		get_board_data(line);
	else if (filler->parse_state == 3)
		get_piece_dim(line);
	else if (filler->parse_state == 4)
		get_piece_data(line);
}

void			get_data(void)
{
	t_filler	*filler;
	char		*line;

	filler = get_filler();
	if (filler->piece != NULL)
	{
		gc_free(NULL, 2);
		filler->piece = NULL;
	}
	while (filler->parse_state < 5)
	{
		if (get_next_line(0, &line) && ft_strlen(line) > 0)
			dispatch_line(line);
		gc_free(line, 0);
	}
	limit_move();
	filler->parse_state = 1;
	filler->parse_board_line = -1;
	filler->parse_piece_line = 0;
}
