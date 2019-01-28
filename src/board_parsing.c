/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   board_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 14:23:38 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 22:08:45 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		check_head_line(char *line)
{
	t_filler	*filler;
	int			i;

	filler = get_filler();
	i = 0;
	while (line && i < (filler->b_width + 4))
	{
		if (i < 4)
		{
			if (line[i] != ' ')
				break ;
		}
		else if (line[i] != (((i - 4) % 10) + '0'))
			break ;
		i++;
	}
	if ((size_t)i < ft_strlen(line))
	{
		write(2, "Error on board headline\n", 24);
		gc_exit(-1);
	}
	filler->parse_board_line++;
}

static void		alloc_board(void)
{
	t_filler	*filler;
	int			i;
	int			j;

	filler = get_filler();
	i = 0;
	filler->board = gc_alloc(sizeof(char *) * filler->b_height, 1);
	while (i < filler->b_height)
	{
		j = 0;
		filler->board[i] = gc_alloc(sizeof(char) * filler->b_width, 1);
		while (j < filler->b_width)
			filler->board[i][j++] = '.';
		i++;
	}
}

static void		add_board_line(char *line)
{
	t_filler	*filler;
	int			i;

	filler = get_filler();
	if (ft_strlen(line) != (size_t)filler->b_width)
		gc_exit(-1);
	i = -1;
	while (++i < filler->b_width)
	{
		if (line[i] == TOKEN_1 || line[i] == TOKEN_1_NEW)
			filler->board[filler->parse_board_line][i] =
				(filler->board[filler->parse_board_line][i] == '.') ?
				TOKEN_1_NEW : TOKEN_1;
		else if (line[i] == TOKEN_2 || line[i] == TOKEN_2_NEW)
			filler->board[filler->parse_board_line][i] =
				(filler->board[filler->parse_board_line][i] == '.') ?
				TOKEN_2_NEW : TOKEN_2;
		else if (line[i] != '.')
			gc_exit(-1);
	}
	filler->parse_board_line++;
}

void			get_board_dim(char *line)
{
	t_filler	*filler;
	char		**split;
	int			error;

	filler = get_filler();
	error = 0;
	if (ft_split_elem_count(split = ft_strsplit(line, ' ')) != 3)
		error = 1;
	else if (ft_strncmp(split[0], "Plateau", 7) != 0)
		error = 1;
	else if (ft_isalldigit(split[1]) != 1 || ft_isalldigit(split[2]) != 1)
		if (split[2][ft_strlen(split[2]) - 1] != ':')
			error = 1;
	if (filler->board == NULL && error == 0)
	{
		filler->b_height = ft_atoi(split[1]);
		filler->b_width = ft_atoi(split[2]);
	}
	if (filler->b_height == 0 || filler->b_width == 0 ||
			ft_atoi(split[1]) != filler->b_height ||
			ft_atoi(split[2]) != filler->b_width || error == 1)
		gc_exit(-1);
	ft_strsplit_free(split);
	filler->parse_state = 2;
}

void			get_board_data(char *line)
{
	t_filler	*filler;
	char		**split;
	int			error;

	filler = get_filler();
	error = 0;
	if (filler->board == NULL)
		alloc_board();
	if (filler->parse_board_line == -1)
		check_head_line(line);
	else
	{
		if (ft_split_elem_count(split = ft_strsplit(line, ' ')) != 2)
			error = 1;
		if (ft_strlen(split[0]) != 3 || ft_isalldigit(split[0]) != 1 ||
				ft_atoi(split[0]) != filler->parse_board_line)
			error = 1;
		if (error == 0)
			add_board_line(split[1]);
		else
			gc_exit(-1);
		ft_strsplit_free(split);
	}
	if (filler->parse_board_line == filler->b_height)
		filler->parse_state = 3;
}
