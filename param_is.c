/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:14:53 by sfraslin          #+#    #+#             */
/*   Updated: 2024/07/07 11:09:45 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	param_col_is_4(char **argv, int n, int c, char grid[4][4])
{
	int	a;
	char	s;

	while (n < 7)
	{
		a = 0;
		s = '1';
		if (argv[1][n] == '4')
		{
			while (a <= 3)
				grid[a++][c] = s++;
		}
		n += 2;
		c++;
	}
	c = 0;
	while (n < 15)
	{
		a = 3;
		s = '1';
		if (argv[1][n] == '4')
		{
			while (a >= 0)
				grid[a--][c] = s++;
		}
		n += 2;
		c++;
	}
}

void	param_row_is_4(char **argv, int n, int l, char grid[4][4])
{
	int	a;
	int	s;

	while (n < 23)
	{
		a = 0;
		s = '1';
		if (argv[1][n] == '4')
		{
			while (a <= 3)
				grid[l][a++] = s++;
		}
		n += 2;
		l++;
	}
	l = 0;
	while (n <= 30)
	{
		a = 3;
		s = '1';
		if (argv[1][n] == '4')
		{
			while (a >= 0)
				grid[l][a--] = s++;
		}
		n += 2;
		l++;
	}
}

void	param_is_1(char **argv, int n, char grid[4][4])
{
	int	a;

	while (n < 7)
	{
		if (argv[1][n] == '1')
			grid[0][a] = '4';
		n += 2;
		a++;
	}
	a = 0;
	while (n < 15)
	{
		if (argv[1][n] == '1')
			grid[3][a] = '4';
		n += 2;
		a++;
	}
	while (n < 23)
	{
		if (argv[1][n] == '1')
			grid[a][0] = '4';
		n += 2;
		a++;
	}
	l = 0;
	while (n <= 30)
	{
		if (argv[1][n]== '1')
			grid[a][3] = '4';
		n += 2;
		a++;
	}
}

/*int	main(int argc, char **argv)
{
	char	grid[4][4] = {
		{'0', '0', '0', '0'},
		{'0', '0', '0', '0'},
		{'0', '0', '0', '0'},
		{'0', '0', '0', '0'}
	};
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 0)
		return 0;
	param_col_is_4(argv, 0, 0, '1', 0, grid);
	param_row_is_4(argv, 16, 0, '1', 0, grid);
	param_is_1(argv, 0, 0, 0, grid);
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &grid[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
	return (0);
}*/
