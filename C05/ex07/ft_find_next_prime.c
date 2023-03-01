/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:57:18 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/19 21:21:32 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!next_prime(nb))
		nb++;
	return (nb);
}
