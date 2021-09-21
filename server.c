/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:25 by mel-haya          #+#    #+#             */
/*   Updated: 2021/09/21 18:05:09 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb <= 9)
	{
		ft_putchar(48 + nb);
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putchar(48 + (nb % 10));
}

void	get_signal(int sig)
{
	sig -= 30;
	if (g_buffer.j == 7)
		g_buffer.buf[g_buffer.i] = 0;
	g_buffer.buf[g_buffer.i] += sig * 1 << g_buffer.j;
	if (g_buffer.j == 0)
	{
		if (!g_buffer.buf[g_buffer.i])
		{
			write(1, g_buffer.buf, g_buffer. i);
			write(1, "\n", 1);
			g_buffer.i = 0;
			g_buffer.j = 7;
			return ;
		}
		g_buffer.j = 7;
		g_buffer.i++;
	}
	else
		g_buffer.j--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	g_buffer.i = 0;
	g_buffer.j = 7;
	g_buffer.buf = malloc(1000000);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	free(g_buffer.buf);
	return (0);
}
