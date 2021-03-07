#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "Circular_ADT.h"



int main(void)
{
	circularQueue_t REAL;
	circularQueue_t* real = &REAL;
	
	initializeQueue(real);
	
	int a = 5;
	int b = 0;
	int* q = &b;
	int size = 0;
	int i = 0;
	int* ptr = NULL;
	int stop = 0;

	for (i = 0; i < a-1; i++)
	{
		printf("값 입력?\n");
		scanf_s("%d", &b);
		
		q = (int*)malloc(sizeof(int));
		*q = b;

		putItem(real, q);
	}
	
	for (i = 0; i < a - 1; i++)
	{
		q = (int*)malloc(sizeof(int));
		q = (int*)real->data[i];
		printf("값 : %d\n", q);
	}

	q = QueueFront(real);  //// QueueFront Test.
	
	printf("값 : %d\n", q);

	scanf_s("%d", &stop);

	return 0;

}