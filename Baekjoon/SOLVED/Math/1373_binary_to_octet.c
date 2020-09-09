#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char binary[1000000];
	int octet;
	int first = 0, middle = 1, last = 2, len;

	scanf("%s", binary);
	
	len = strlen(binary);
	
	if ((len % 3) == 2)
	{
		octet = 0;
		octet += binary[0] == '1' ? 2 : 0;
		octet += binary[1] == '1' ? 1 : 0;

		printf("%d", octet);

		first = 2;
		middle = 3;
		last = 4;
	}	
	else if ((len % 3) == 1)
	{
		octet = 0;
		octet += binary[0] == '1' ? 1 : 0;

		printf("%d", octet);

		first = 1;
		middle = 2;
		last = 3;
	}
	while (last < len)
	{
		octet = 0;	
		octet += binary[first] == '1' ? 4 : 0;
		octet += binary[middle] == '1' ? 2 : 0;
		octet += binary[last] == '1' ? 1 : 0;
			
		printf("%d", octet);
		
		first += 3;
		middle += 3;
		last += 3;
	}
	printf("\n");
	return (0);
}
