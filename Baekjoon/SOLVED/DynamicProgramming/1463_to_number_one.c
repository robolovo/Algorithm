#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MIN3(a, b, c) (((MIN(a, b)) < (c)) ? (MIN(a, b)) : (c))

int main(void)
{
	int X, a, b, c;
	int m[1000001];

	scanf("%d", &X);
	
	m[1] = 0;

	for (int i = 2; i <= X; i++)
	{
		a = b = c = 999999;

		if (i % 3 == 0)
			a = m[i / 3];	
		if (i % 2 == 0)
			b = m[i / 2];
		c = m[i - 1];
		m[i] = MIN3(a, b, c) + 1;	
	}
	printf("%d\n", m[X]);
	return (0);
}
