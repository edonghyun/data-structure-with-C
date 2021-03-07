#include <stdio.h>


int BinX(int cnt, int Decimal , char* Arr);
int main(void)
{

	int num = 0; // 입력 받을 10진수 수
	char Binery[256]; // 변환될 이진법 수가 저장될 공간
	int p = 0; // 이진법 자리수
	int c = 0; // 출력용

	printf("2진수로 변환할 10진수 숫자를 입력하세요\n");
	scanf_s("%d", &num);

		
	p = BinX(p, num, Binery); // 변환된 이진수 Binery 입력 및 문자 갯수 
	
	printf("%d의 이진법 변환수는 ",num);

	for (c = 0; c <= p; c++) //  이진법 변환 수 출력
	{
		printf("%d", Binery[c]);
	
	}
	printf("\n");

	return 0 ;

}

int BinX(int cnt ,int Decimal, char* Arr)
{
		int J = 0;
		J = Decimal % 2;


	if (Decimal == 0)  // Base Case
	{
		Arr[cnt] = 0;

		return 0;
	}

	if (Decimal == 1 )
	{
		Arr[cnt] = 1;

		return 0;
	}
	////////General Case

	if( J == 0) // 짝수 대상 
		{
			Arr[cnt] = J;
			
			Decimal = Decimal / 2;
			
			cnt += BinX(cnt++, Decimal, Arr+1);	

			return cnt;
			
		}

	if (J == 1) // 홀수 대상
	{
		Arr[cnt] = J; 
		
		Decimal = (Decimal - 1) / 2;

		cnt += BinX(cnt++, Decimal, Arr+1);
		
		return cnt;

	}
	return cnt;
}