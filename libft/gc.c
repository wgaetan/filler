/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gc.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 13:18:28 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 17:49:08 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static t_collector		*init_collector(void)
{
	t_collector			*collector;
	int					i;

	i = 0;
	if (!(collector = malloc(sizeof(t_collector))))
		exit(-1);
	if (!(collector->ptr_array = malloc(sizeof(void *) * GC_LIMIT)))
	{
		free(collector);
		exit(-1);
	}
	if (!(collector->tag_array = malloc(sizeof(short) * GC_LIMIT)))
	{
		free(collector);
		free(collector->ptr_array);
		exit(-1);
	}
	while (i < GC_LIMIT)
	{
		collector->ptr_array[i] = NULL;
		collector->tag_array[i] = 0;
		i++;
	}
	collector->size = GC_LIMIT;
	return (collector);
}

t_collector				*get_collector(void)
{
	static t_collector	*collector = NULL;
	int					i;

	if (collector == NULL)
		collector = init_collector();
	return (collector);
}

void					gc_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	gc_exit(-1);
}

void					gc_exit(int exit_sig)
{
	t_collector			*collector;
	int					i;

	collector = get_collector();
	i = 0;
	while (i < collector->size)
	{
		if (collector->ptr_array[i] != NULL)
		{
			free(collector->ptr_array[i]);
			collector->ptr_array[i] = NULL;
			collector->tag_array[i] = 0;
		}
		i++;
	}
	free(collector->ptr_array);
	free(collector->tag_array);
	free(collector);
	exit(exit_sig);
}
