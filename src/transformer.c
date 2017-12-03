/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:25:11 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 13:37:46 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/transformer.h"

static char			*get_row(t_list **head)
{
	int		i;
	char	*row;

	row = ft_strnew(4);
	i = 0;
	while (i < 4 && *head)
	{
		if (*(char *)((*head)->content) != '\n')
		{
			row[i] = *(char *)((*head)->content);
			i++;
		}
		*head = (*head)->next;
	}
	return (row);
}

static char			***transform_input(t_list *head, int tet_num)
{
	int		i;
	int		j;
	char	***composition;
	char	**tetro;
	char	*row;

	composition = (char ***)malloc(sizeof(char **) * (tet_num + 1));
	if (!composition)
		return (0);
	i = 0;
	while (i < tet_num)
	{
		j = 0;
		tetro = (char **)malloc(sizeof(char *) * 5);
		while (j < 4)
		{
			row = get_row(&head);
			tetro[j++] = row;
		}
		tetro[j] = 0;
		composition[i] = tetro;
		i++;
	}
	composition[i] = 0;
	return (composition);
}

static t_coords		get_zero_coords(char **tetro)
{
	t_coords a_c;

	a_c.row = 0;
	a_c.col = 0;
	while (a_c.row < 4)
	{
		a_c.col = 0;
		while (a_c.col < 4)
		{
			if (tetro[a_c.row][a_c.col] == '#')
				break ;
			a_c.col++;
		}
		if (tetro[a_c.row][a_c.col] == '#')
			break ;
		a_c.row++;
	}
	return (a_c);
}

/*
** Get coordinates of current tetromino
** a_c means absolute coordinates
** t_z means tetromeno zero coordinates;
*/

static t_tetro		*analyze_tetro(char **tetro)
{
	t_tetro		*tetro_node;
	t_coords	a_c;
	t_coords	t_z;
	int			i;

	tetro_node = create_new_node();
	a_c = get_zero_coords(tetro);
	t_z = a_c;
	a_c.col++;
	i = 1;
	while (tetro[a_c.row])
	{
		while (tetro[a_c.row][a_c.col])
		{
			if (tetro[a_c.row][a_c.col] == '#')
			{
				tetro_node->coords[i].row = a_c.row - t_z.row;
				tetro_node->coords[i++].col = a_c.col - t_z.col;
			}
			a_c.col++;
		}
		a_c.col = 0;
		a_c.row++;
	}
	return (tetro_node);
}

t_tetro				*fetch_coords(t_list *head, int tet_num)
{
	char	***composition;
	t_tetro	*coord_list;
	t_tetro	*curr_tetro;
	int		count;

	composition = transform_input(head, tet_num);
	coord_list = create_new_node();
	count = 0;
	while (composition[count])
	{
		curr_tetro = analyze_tetro(composition[count]);
		curr_tetro->label = count + 'A';
		add_back(&coord_list, curr_tetro);
		count++;
	}
	free_composition(composition);
	show_tetro_list(coord_list);
	return (coord_list);
}
