#include<stdio.h>
int main()
{
	int n;
	// a 거리, b 가격 
	long long int a[100005] = {0, }, b[100005] = {0, }, cost = 0, min = 1000000010;
	scanf("%d", &n);
	for(int i = 0; i<n-1; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &b[i]);
	}
	for(int i = 0; i<n-1; i++)
	{
		if(b[i] < min)
		{
			min = b[i];
		}
		cost += min*a[i];
	}
	printf("%d", cost);
	
	return 0;
}