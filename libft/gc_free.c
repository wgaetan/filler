/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gc_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 12:57:50 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:16:55 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static void		gc_free_tag(t_collector *collector, short tag)
{
	int			i;

	i = 0;
	while (i < collector->size)
	{
		if (tag == collector->tag_array[i])
		{
			if (collector->ptr_array[i] != NULL)
				free(collector->ptr_array[i]);
			collector->ptr_array[i] = NULL;
			collector->tag_array[i] = 0;
		}
		i++;
	}
}

void			gc_free(void *ptr, short tag)
{
	t_collector	*collector;
	int			i;

	collector = get_collector();
	i = 0;
	if (tag != 0)
		gc_free_tag(collector, tag);
	else
	{
		while (i < collector->size)
		{
			if (collector->ptr_array[i] == ptr)
			{
				if (collector->ptr_array[i] != NULL)
					free(collector->ptr_array[i]);
				ptr = NULL;
				collector->ptr_array[i] = NULL;
				collector->tag_array[i] = 0;
				break ;
			}
			i++;
		}
	}
}

void			gc_free_all(void)
{
	t_collector	*collector;
	int			i;

	collector = get_collector();
	i = 0;
	while (i < collector->size)
	{
		if (collector->ptr_array[i] != NULL)
			free(collector->ptr_array[i]);
		collector->ptr_array[i] = NULL;
		collector->tag_array[i] = 0;
		i++;
	}
	free(collector->ptr_array);
	free(collector->tag_array);
	free(collector);
}
