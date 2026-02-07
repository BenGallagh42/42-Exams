/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:50:01 by bboulmie          #+#    #+#             */
/*   Updated: 2024/10/18 13:20:53 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void str_capitalizer(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z'
			&& !(i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;

	if (ac == 1)
		write(1, "\n", 1);
	while (i < ac)
	{
		str_capitalizer(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}