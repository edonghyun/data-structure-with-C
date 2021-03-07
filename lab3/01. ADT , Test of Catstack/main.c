#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "STACK_ADT.h"

int main(void)
{
	bool done = false;
	int* dataPtr; 
	int stop = 0;

	STACK* stack1;
	STACK* stack2;


	stack1 = createSTack();
	stack2 = createSTack();

	printf("스택 2개를 합칩니다. 값을 입력하세요\n");
	printf("입력을 완료하시면 Ctrl+z 를 입력하시면 됩니다.\n");

	while (!done)
	{
		dataPtr = (int*)malloc(sizeof(int));
		printf("Enter a number to Stack1: <EOF> to stop :");
		if ((scanf_s("%d", dataPtr)) == EOF || fullStack(stack1))
			done = true;
		else
			pushStack(stack1, dataPtr);
	}
	done = false;
	while (!done)
	{
		dataPtr = (int*)malloc(sizeof(int));
		printf("Enter a number to Stack2 : <EOF> to stop :");
		if ((scanf_s("%d", dataPtr)) == EOF || fullStack(stack2))
			done = true;
		else
			pushStack(stack2, dataPtr);
	}
	
	CatStack(stack1, stack2);

	printf("\n The list of numbers reversed with Stack1, Stack2\n");
		while (!emptyStack(stack1))
		{
			dataPtr = (int*)popStack(stack1);
			printf("%3d\n", *dataPtr);
			free(dataPtr);
		}
		
		destroyStack(stack1);
		scanf_s("%d", &stop);
		return 0;
}