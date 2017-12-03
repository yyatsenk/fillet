/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetro_lst_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:34:01 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 14:31:50 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/transformer.h"

t_tetro		*create_new_node(void)
{
	int		i;
	t_tetro	*new_node;

	new_node = (t_tetro *)malloc(sizeof(t_tetro));
	if (!new_node)
		return (0);
	i = 0;
	while (i < 4)
	{
		new_node->coords[i].row = 0;
		new_node->coords[i].col = 0;
		i++;
	}
	new_node->label = '-';
	new_node->next = 0;
	return (new_node);
}

void		add_back(t_tetro **head, t_tetro *new_node)
{
	t_tetro *temp;

	if (head && *head && new_node)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = 0;
	}
}

void		show_tetro_list(t_tetro *head)
{
	int i;

	while (head)
	{
		i = 0;
		while (i < 4)
		{
			ft_putstr(ft_itoa(head->coords[i].row));
			ft_putstr(ft_itoa(head->coords[i].col));
			ft_putstr("\n");
			i++;
		}
		ft_putendl(&(head->label));
		ft_putstr("\n");
		head = head->next;
	}
}

void		free_composition(char ***composition)
{
	char ***temp;

	temp = composition;
	while (*composition)
	{
		free_board(*composition);
		(*composition) = 0;
		composition++;
	}
	free(temp);
}

void		free_list_termino(t_tetro **head)
{
	t_tetro *tmp;

	tmp = NULL;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp->next = NULL;
	}
}
