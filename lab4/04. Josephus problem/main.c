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
	printf("�� ���� ������� ���� ����ðڽ��ϱ�?\n n =? \n");
	scanf_s("%d", &n);

	printf("�� ��° ����� ���̽ðڽ��ϱ�?\n");
	scanf_s("%d", &a);

	printf("%d���� ����� �Բ� ������ �����մϴ�\n1������ ���ʴ�� %d��° ����� �׽��ϴ�\n", n, a);

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
	printf("���� �Է��ϸ� ���α׷��� ����˴ϴ�.");
	scanf_s("%d", &stop);


	return 0;

}