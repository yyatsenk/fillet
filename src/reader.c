/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:42:10 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/28 13:40:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reader.h"

#define BUFFER_SIZE 1

t_list	*read_file(char *filename)
{
	int		f;
	char	buffer[BUFFER_SIZE];
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	head = NULL;
	f = open(filename, O_RDONLY);
	read(f, buffer, BUFFER_SIZE);
	head = ft_lstnew(&buffer[0], sizeof(buffer));
	if (!head)
		return (NULL);
	tail = head;
	while (read(f, buffer, BUFFER_SIZE))
	{
		new = ft_lstnew(&buffer[0], sizeof(buffer));
		if (!new)
			return (ft_lst_erase(head));
		ft_lstadd_back(&tail, new);
		tail = tail->next;
	}
	close(f);
	return (head);
}
