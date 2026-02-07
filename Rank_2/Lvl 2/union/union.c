/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:07 by bboulmie          #+#    #+#             */
/*   Updated: 2024/12/19 12:09:04 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0;
		int j = 0;
		unsigned char seen[256] = {0};

		while (av[1][i] != '\0')
		{
			if (!seen[(unsigned char)av[1][i]])
			{
				write(1, &av[1][i], 1);
				seen[(unsigned char)av[1][i]] = 1;
			}
			i++;
		}
		while (av[2][j] != '\0')
		{
			if (!seen[(unsigned char)av[2][j]])
			{
				write(1, &av[2][j], 1);
				seen[(unsigned char)av[2][j]] = 1;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}