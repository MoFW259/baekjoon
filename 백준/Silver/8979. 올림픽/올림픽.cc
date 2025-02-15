#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct medal
{
	int c;
	int m1;
	int m2;
	int m3;
	int s;
}medal;

bool com(medal asdf, medal b)
{
	if(asdf.m1 == b.m1)
	{
		if(asdf.m2 == b.m2)
		{
			return asdf.m3 > b.m3;
		}
		else return asdf.m2 > b.m2;
	}
	else return asdf.m1 > b.m1;
}

int main()
{
	medal a[1005] = {0, };
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++)
	{
		scanf("%d %d %d %d", &a[i].c, &a[i].m1, &a[i].m2, &a[i].m3);
	}
	sort(a, a + n, com);
	
	for(int i = 0; i<n; i++)
	{
		if(a[i].c == k) printf("%d", i+1);
	}
	
	return 0;
}