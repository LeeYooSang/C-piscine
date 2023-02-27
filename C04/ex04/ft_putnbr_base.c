/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:04 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/19 16:14:52 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr_base(unsigned int nbr, char *base, int bs)
{
	unsigned int	i;

	if (nbr == 0)
		return ;
	putnbr_base(nbr / bs, base, bs);
	i = nbr % bs;
	write(1, base + i, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	int		bs;
	char	check[127];

	n = 0;
	while (n <= 127)
		check[n++] = 0;
	bs = 0;
	while (base[bs])
	{
		if (check[(int)base[bs]] == 1 || base[bs] == '+' || base[bs] == '-')
			return ;
		check[(int)base[bs]]++;
		bs++;
	}
	if (bs == 0 || bs == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	else if (nbr == 0)
		write(0, "0", 1);
	putnbr_base(nbr, base, bs);
}
