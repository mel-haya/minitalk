/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:23:19 by mel-haya          #+#    #+#             */
/*   Updated: 2021/09/21 17:39:11 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	output;
	int		i;
	int		sign;
	int		j;

	output = 0;
	j = 0;
	i = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\r' || str[i] == ' ')
		|| (str[i] == '\v' || str[i] == '\n' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i] - '0';
		output = output * 10 + j;
		i++;
	}
	return (output * sign);
}
