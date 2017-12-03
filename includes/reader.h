/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:43:54 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/28 13:48:52 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

# include "../libft/libft.h"

t_list	*read_file(char *filename);

#endif
