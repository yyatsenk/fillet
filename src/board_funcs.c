/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:54:24 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/01 17:13:19 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/board_funcs.h"
#include "../libft/libft.h"

int		get_initial_size(int tet_num)
{
	int size;

	size = 1;
	while (size * size < tet_num * 4)
		size++;
	return (size);
}

void	print_board(char **board)
{
	if (board)
	{
		while (*board)
		{
			ft_putendl(*board);
			board++;
		}
	}
}

void	free_board(char **board)
{
	int i;

	if (board)
	{
		i = 0;
		while (board[i])
		{
			free(board[i]);
			board[i] = NULL;
			i++;
		}
		free(board);
	}
}

char	**dup_board(char **board, int board_size)
{
	int		i;
	char	**new_board;

	new_board = (char **)malloc(sizeof(char *) * (board_size + 1));
	i = 0;
	while (i < board_size)
	{
		new_board[i] = ft_strdup(board[i]);
		i++;
	}
	new_board[i] = 0;
	return (new_board);
}

char	**create_board(int board_size)
{
	int		i;
	int		j;
	char	**board;
	char	*row;

	board = (char **)malloc(sizeof(char *) * (board_size + 1));
	if (!board)
		return (0);
	i = 0;
	while (i < board_size)
	{
		j = 0;
		row = (char *)malloc(sizeof(char) * (board_size + 1));
		while (j < board_size)
		{
			row[j] = '.';
			j++;
		}
		row[j] = '\0';
		board[i] = row;
		i++;
	}
	board[i] = 0;
	return (board);
}
