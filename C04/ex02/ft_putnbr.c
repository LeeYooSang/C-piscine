/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:59:07 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/18 21:56:59 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int arr[], int ab)
{
	int		i;
	char	a;

	i = 1;
	a = '0';
	arr[0] = ab % 10;
	ab = ab / 10;
	while (ab / 10 != 0)
	{
		arr[i] = ab % 10;
		i ++;
		ab = ab / 10;
	}
	arr[i] = ab;
	i ++;
	while (i -- > 0)
	{
		a = arr[i] + 48;
		write(1, &a, 1);
	}
}

void	ft_putnbr(int nb)
{
	int		arr[12];
	char	a;

	a = '0';
	arr[0] = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb < 10 && nb > -10)
	{
		a = nb + 48;
		write(1, &a, 1);
		return ;
	}
	arr[0] = nb % 10;
	print(arr, nb);
}
