void	determine_1234(int board[4][4], int x, int y)
{
	int	i;
	int	j;
	int	inc;

	j = 1;
	inc = 1;
	i = 0;
	if (x % 2)
	{	
		inc = -1;
		i = 3;
	}
	if (x < 2) // colonnes
	{
		place_1234_col(board[4][4], x, y, inc);
	}
	else // lignes
		place_1234_row(board[4][4], x, y, inc);
}

void	place_1234_col(int board[4][4], int x, int y, int inc)
{
	char	s;

	s = '1';
	while (x < 4 || x >= 0)
	{
		board[x][y] = s++;
		x += inc;
	}
}

void	place_1234_row(int board[4][4], int x, int y, int inc)
{
	char	s;

	s = '1';
	while (y < 4 || y >= 0)
	{
		board[x][y] = s++;
		y += inc;
	}
}

void	place_4(int board[4][4], int x, int y)
{
	board[x][y] == '4';
}

void	check_cases(char board[4][4], int ac, char **av)
{
	int	i;

	i = 0;
	while (av[ac - 1][i])
	{
		if (av[ac - 1][i] == '4')
			determine_1234(board[4][4], i / 8, (i % 8) / 2);
		if (av[ac - 1][i] == '1')
			place_4(board[4][4], i / 8, (i % 8) / 2);
	}
}
