#include <stdio.h>

long long Fib(long long num, long long* Arr);
int main(void)
{
	long long a = 0;
	int b = 0;
	long long Arr[100];
	

	printf("�Ǻ���ġ ������ ���° �ױ��� ����Ͻðڽ��ϱ�?\n");

	scanf_s("%lld", &a);

	printf("/// ��� �� ///\n");

	for (b = 0; b < a; b++)
	{
		printf("%d��° : %lld \n", b+1, Fib(b, Arr));
	}

	return 0;
}

long long Fib(long long num, long long* Arr)
{
	long long result;

	if (num == 0 || num == 1)
	{
		Arr[num] = num;

		return num;
	}

	else
	{
		
		result = Fib(num - 1, Arr) + Arr[num - 2];

		Arr[num] = result;

		return result;
	}
}