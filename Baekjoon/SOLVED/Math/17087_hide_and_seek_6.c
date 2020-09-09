#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}

int main(void)
{
	int N, S, i, res;
	int s[100000];

	scanf("%d %d", &N, &S);
	for (i = 0; i < N; i++)
		scanf("%d", &s[i]);
	
	for (i = 0; i < N; i++)
		s[i] = abs(S - s[i]);
	
	res = s[0];
	for (i = 1; i < N; i++)
		res = gcd(res, s[i]);
	
	printf("%d\n", res);
	return (0);
}
