#include <stdlib.h>

int	check_up(int grid[4][4], int edge[4]);
int	check_down(int grid[4][4], int edge[4]);
int	check_left(int grid[4][4], int edge[4]);
int	check_right(int grid[4][4], int edge[4]);

int	exist(int grid[4][4], int pos, int num)
{
	int	i;

	i = 0;
	while (i++ < pos / 8)
		if (grid[i][pos % 8] == num)
			return (1);
	i = 0;
	while (i++ < pos % 8)
		if (grid[pos / 8][i] == num)
			return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	nbrminus;

	i = 0;
	nbr = 0;
	nbrminus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nbrminus++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (nbrminus % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

int	*get_numbers(char *str)
{
	int	i;
	int	j;
	int	*grid;

	if (!(grid = malloc(sizeof(int) * 16)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			grid[j++] = ft_atoi(str + i);
	return (grid);
}

int	found_solution(int grid[4][4], int entry[16])
{
	if (check_up(grid, entry) == 1)
		return (1);
	if (check_right(grid, entry) == 1)
		return (1);
	if (check_down(grid, entry) == 1)
		return (1);
	if (check_up(grid, entry) == 1)
		return (1);
	return (0);
}

int	solve(int grid[4][4], int param[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (exist(grid, pos, size) == 0)
		{
			grid[pos / 4][pos % 4] = size;
			if (found_solution(grid, param) == 0)
			{
				if (solve(grid, param, pos + 1) == 1)
					return (1);
			}
			else
				grid[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

/*
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int	grid[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    int *edge;;

    if (ac < 2)
    {
        write(2, "error", 5);
        return 1;
    }

    edge = get_numbers(av[1]);
    int i = 0;
    solve(grid, edge , 0);
    while (i < 16)
    {
        printf("%d ", edge[i]);
        i++;
    }
    printf("\n");

    free(edge);
    return 0;
}*/
