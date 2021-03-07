#include <stdio.h>
#include <string.h>
#include "Function_a.h"
#include "Function_b.h"
#include "Function_c.h"

int main (void)
{
   int a=0;
   int b=0;
   int lrg =0;
   int c=0;
   char* A=0;

   char string1[100];
   char string2[100];
   

   printf("비교할 두 정수를 입력하시오\n"); 
   scanf_s("%d %d", &a,&b);getchar();
      
   lrg= *(int*)larger(&a,&b,int_compare);

   printf("Larger value is : %d\n",lrg); /// 결과값 출력
   
   fprintf(stdout,"문자열1을 입력하세요\n");
   
   fgets(string1,sizeof(string1),stdin);getchar();
   
   fprintf(stdout,"문자열2를 입력하세요\n");
   
   fgets(string2,sizeof(string2),stdin);getchar();
   
   A = (char*) larger(string1,string2,StrToCmpFun); /// 결과값 출력

   printf("Larger value is : ");

   while (A[c] != 0)
   {
      printf("%c",A[c]);
      c++;
   }

   printf("\n");
   return 0;


}



