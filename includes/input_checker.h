/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:54:09 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/01 18:19:52 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECKER_H
# define INPUT_CHECKER_H

# include "../libft/libft.h"

typedef struct	s_map_cont
{
	int			hashes;
	int			dots;
	int			new_lines;
}				t_map_cont;

int				check_input(t_list *head);

#endif
