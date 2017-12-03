/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:31:46 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 18:09:28 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"
#include <stdio.h>

static int	is_possible(t_coords a_c, char **board, int b_size, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		if (temp.row < 0 || temp.row >= b_size ||
			temp.col < 0 || temp.col >= b_size ||
			board[temp.row][temp.col] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	set_tetro(t_coords a_c, char ***board, t_tetro *tetro)
{
	int			i;
	t_coords	temp;

	i = 0;
	while (i < 4)
	{
		temp.row = a_c.row + tetro->coords[i].row;
		temp.col = a_c.col + tetro->coords[i].col;
		(*board)[temp.row][temp.col] = tetro->label;
		i++;
	}
}

static int	bt(int b_size, char **board, t_tetro *tetro, int i)
{
	t_coords	a_c;
	int			succes;

	if (!tetro)
	{
		print_board(board);
		return (1);
	}
	a_c.row = -1;
	succes = 0;
	while (++a_c.row < b_size)
	{
		a_c.col = -1;
		if (a_c.row == 0)
			a_c.col = i - 1;
		while (++a_c.col < b_size)
			if (is_possible(a_c, board, b_size, tetro))
			{
				set_tetro(a_c, &board, tetro);
				succes = bt(b_size, board, tetro->next, i);
				if (succes)
					return (1);
			}
	}
	return (succes);
}

void		solve_problem(t_tetro *tetro, int tet_num)
{
	int		b_size;
	char	**board;
	int		succes;
	int		i;

	b_size = get_initial_size(tet_num);
	succes = 0;
	i = 0;
	while (b_size)
	{
		board = create_board(b_size);
		succes = bt(b_size, board, tetro->next, i);
		i++;
		if (succes)
			break ;
		b_size++;
	}
	free_list_termino(&tetro);
}
