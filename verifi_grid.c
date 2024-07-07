#include <stdio.h>
#include <stdlib.h>

int	check_up(int grid[4][4], int edge[16])
{
	int	i;
	int	j;
	int	count;
	char	max;

	i = 0;
	while (i < 4)
	{
		max = grid[0][i];
		count = 1;
		j = 0;
		while (j < 3)
		{
			if (max < grid[j + 1][i])
			{
				max = grid[j + 1][i];
				count ++;
			}
			j++;
		}
		if (edge[i] != count)
			return (1);
		i++;
	}
	return (0);
}

int	check_down(int grid[4][4], int edge[4])
{
	int	i;
	int	j;
	int	count;
	char	max;
	int	v;

	i = 0;
	v = 3;
	while (i < 4)
	{
		max = grid[3][i];
		count = 1;
		j = 3;
		while (j > 0)
		{
			if (max < grid[j - 1][i])
			{
				max = grid[j - 1][i];
				count ++;
			}
			j--;
		}
		if (edge[v++] != count)
			return (1);
		i ++;
	}
	return (0);
}

int	check_left(int grid[4][4], int edge[4])
{
	int	i;
	int	j;
	int	count;
	char	max;
	int	v;

	i = 0;
	v = 7;
	while (i < 4)
	{
		max = grid[i][0];
		count = 1;
		j = 0;
		while (j < 3)
		{
			if (max < grid[i][j + 1])
			{
				max = grid[i][j +1];
				count ++;
			}
			j++;
		}
		if (edge[v++] != count)
			return (1);
		i ++;
	}
	return (0);
}

int	check_right(int grid[4][4], int edge[4])
{
	int	i;
	int	j;
	int	count;
	char	max;
	int	v;

	i = 0;
	v = 11;
	while (i < 4)
	{
		max = grid[i][3];
		count = 1;
		j = 3;
		while (j > 0)
		{
			if (max < grid[i][j - 1])
			{
				max = grid[i][j - 1];
				count ++;
			}
			j--;
		}
		if (edge[v++] != count)
			return (1);
		i++;
	}
	return (0);
}

/*
int main() {
    int grid[4][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 1},
        {3, 4, 1, 2},
        {4, 1, 2, 3}
    };

    int edge_top[4] = {4, 3, 2, 1};
    int edge_bottom[4] = {1, 2, 2, 2};
    int edge_left[4] = {4, 3, 2, 1};
    int edge_right[4] = {1, 2, 2, 2};




    if (!(check_up(grid, edge_top) && check_down(grid, edge_bottom) &&
        check_left(grid, edge_left) && check_right(grid, edge_right)))
		{
        printf("valide!\n");
    } else {
        printf("%d\n%d\n%d\n%d\n",check_up(grid, edge_top) , check_down(grid, edge_bottom) ,
        check_left(grid, edge_left), check_right(grid, edge_right));
        
        printf("invalide!\n");
    }

    return 0;
}*/
