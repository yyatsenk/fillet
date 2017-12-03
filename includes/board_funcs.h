/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:04:42 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/01 18:08:16 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_FUNCS_H
# define BOARD_FUNCS_H

int		get_initial_size(int tet_num);
void	print_board(char **board);
void	free_board(char **board);
char	**create_board(int board_size);
char	**dup_board(char **board, int board_size);

#endif
