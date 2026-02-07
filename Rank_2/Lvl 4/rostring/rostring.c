/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:36 by bboulmie          #+#    #+#             */
/*   Updated: 2024/12/04 16:22:51 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 0;
		int start = 0;
		int end = 0;

		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		start = i;
		while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
			i++;
		end = i;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
			{
				write(1, &av[1][i], 1);
				i++;
			}
			while (av[1][i] == 32 || av[1][i] == 9)
				i++;
			if (av[1][i])
				write(1, " ", 1);
		}
		write(1, " ", 1);
		while (start < end)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}