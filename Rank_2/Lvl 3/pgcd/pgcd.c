/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:24:31 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/07 17:36:00 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int nb1 = atoi(av[1]);
		int nb2 = atoi(av[2]);
		int temp = 0;

		while (nb2)
		{
			temp = nb2;
			nb2 = nb1 % nb2;
			nb1 = temp;
		}
		printf("%d", nb1);
	}
	printf("\n");
	return (0);
}