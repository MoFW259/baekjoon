#include<stdio.h>

char a[10][10] = {0, }, b[10][10] = {0, }, p[51] = {0, }, q[51][51] = {0, };
int A = 0, B = 0, score;
int f(int x, int y)
{
	for(int i = x; i<x+8; i++)
	{
		for(int j = y; j<y+8; j++)
		{
			if(q[i][j] != a[i-x][j-y]) A++;
			if(q[i][j] != b[i-x][j-y]) B++;
		}
	}
	if(A > B) return B;
	else return A;
}

int main()
{
	int m, n, min = 100000;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
	{
		scanf("%s", p);
		for(int j = 0; j<m; j++)
		{
			q[i][j] = p[j];
		}
	}
	/*
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			printf("%c ", q[i][j]);
		}
		printf("\n");
	}
	*/
	//보드판 
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(i%2 == 0)
			{
				if(j%2 == 0)
				{
					a[i][j] = 'W';
					b[i][j] = 'B';
				}
				else
				{
					a[i][j] = 'B';
					b[i][j] = 'W';
				}
			}
			else
			{
				if(j%2 != 0)
				{
					a[i][j] = 'W';
					b[i][j] = 'B';
				}
				else
				{
					a[i][j] = 'B';
					b[i][j] = 'W';
				}
			}
		}
	}
	
	//찐 코드 
	
	for(int i = 0; i<=n-7; i++)
	{
		for(int j = 0; j<=m-7; j++)
		{
			A = 0;
			B = 0;
			score = f(i, j);
			if(score < min) min = score;
		}
	}
	printf("%d", min);
	
	
	return 0;
}