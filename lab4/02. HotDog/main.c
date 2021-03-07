#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "Queue.h"


int main(void)
{

	QUEUE Line1;
	QUEUE* line1 = &Line1;
	
	QUEUE Line2;
	QUEUE* line2 = &Line2;

	QUEUE_NODE* TEMP = NULL;

	int peoNum = 0;
	int patience = 0;
	int* ptr = &patience;
	int i = 0;
	int HotSell = 0;
	int count = 0;
	int who = 0;
	int value = 0;
	int stop = 0;

	printf("손님 수를 입력하세요 \n");
	scanf_s("%d", &peoNum);

	line1 = createQueue(); // 큐 생성 원래
	line2 = createQueue(); // 큐 생성
	
	for (i = 1; i <= peoNum; i++)
	{
		printf("%d번째 손님의 인내심 ?", i);
		
		scanf_s("%d", &patience);

		enqueue(line1, patience);

	}

	count = line1->count;
	TEMP = line1->front;

	while (!emptyQueue(line1) || !emptyQueue(line2)) // 
	{
		if (!emptyQueue(line1))
		{
			dequeue(line1, (void*)ptr);//첫번째 손님
	
			HotSell++;


			while (!emptyQueue(line1))
			{
				dequeue(line1, (void*)ptr);
				value = *ptr;
				
				if (value == 0)
				{
					continue;
				}
				else
				{
					enqueue(line2, *ptr);
				}
			}//while patience 0 아닌 사람 옮기기
		
			//////////////////////////////////////////// -1 줄이기
			count = line2->count;
			TEMP = line2->front;

			for (i = 1; i <= count; i++)
			{
				dequeue(line2, (void*)ptr);
				*(int*)ptr -= 1;
				enqueue(line2, *ptr);
			}
	
		}
		else if (!emptyQueue(line2))//////////////////////////////
		{
			if (!emptyQueue(line2))
			{
				dequeue(line2, (void*)ptr);//첫번째 손님

				HotSell++;

				while (!emptyQueue(line2))
				{
					dequeue(line2, (void*)ptr);
					value = *ptr;

					if (value == 0)
					{
						continue;
					}
					else
					{
						enqueue(line1, *ptr);
					}

				}//while patience 0 아닌 사람 옮기기

				 //////////////////////////////////////////// -1 줄이기
				count = line1->count;
				TEMP = line1->front;

				for (i = 1; i <= count; i++)
				{
					dequeue(line1, (void*)ptr);

					*(int*)ptr -= 1;

					enqueue(line1, *ptr);

				}
			}


		}

	}//while

		
	printf("I sell %d hotdogs\n", HotSell);
	printf("값을 입력하시면 프로그램이 종료됩니다.");
	scanf_s("%d", &stop);
	
	return 0;
}


