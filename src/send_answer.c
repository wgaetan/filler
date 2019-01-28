/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fil_send_move.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/23 15:13:43 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:31:53 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		copy_in(char *dest, const char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

static void		write_move(int x, int y)
{
	char		*send_x;
	char		*send_y;
	char		*send;
	int			size[3];

	send_x = ft_itoa(x);
	send_y = ft_itoa(y);
	size[0] = ft_strlen(send_x);
	size[1] = ft_strlen(send_y);
	size[2] = size[0] + size[1] + 1;
	send = gc_alloc((size[2] + 2), 0);
	copy_in(send, send_x);
	copy_in(send + size[0], " ");
	copy_in(send + size[0] + 1, send_y);
	send[size[2]] = '\n';
	send[size[2] + 1] = '\0';
	write(1, send, size[2] + 1);
	gc_free(send_x, 0);
	gc_free(send_y, 0);
	gc_free(send, 0);
}

void			send_answer(void)
{
	t_filler	*filler;

	filler = get_filler();
	if ((filler->send_x == 0 && filler->send_y == 0) || filler->stop == 2)
	{
		gc_free_all();
		write(1, "0 0\n", 4);
		exit(0);
	}
	if (filler->stop == 1)
		filler->stop = 2;
	write_move(filler->send_x, filler->send_y);
	filler->send_x = 0;
	filler->send_y = 0;
}
