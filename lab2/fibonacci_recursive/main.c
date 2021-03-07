#include <stdio.h>

int Fib(int num);
int main(void)
{
	int a = 0;
	int b = 0;

	printf("피보나치 수열의 몇번째 항까지 출력하시겠습니까?\n");

	scanf_s("%d", &a);
		
	printf("/// 결과 값 ///\n", b);

	for ( b = 0 ; b <= a ; b++)
	{
		printf("%d번째 : %d \n", b, Fib(b));
	}

	return 0;
}

int Fib(int num)
{
	int result;

	if (num == 0 || num == 1)
	{
		return num;
	}

	else
	{
		result = Fib(num - 1) + Fib(num - 2);

		return result;
	}
}