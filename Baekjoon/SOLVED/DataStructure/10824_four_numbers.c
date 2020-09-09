#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char numA[16];
	char numB[8];
	char numC[16];
	char numD[8];
	long long resA, resB;

	scanf("%s %s %s %s", numA, numB, numC, numD);

	strcat(numA, numB);
	strcat(numC, numD);

	resA = atoll(numA);
	resB = atoll(numC);

	printf("%lld\n", resA + resB);
	return (0);
}
