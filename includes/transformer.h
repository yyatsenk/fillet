/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:26:28 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/02 13:13:44 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMER_H
# define TRANSFORMER_H

# include "../libft/libft.h"
# include "board_funcs.h"

typedef struct		s_coords
{
	int				row;
	int				col;
}					t_coords;

typedef struct		s_tetro
{
	t_coords		coords[4];
	char			label;
	struct s_tetro	*next;
}					t_tetro;

t_tetro				*fetch_coords(t_list *head, int tet_num);
t_tetro				*create_new_node(void);
void				add_back(t_tetro **head, t_tetro *new_node);
void				show_tetro_list(t_tetro *head);
void				free_composition(char ***composition);
void				free_list_termino(t_tetro **head);

#endif
