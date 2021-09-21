/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:29 by mel-haya          #+#    #+#             */
/*   Updated: 2021/09/21 17:47:21 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_buffer
{
	int		i;
	int		j;
	char	*buf;
}				t_buffer;

t_buffer	g_buffer;
#endif