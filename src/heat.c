/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 16:34:05 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:14:37 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		init_thinker(void)
{
	t_filler	*filler;
	int			i;
	int			sqrt_count;

	filler = get_filler();
	i = 0;
	filler->heatmap = gc_alloc(sizeof(int *) * filler->b_height, 3);
	while (i < filler->b_height)
		filler->heatmap[i++] = gc_alloc(sizeof(int) * filler->b_width, 0);
	i = -1;
	sqrt_count = filler->b_height + filler->b_width;
	filler->sqrt_table = gc_alloc(sizeof(float) * (sqrt_count + 1), 0);
	while (++i <= sqrt_count)
		filler->sqrt_table[i] = fast_sqrt(((float)i * (float)i));
}

static void		reset_heatmap(void)
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
			filler->heatmap[i][j++] = 0.0F;
		i++;
	}
}

static void		calc_heat(t_filler *filler, int x, int y)
{
	int			i;
	int			j;
	int			a;
	int			b;

	i = -1;
	while (++i < filler->b_height)
	{
		j = -1;
		while (++j < filler->b_width)
		{
			if (filler->board[i][j] == filler->token[2] ||
					filler->board[i][j] == filler->token[3])
			{
				a = -1;
				while (++a < filler->p_height)
				{
					b = -1;
					while (++b < filler->p_width)
						if (filler->piece[a][b] == PIECE_CHAR)
							filler->heatmap[x][y] += score(i, j, a + x, b + y);
				}
			}
		}
	}
}

static void		fill_heatmap(void)
{
	t_filler	*filler;
	int			i;
	int			j;

	filler = get_filler();
	i = -1;
	while (++i < filler->b_height)
	{
		j = -1;
		while (++j < filler->b_width)
		{
			if (is_placeable(filler, i, j) == 1)
			{
				calc_heat(filler, i, j);
				if (filler->heatmap[i][j] == 0)
					filler->heatmap[i][j] = 1;
			}
		}
	}
}

void			think(void)
{
	t_filler	*filler;

	filler = get_filler();
	if (filler->heatmap == NULL)
		init_thinker();
	reset_heatmap();
	fill_heatmap();
}
