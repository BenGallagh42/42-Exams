/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:00:56 by bboulmie          #+#    #+#             */
/*   Updated: 2024/10/16 20:03:30 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i = 0;
	int len = abs(end - start) + 1;
	int *res = malloc(sizeof(int) * len);

	while (i < len)
	{
		res[i] = end;
		if (end > start)
			end--;
		else
			end++;
		i++;
	}
	return (res);
}