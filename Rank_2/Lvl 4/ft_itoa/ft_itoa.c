/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:47:30 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/08 18:04:50 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_nbrlen(int nbr)
{
	int len = 0;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int len = ft_nbrlen(nbr);
	char *result = malloc(len + 1);
	unsigned int abs_nbr = 0;

	if (!result)
		return (NULL);
	result[len] = '\0';

	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	while (abs_nbr > 0)
	{
		result[--len] = abs_nbr % 10 + '0';
		abs_nbr = abs_nbr / 10;
	}
	return (result);
}

// int main(void)
// {
//     int number = -12345;
//     char *string = ft_itoa(number);

//     printf("%s\n", string);
//     return (0);
// }