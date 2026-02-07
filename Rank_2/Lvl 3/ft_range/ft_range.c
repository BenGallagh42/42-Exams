/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:16:43 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/06 16:14:55 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = abs(end - start) + 1;
	int *res = malloc(sizeof(int) * len);

	while (i < len)
	{
		res[i] = start;
		if (end > start)
			start++;
		else
			start--;
		i++;
	}
	return (res);
}

// int main(void)
// {
// 	int *result = ft_range(0, 0);
// 	if (result)
// 	{
// 		printf("%d\n", result[0]);
// 		free(result);
// 	}
// 	return (0);
// }