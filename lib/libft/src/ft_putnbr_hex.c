/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:55:54 by myokogaw          #+#    #+#             */
/*   Updated: 2023/09/30 22:25:54 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned int n, char c)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += ft_putnbr_hex(n / 16, c);
	if (c == 'x')
		ret += ft_putchar(HEX_LOW[n % 16]);
	else if (c == 'X')
		ret += ft_putchar(HEX_UPP[n % 16]);
	return (ret);
}
