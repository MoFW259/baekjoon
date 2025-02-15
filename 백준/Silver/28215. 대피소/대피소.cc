#include<stdio.h>
 
int f(int x)
{
	if(x < 0) return -1*x;
	return x;
}

int main()
{
	int n, m, h[51][3] = {0, }, min = 100000000, max = -1, max1 = -1, max2 = -1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
	{
		scanf("%d %d", &h[i][1], &h[i][2]);
	}
	
	if(m == 1)
	{
		for(int i = 0; i<n; i++)
		{
			max = -1;
			for(int j = 0; j<n; j++)
			{
				if(j == i) continue;
				if(max < f(h[j][1] - h[i][1]) + f(h[j][2] - h[i][2])) max = f(h[j][1] - h[i][1]) + f(h[j][2] - h[i][2]);
			}
			if(max < min && max != -1) min = max;
		}
	}
	else if(m == 2)
	{
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				max = -1;
				for(int k = 0; k<n; k++)
				{
					if(i == j || j == k || i == k) continue;
					if(max < f(h[k][1] - h[i][1]) + f(h[k][2] - h[i][2])) max = f(h[k][1] - h[i][1]) + f(h[k][2] - h[i][2]);
					if(max > f(h[k][1] - h[j][1]) + f(h[k][2] - h[j][2])) max = f(h[k][1] - h[j][1]) + f(h[k][2] - h[j][2]); 
				}
				if(max < min && max != -1) min = max;
			}
		}
	}
	else
	{
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				for(int k = 0; k<n; k++)
				{
					max = -1;
					for(int l = 0; l<n; l++)
					{
						if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						if(max < f(h[l][1] - h[i][1]) + f(h[l][2] - h[i][2])) max = f(h[l][1] - h[i][1]) + f(h[l][2] - h[i][2]);
						if(max > f(h[l][1] - h[j][1]) + f(h[l][2] - h[j][2])) max = f(h[l][1] - h[j][1]) + f(h[l][2] - h[j][2]);
						if(max > f(h[l][1] - h[k][1]) + f(h[l][2] - h[k][2])) max = f(h[l][1] - h[k][1]) + f(h[l][2] - h[k][2]); 
					}
					if(max < min && max != -1) min = max;
				}
			}
		}
	}
	if(min == 100000000) printf("0");
	else printf("%d", min);
	
	return 0;
}