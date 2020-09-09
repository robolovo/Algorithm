#include <stdio.h>

int main(void)
{
	int N;
	int res;

	scanf("%d", &N);
	
	res = N / 5;
	if (N >= 25)
		res += N / 25;
	if (N >= 125)
		res += N / 125;
	printf("%d\n", res);
	return (0);
}
