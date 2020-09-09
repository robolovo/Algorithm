#include <stdio.h>

//*******************************************//
// 최대공배수 공식                           //					
//                                           //
// a,b : 최소공배수를 구하고자 하는 두 수    //
// gcd(a,b) : a와b의 최대공약수              //
// (최소공배수 * 최대공약수 = a * b)를 이용  //
// 식 : a * b / gcd(a,b)                     //
//*******************************************//

int		gcd(int a, int b)
{
	int r;

	while (1)
	{
		if (b == 0)
			break;
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b));
}

int main(void)
{
	int T, i, num1, num2, min;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &num1, &num2);

		min = lcm(num1, num2);
		printf("%d\n", min);
	}
	return (0);
}
