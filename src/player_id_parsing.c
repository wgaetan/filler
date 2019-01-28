/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player_id_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 21:37:11 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 13:34:40 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void			get_player_id(char *line)
{
	t_filler	*filler;

	filler = get_filler();
	if (ft_strlen(line) < 11 || ft_strncmp(line, "$$$ exec p", 10) != 0)
		gc_exit(-1);
	if (line[10] == '1')
	{
		filler->token[0] = TOKEN_1;
		filler->token[1] = TOKEN_1_NEW;
		filler->token[2] = TOKEN_2;
		filler->token[3] = TOKEN_2_NEW;
	}
	else if (line[10] == '2')
	{
		filler->token[0] = TOKEN_2;
		filler->token[1] = TOKEN_2_NEW;
		filler->token[2] = TOKEN_1;
		filler->token[3] = TOKEN_1_NEW;
	}
	else
		gc_exit(-1);
	filler->parse_state = 1;
}
