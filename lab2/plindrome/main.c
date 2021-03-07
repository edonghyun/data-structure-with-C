#include <stdio.h>

int StrLen(char* A);
int Pal(int* a, int Len, char* B); // 참이면 1, 거짓 0

int main (void)
{
	char Word[256];
	int Len = 0;
	int a = 3;
	int b = 0;

	printf("Palindrome 여부를 판단할 단어를 입력하세요\n\n");
	printf("대문자와 소문자는 다른 글자로 간주합니다\n\n");
	scanf("%s",Word);
	
	Len = StrLen(Word);

	printf("\n입력한 단어의 길이 : %d\n\n",Len);

	b = Pal(&a, Len, Word);

	if( b == 0)
		printf("\n해당 단어는 Palindrome : True \n\n");

	if( b != 0)
		printf("해당 단어는 Palinwdrome : False \n\n");

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
	
	if ( Len%2 == 0 ) //짝수면
	{
		

		if(Len==2) // 베이스 케이스
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

		if(B[0]==B[Len-1]) // 제너럴 케이스
			{
				
				return 0;
			}
		else
			{
				
				return 3;
			}

		
	}

	else //홀수면
	{
		

		if(Len==2) // 베이스 케이스
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

		if(B[0]==B[Len-1]) // 제너럴 케이스
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

