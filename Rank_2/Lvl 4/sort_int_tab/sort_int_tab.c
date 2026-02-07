/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:45 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/09 11:27:53 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

// void    ft_putnbr(int n)
// {
//     char c;

//     if (n > 9)
//         ft_putnbr(n / 10);
//     c = n % 10 + '0';
//     write(1, &c, 1);
// }

// int main(void)
// {
// 	int tab[] = {5, 2, 9, 1, 7};
// 	unsigned int size = 5;
// 	unsigned int i = 0;

// 	sort_int_tab(tab,  size);
// 	while (i < size)
// 	{
// 		ft_putnbr(tab[i]);
// 		write(1, " ", 1);
// 		i++;
// 	}
// 	return (0);
// }