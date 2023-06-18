#include <stdio.h>

#define N 9

int count;

void showSolution(int a[N][N])
{
	printf("Solution %d:\n", count);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 9; i++)
		printf("**");
	printf("\n");
}

int check(int k, int x, int a[N][N])
{
	int r = x / 9;
	int c = x % 9;
	for (int i = 0; i < 9; i++)
		if (a[r][i] == k || a[i][c] == k)
			return 0;
	r /= 3;
	c /= 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i + r * 3][j + c * 3] == k)
				return 0;
	return 1;
}

void copyMap(int a[N][N], int b[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void solve(int x, int a[N][N])
{
	int temp[N][N];
	copyMap(temp, a);

	if (temp[x / 9][x % 9])
		solve(x + 1, a);
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (check(i, x, temp))
			{
				temp[x / 9][x % 9] = i;
				if (x == 80)
				{
					count++;
					showSolution(temp);
				}
				else
					solve(x + 1, temp);
			}
		}
	}
}

int main()
{
	int a[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	count = 0;
	solve(0, a);
	printf("%d\n",count);
}
