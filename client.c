/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:34 by mel-haya          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:03 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int is_nbr(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	send_char(pid_t pid, char c, int i)
{
	if (!i)
		return ;
	i--;
	send_char(pid, c / 2, i);
	if (c % 2)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(30);
}

int	main(int c, char **v)
{
	pid_t	pid;
	int		i;
	
	i = 0;
	if(c != 3 || !is_nbr(v[1]))
		return (1);
	pid = ft_atoi(v[1]);
	if (pid < 0 || pid > 99999)
		return (1);
	while (1)
	{
		send_char(pid, v[2][i], 8);
		if (!v[2][i])
			return (0);
		i++;
	}
}
