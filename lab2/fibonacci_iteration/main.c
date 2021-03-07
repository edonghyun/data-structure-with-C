#include <stdio.h>

int main (void)

{

	int a = 0; // 첫번째 숫자
	int b = 1; // 두번째 숫자
	int c = 0;
	int d = 0;
	int temp = 0;
	int n= 0;

	printf("피보나치 수열 : 몇번째 항까지 출력하시겠습니까?");
	scanf_s("%d",&n);

	printf("%d번째 수 : %d\n",a+1,a);
	
	for ( d= 3 ; d <= n+1 ; d++)
	{
		c = a + b;
		printf("%d번째 수 : %d\n",d-1, c);
		
		
		b= temp;
		
		b=a;

		a=c;
	}

	return 0;
}
