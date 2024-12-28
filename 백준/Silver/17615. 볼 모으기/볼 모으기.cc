#include<stdio.h>
int main()
{
	int N, f = 0, count = 0, c, x;
	char a[500005] = {0, };
	scanf("%d", &N);
	scanf("%s", a);
	for(int i = N-1; i>=0; i--)
	{
		if(f == 0)
		{
			if(a[i] != a[N-1])
			{
				f = 1;
				c = i;
			}
		}
		else
		{
			if(a[i] == a[N-1])
			{
				f = 0;
				count++;
				x = a[i];
				a[i] = a[c];
				a[c] = a[i];
				i = c-1;
			}
		}
	}
	printf("%d", count);
	
	return 0;
}
