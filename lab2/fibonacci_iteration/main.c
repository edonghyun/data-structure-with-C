#include <stdio.h>

int main (void)

{

	int a = 0; // ù��° ����
	int b = 1; // �ι�° ����
	int c = 0;
	int d = 0;
	int temp = 0;
	int n= 0;

	printf("�Ǻ���ġ ���� : ���° �ױ��� ����Ͻðڽ��ϱ�?");
	scanf_s("%d",&n);

	printf("%d��° �� : %d\n",a+1,a);
	
	for ( d= 3 ; d <= n+1 ; d++)
	{
		c = a + b;
		printf("%d��° �� : %d\n",d-1, c);
		
		
		b= temp;
		
		b=a;

		a=c;
	}

	return 0;
}
