/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_best_answer.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 17:50:36 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 22:37:14 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void			find_best_answer(void)
{
	t_filler	*filler;
	int			i;
	int			j;

	filler = get_filler();
	i = 0;
	while (i < filler->b_height)
	{
		j = 0;
		while (j < filler->b_width)
		{
			if (filler->heatmap[i][j] > 0 && filler->heatmap[i][j] >=
					filler->heatmap[filler->send_x][filler->send_y])
			{
				filler->send_x = i;
				filler->send_y = j;
			}
			j++;
		}
		i++;
	}
}
