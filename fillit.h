/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:15:33 by rrosaura          #+#    #+#             */
/*   Updated: 2019/05/23 20:53:38 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "fcntl.h"
# include <stdio.h>

int count_and_check(char **matrix);
int check_tetrim(char **matrix);
int check_sharps(char **matrix, int i);
int validate(char **matrix);
int	count_sharps(char **matrix);

#endif
