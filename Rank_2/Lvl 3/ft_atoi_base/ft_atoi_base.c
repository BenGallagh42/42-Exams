/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:05:02 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/09 12:31:28 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int c = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = str[i] - 'A' + 10;
		else
			break ;
		result = result * str_base + c;
		i++;
	}
	return (result * sign);
}

// int main(void)
// {
// 	printf("Base 16 ('A2') : %d\n", ft_atoi_base("A2", 16));
// 	printf("Base 10 ('1234') : %d\n", ft_atoi_base("1234", 10));
// 	printf("Base 2 ('1011') : %d\n", ft_atoi_base("1011", 2));
// 	printf("Base 36 ('z2') : %d\n", ft_atoi_base("z2", 36));
// 	printf("Base 16 ('-1F') : %d\n", ft_atoi_base("-1F", 16));
// 	return (0);
// }