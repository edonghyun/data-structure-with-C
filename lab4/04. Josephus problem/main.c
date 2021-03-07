#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdbool.h>
#include "Circular.h"

int main(void)
{
	circularQueue_t Circle;
	circularQueue_t* circle = &Circle;
	circularQueue_t Result;
	circularQueue_t* result = &Result;

	initializeQueue(circle);
	initializeQueue(result);

	int n = 0;
	int i = 0;
	int a = 0;
	int judge = 0;
	int* ptr = NULL;
	int tempInt = 0;
	int temp = 0;
	int stop = 0;


	printf("Josuea Problem\n");
	printf("몇 명의 사람으로 원을 만드시겠습니까?\n n =? \n");
	scanf_s("%d", &n);

	printf("몇 번째 사람을 죽이시겠습니까?\n");
	scanf_s("%d", &a);

	printf("%d명의 사람과 함께 게임을 시작합니다\n1번부터 차례대로 %d번째 사람이 죽습니다\n", n, a);

	for (i = 1; i <= n; i++)
	{
		
		ptr = (int*)malloc(sizeof(int));
		ptr = &i;
		
		putItem(circle, ptr);

	}

	while (!isEmpty(circle))
	{

		for (i = 1; i < a; i++)
		{
			
			ptr = (int*)malloc(sizeof(int));
			*ptr = getItem(circle);

			putItem(circle, ptr);
		
		}


		*ptr = (int*) getItem(circle);


		putItem(result, ptr);

	}

	printQueue(result);

	printf("\n");
	printf("값을 입력하면 프로그램이 종료됩니다.");
	scanf_s("%d", &stop);


	return 0;

}