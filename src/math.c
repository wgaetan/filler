/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   math.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 16:45:50 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:15:12 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

float			score(int i, int j, int x_diff, int y_diff)
{
	t_filler	*filler;
	int			index;
	int			multi;
	float		ret;

	filler = get_filler();
	index = ft_abs(x_diff - i) + ft_abs(y_diff - j);
	multi = (filler->board[i][j] == filler->token[2] ? 100 : 1000);
	ret = (filler->sqrt_table[index] / filler->sqrt_table[filler->b_height +
			filler->b_width]) * 10;
	if (ret == 0)
		ret = 1.0;
	ret = (float)multi / ret;
	ret *= ret;
	ret /= 10;
	return (ret);
}

float			fast_sqrt(float n)
{
	long		i;
	float		x;
	float		y;

	x = n * 0.5F;
	y = n;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5F - (x * y * y));
	return (y * n);
}
