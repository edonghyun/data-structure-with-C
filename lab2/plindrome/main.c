#include <stdio.h>

int StrLen(char* A);
int Pal(int* a, int Len, char* B); // ���̸� 1, ���� 0

int main (void)
{
	char Word[256];
	int Len = 0;
	int a = 3;
	int b = 0;

	printf("Palindrome ���θ� �Ǵ��� �ܾ �Է��ϼ���\n\n");
	printf("�빮�ڿ� �ҹ��ڴ� �ٸ� ���ڷ� �����մϴ�\n\n");
	scanf("%s",Word);
	
	Len = StrLen(Word);

	printf("\n�Է��� �ܾ��� ���� : %d\n\n",Len);

	b = Pal(&a, Len, Word);

	if( b == 0)
		printf("\n�ش� �ܾ�� Palindrome : True \n\n");

	if( b != 0)
		printf("�ش� �ܾ�� Palinwdrome : False \n\n");

	return 0;
}

int StrLen(char* A)
{
	
	int b = 0;
	
	if (A[1] == '\0')
	{
			return 1;}
	else
		{b =StrLen(A+1);
	return b+1;}
}


int Pal(int *a, int Len, char* B)
{
	
	if ( Len%2 == 0 ) //¦����
	{
		

		if(Len==2) // ���̽� ���̽�
			{
					if(B[0]==B[1])
						{
							return 0;
						}
					else
						{
							return 3;
						}
			}

		if(B[0]==B[Len-1]) // ���ʷ� ���̽�
			{
				
				return 0;
			}
		else
			{
				
				return 3;
			}

		
	}

	else //Ȧ����
	{
		

		if(Len==2) // ���̽� ���̽�
			{
					if(B[0]==B[2])
						{
							return 0;
						}
					else
						{
							return 3;
						}
			}

		if(B[0]==B[Len-1]) // ���ʷ� ���̽�
			{
			
				return 0;
			}
		else
			{
				
				return 3;
			}

	}
	
	*a += Pal(&a, Len - 2, B + 1);
	
	return 3;
}

