/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:53:05 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 15:26:52 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/input_checker.h"

#include <stdio.h>

/*
** Get information about map
** error if wrong character will be found
*/

static t_map_cont	parse_content(t_list *head)
{
	t_map_cont cont;

	cont.hashes = 0;
	cont.dots = 0;
	cont.new_lines = 0;
	while (head)
	{
		if (*(char *)(head->content) == '#')
			cont.hashes++;
		else if (*(char *)(head->content) == '.')
			cont.dots++;
		else if (*(char *)(head->content) == '\n')
			cont.new_lines++;
		else
		{
			ft_putendl("error");
			exit(1);
		}
		head = head->next;
	}
	return (cont);
}

/*
** Check right form of map:
** - position of newlines;
** - invalid row length;
*/

static void			check_field_form(t_list *head)
{
	int position;

	position = 1;
	while (head)
	{
		if (*(char *)(head->content) == '.' || *(char *)(head->content) == '#')
			;
		else if (*(char *)(head->content) == '\n' && position % 5 == 0)
			;
		else
		{
			ft_putendl("error");
			exit(1);
		}
		position++;
		if (position == 21)
			position = 0;
		head = head->next;
	}
}

static int			adjacency(t_list *head)
{
	int i;
	int neighbors;

	i = 0;
	neighbors = 0;
	while (head->next && i < 6)
	{
		if (i == 1 && *(char *)(head->content) == '#')
			neighbors++;
		if (i == 5 && *(char *)(head->content) == '#')
			neighbors++;
		if (*(char *)(head->content) == '\n' &&
			*(char *)(head->next->content) == '\n')
			break ;
		head = head->next;
		i++;
	}
	return (neighbors);
}

static void			check_tetromino(t_list *head)
{
	int hashes;
	int neighbors;

	hashes = 0;
	neighbors = 0;
	while (head)
	{
		if (*(char *)(head->content) == '#')
		{
			neighbors += adjacency(head);
			hashes++;
		}
		if (hashes == 4 && (neighbors < 3 || neighbors > 4))
		{
			ft_putendl("error");
			exit(1);
		}
		else if (hashes == 4 && (neighbors == 3 || neighbors == 4))
		{
			hashes = 0;
			neighbors = 0;
		}
		head = head->next;
	}
}

int					check_input(t_list *head)
{
	t_map_cont cont;

	cont = parse_content(head);
	check_field_form(head);
	if (cont.hashes % 4 != 0 ||
		cont.new_lines != cont.hashes + cont.hashes / 4 - 1)
	{
		ft_putendl("error");
		exit(1);
	}
	check_tetromino(head);
	if (cont.hashes / 4 > 26)
	{
		ft_putendl("error");
		exit(1);
	}
	return (cont.hashes / 4);
}
