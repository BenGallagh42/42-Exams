/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulmie <bboulmie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:43:17 by bboulmie          #+#    #+#             */
/*   Updated: 2025/01/06 16:12:30 by bboulmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char result = 0;

	while (i--)
	{
		result = (result << 1);
		result = result | (octet & 1);
		octet = octet >> 1;
	}
	return (result);
}