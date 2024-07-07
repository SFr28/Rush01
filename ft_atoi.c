/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:24:22 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/06 19:43:16 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int			i;
	int			rez;
	int			s;

	rez = 0;
	s = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
	{
		if (str[i] != ' ')
		{
			rez *= 10;
			rez += (str[i] - '0');
		}
		i++;
	}
	return (s * rez);
}