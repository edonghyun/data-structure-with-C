#include <stdio.h>

int Fib(int num);
int main(void)
{
	int a = 0;
	int b = 0;

	printf("�Ǻ���ġ ������ ���° �ױ��� ����Ͻðڽ��ϱ�?\n");

	scanf_s("%d", &a);
		
	printf("/// ��� �� ///\n", b);

	for ( b = 0 ; b <= a ; b++)
	{
		printf("%d��° : %d \n", b, Fib(b));
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