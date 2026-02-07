/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:06:18 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/06 18:55:07 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i = 0;
	int result;
	int sign = 1;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_puthex(int n)
{
	char hex_digit[] = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	write(1, &hex_digit[n % 16], 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_puthex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}