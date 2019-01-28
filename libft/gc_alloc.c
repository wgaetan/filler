/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gc_alloc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 14:09:07 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:07:10 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static void		gc_realloc_collector(void)
{
	t_collector	*collector;
	void		**new_ptrarray;
	short		*new_tagarray;
	int			new_size;
	int			i;

	collector = get_collector();
	new_size = collector->size + GC_LIMIT;
	i = 0;
	if (!(new_ptrarray = malloc(sizeof(void *) * new_size)))
		gc_error("GC failed to reallocate collector\n");
	if (!(new_tagarray = malloc(sizeof(short) * new_size)))
		gc_error("GC failed to reallocate tag array\n");
	while (i < new_size)
	{
		new_ptrarray[i] =
		(i < collector->size) ? collector->ptr_array[i] : NULL;
		new_tagarray[i] = (i < collector->size) ? collector->tag_array[i] : 0;
		i++;
	}
	free(collector->ptr_array);
	free(collector->tag_array);
	collector->ptr_array = new_ptrarray;
	collector->tag_array = new_tagarray;
	collector->size = new_size;
}

void			gc_add(void *ptr, short tag)
{
	t_collector	*collector;
	int			i;

	collector = get_collector();
	i = 0;
	while (i < collector->size && collector->ptr_array[i] != NULL)
	{
		if (collector->ptr_array[i] == ptr)
			return ;
		i++;
	}
	if (i >= collector->size)
		gc_realloc_collector();
	collector->ptr_array[i] = ptr;
	collector->tag_array[i] = tag;
}

void			*gc_alloc(size_t size, short tag)
{
	t_collector	*collector;
	void		*new_ptr;
	int			i;

	collector = get_collector();
	if (!(new_ptr = ft_memalloc(size)))
		gc_error("GC failed to allocate pointer\n");
	i = 0;
	while (i < collector->size && collector->ptr_array[i] != NULL)
		i++;
	if (i >= collector->size)
		gc_realloc_collector();
	collector->ptr_array[i] = new_ptr;
	collector->tag_array[i] = tag;
	return (new_ptr);
}
