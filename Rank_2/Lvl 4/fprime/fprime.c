/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:03:09 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/07 18:27:48 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int number;
	int i = 2;

	if (ac == 2)
	{
		number = atoi(av[1]);
		if (number == 1)
		{
			printf("1");
			return (0);
		}
		while (number > 1)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				number /= i;
				if (number > 1)
					printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}