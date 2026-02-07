/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:49:55 by bboulmie          #+#    #+#             */
/*   Updated: 2024/10/17 13:23:36 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *av)
{
	int i = 0;
	int result = 0;
	int signe = 1;

	while (av[i] == ' ' || (av[i] >= 9 && av[i] <= 13))
		i++;
	if (av[i] == '+')
		i++;
	if (av[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (av[i] >= '0' && av[i] <= '9')
	{
		result = result * 10 + (av[i] - '0');
		i++;
	}
	return (result * signe);
}

void ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	int i = 1;
	int nbr = ft_atoi(av[1]);

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
