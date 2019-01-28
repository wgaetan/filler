/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_filler.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 18:23:14 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:27:24 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

t_filler			*get_filler(void)
{
	static t_filler	*filler = NULL;

	if (filler == NULL)
	{
		filler = gc_alloc(sizeof(t_filler), 0);
		filler->board = NULL;
		filler->piece = NULL;
		filler->heatmap = NULL;
		filler->sqrt_table = NULL;
		filler->parse_state = 0;
		filler->send_x = 0;
		filler->send_y = 0;
		filler->parse_board_line = -1;
		filler->parse_piece_line = 0;
		filler->stop = 0;
	}
	return (filler);
}
