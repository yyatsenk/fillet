/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:15:33 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 15:38:01 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	show(t_list *node)
{
	ft_putchar(*(char *)(node->content));
}

int		main(int argc, char **argv)
{
	t_list	*file_cont;
	int		tet_num;
	t_tetro	*tetro_list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [filename]\n");
		return (0);
	}
	file_cont = read_file(argv[1]);
	ft_lstiter(file_cont, show);
	tet_num = check_input(file_cont);
	tetro_list = fetch_coords(file_cont, tet_num);
	solve_problem(tetro_list, tet_num);
	ft_lst_erase(file_cont);
	return (0);
}
