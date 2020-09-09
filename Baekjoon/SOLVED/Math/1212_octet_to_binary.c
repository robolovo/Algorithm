#include <stdio.h>
#include <string.h>

char cmp[8][4] = {"0", "001", "010", "011", "100", "101", "110", "111"};
char cmp2[8][4] = {"0", "1", "10", "11", "100", "101", "110", "111"};

int main(void)
{
	char octet[333335];
	int i, j, index;

	scanf("%s", octet);

	int len = strlen(octet);

	printf("%s", cmp2[octet[0] - '0']);

	for (i = 1; i < len; i++)
	{
		index = octet[i] - '0';
		printf("%s", cmp[index]);
	}

	printf("\n");
	return (0);
}
