/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:28 by bboulmie          #+#    #+#             */
/*   Updated: 2024/12/20 15:22:02 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int start = 0;
	char **result = NULL;
	int wc = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == '\n'))
			i++;
		if (str[i])
		{
			wc++;
			while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != '\n')
				i++;
		}
	}
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!result)
		return (NULL);

	i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == '\n'))
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != '\n')
				i++;
			result[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!result[j])
				return (NULL);
			ft_strcpy(result[j++], &str[start]);
		}
	}
	result[j] = NULL;
	return (result);
}