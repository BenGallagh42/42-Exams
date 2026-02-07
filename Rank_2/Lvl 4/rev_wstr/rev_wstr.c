/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:47:42 by bboulmie          #+#    #+#             */
/*   Updated: 2025/02/07 16:37:46 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int start = 0;
		int end = 0;
		int flag = 0;

		while (av[1][i] != '\0')
			i++;
		i--;
		while (i >= 0)
		{
			while (i >= 0 && (av[1][i] == 32 || av[1][i] == 9))
				i--;
			end = i;
			while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
				i--;
			start = i + 1;
			if (flag)
				write(1, " ", 1);
			while (start <= end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
			flag = 1;
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
