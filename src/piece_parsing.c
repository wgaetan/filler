/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 15:12:28 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 15:29:57 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		alloc_piece(void)
{
	t_filler	*filler;
	int			i;
	int			j;

	filler = get_filler();
	i = 0;
	filler->piece = gc_alloc(sizeof(char *) * filler->p_height, 2);
	while (i < filler->p_height)
	{
		j = 0;
		filler->piece[i] = gc_alloc(sizeof(char) * filler->p_width, 2);
		while (j < filler->p_width)
			filler->piece[i][j++] = '.';
		i++;
	}
}

static void		add_piece_line(char *line)
{
	t_filler	*filler;
	int			i;

	filler = get_filler();
	if (ft_strlen(line) != (size_t)filler->p_width)
		gc_exit(-1);
	i = -1;
	while (++i < filler->p_width)
	{
		if (line[i] == PIECE_CHAR)
			filler->piece[filler->parse_piece_line][i] = PIECE_CHAR;
		else if (line[i] != '.')
			gc_exit(-1);
	}
	filler->parse_piece_line++;
}

static void		resize_piece(void)
{
	t_filler	*filler;
	int			i;
	int			j;
	int			max_i;
	int			max_j;

	filler = get_filler();
	i = -1;
	max_i = 0;
	max_j = 0;
	while (++i < filler->p_height)
	{
		j = -1;
		while (++j < filler->p_width)
			if (filler->piece[i][j] == PIECE_CHAR)
			{
				max_i = i;
				max_j = j > max_j ? j : max_j;
			}
	}
	filler->p_height = max_i + 1;
	filler->p_width = max_j + 1;
}

void			get_piece_dim(char *line)
{
	t_filler	*filler;
	char		**split;
	int			error;

	filler = get_filler();
	error = 0;
	if (ft_split_elem_count(split = ft_strsplit(line, ' ')) != 3)
		error = 1;
	else if (ft_strncmp(split[0], "Piece", 5))
		error = 1;
	else if (ft_isalldigit(split[1]) != 1 || ft_isalldigit(split[2]) != 1)
		if (split[2][ft_strlen(split[2]) - 1] != ':')
			error = 1;
	if (error == 0)
	{
		filler->p_height = ft_atoi(split[1]);
		filler->p_width = ft_atoi(split[2]);
	}
	ft_strsplit_free(split);
	if (filler->p_height == 0 || filler->p_width == 0 || error == 1)
		gc_exit(-1);
	filler->parse_state = 4;
}

void			get_piece_data(char *line)
{
	t_filler	*filler;
	int			error;

	filler = get_filler();
	error = 0;
	if (filler->piece == NULL)
		alloc_piece();
	add_piece_line(line);
	if (filler->parse_piece_line == filler->p_height)
	{
		resize_piece();
		filler->parse_state = 5;
	}
}
