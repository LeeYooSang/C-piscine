/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooslee <yooslee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:26:56 by yooslee           #+#    #+#             */
/*   Updated: 2023/02/19 19:46:18 by yooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 1)
		return (1);
	else if (nb < 1)
		return (0);
	while (nb)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}
