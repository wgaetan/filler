/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_placeable.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 15:30:49 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 22:23:02 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int		is_placeable(t_filler *filler, int x, int y)
{
	int			in_common;
	int			i;
	int			j;

	i = -1;
	in_common = 0;
	if ((x + filler->p_height) > filler->b_height ||
			(y + filler->p_width) > filler->b_width)
		in_common += 10;
	while (++i < filler->p_height && in_common <= 1)
	{
		j = -1;
		while (++j < filler->p_width && in_common <= 1)
		{
			if (filler->piece[i][j] == PIECE_CHAR)
			{
				if (filler->board[i + x][j + y] == filler->token[0] ||
						filler->board[i + x][j + y] == filler->token[1])
					in_common++;
				else if (filler->board[i + x][j + y] != '.')
					in_common += 10;
			}
		}
	}
	return (in_common == 1 ? 1 : 0);
}
