#include <stdio.h>


int BinX(int cnt, int Decimal , char* Arr);
int main(void)
{

	int num = 0; // �Է� ���� 10���� ��
	char Binery[256]; // ��ȯ�� ������ ���� ����� ����
	int p = 0; // ������ �ڸ���
	int c = 0; // ��¿�

	printf("2������ ��ȯ�� 10���� ���ڸ� �Է��ϼ���\n");
	scanf_s("%d", &num);

		
	p = BinX(p, num, Binery); // ��ȯ�� ������ Binery �Է� �� ���� ���� 
	
	printf("%d�� ������ ��ȯ���� ",num);

	for (c = 0; c <= p; c++) //  ������ ��ȯ �� ���
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

	if( J == 0) // ¦�� ��� 
		{
			Arr[cnt] = J;
			
			Decimal = Decimal / 2;
			
			cnt += BinX(cnt++, Decimal, Arr+1);	

			return cnt;
			
		}

	if (J == 1) // Ȧ�� ���
	{
		Arr[cnt] = J; 
		
		Decimal = (Decimal - 1) / 2;

		cnt += BinX(cnt++, Decimal, Arr+1);
		
		return cnt;

	}
	return cnt;
}