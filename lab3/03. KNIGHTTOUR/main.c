#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STACK_ADT.h"

typedef struct
{
	int row;
	int col;
	int count;
	int wheretoback; // 

}INFO;

int board[30][30] = { 0 }; /// 보드 세팅
int getBSize(void);
int Wheretogo(STACK* stack, int boardsize, int(*ptr)[10]);
bool printBoard(STACK* stack, int boardsize);

int main(void)
{
	int wheretogo = 0; // 갈 수 있는 선택지
	int boardsize = 0; // 보드 사이즈
	int a = 0; // 프로세스 성공, 실패 판단용
	int i = 0;
	int b = 0;
	int(*ptr)[30] = board;
	int stop = 0;

	INFO present, *q; // 스택에 들어갈 정보
	q = &present;
	INFO* temp1 = NULL;
	INFO* temp2 = NULL;

	STACK* stack;
	STACK_NODE* test;
	stack = createSTack();
	boardsize = getBSize();
	
	printf("시작할 위치 (x,y)를 입력하세요\n");
	printf("x = ?");
	scanf_s("%d", &q->row);
	printf("y = ?");
	scanf_s("%d", &q->col);
	printf("\n");
	

	if (q->row > boardsize || q->col > boardsize)
	{
		printf("처음 시작 위치가 보드 크기 내에 없습니다. 프로그램을 종료합니다.\n");
		getchar();
		return 0;
	}

	printf("%d X %d 크기의 보드에서 \n(%d,%d)를 출발점으로 Night tour를 시작합니다.\n값에 따라 시간이 오래 걸릴 수 있으니 잠시만 기다려주세요\n\n", boardsize, boardsize, q->row, q->col);

					
	q->count = 1;   //출발 자리 입력 , 기본값
	q->wheretoback = 0;
	board[q->row][q->col] = 1;
	pushStack(stack, q);




	
	q = (INFO*)malloc(sizeof(INFO));
	if (!q)
	{
		printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
		scanf_s("%d", &stop);
		return 0;
	}
	
	
	q = (INFO*)stackTop(stack);



	while (q->count <= (boardsize * boardsize))
	{
		
		switch (Wheretogo(stack, boardsize, ptr))
		{
		
		case 1:
		{
			q = (INFO*)malloc(sizeof(INFO));
			if(!q)
			{
				printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
				scanf_s("%d", &stop);
				return 0;
			}
			q = (INFO*)popStack(stack);
			q->wheretoback = 1;
			pushStack(stack, q);


			temp1 = (INFO*)malloc(sizeof(INFO));
			if(!temp1)
			{
				printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
				scanf_s("%d", &stop);
				return 0;
			}
			temp1->row = q->row - 1;
			temp1->col = q->col - 2;
			temp1->count = q->count + 1;
			temp1->wheretoback = 0;
			ptr[temp1->row][temp1->col] = 1;

			pushStack(stack, temp1);
			break;
		}
		case 2:
		{
			q = (INFO*)malloc(sizeof(INFO));
			if (!q)
			{
				printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
				scanf_s("%d", &stop);
				return 0;
			}
			q = (INFO*)popStack(stack);
			q->wheretoback = 2;
			pushStack(stack, q);


			temp1 = (INFO*)malloc(sizeof(INFO));

			if (!temp1)
			{
				printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
				scanf_s("%d", &stop);
				return 0;
			}

			temp1->row = q->row + 1;
			temp1->col = q->col - 2;
			temp1->count = q->count + 1;
			temp1->wheretoback = 0;
			ptr[temp1->row][temp1->col] = 1;
			pushStack(stack, temp1);
			break;
		}
		case 3:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 3;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));

		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}

		temp1->row = q->row - 2;
		temp1->col = q->col - 1;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);
		break;
		}
		case 4:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 4;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));

		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;

		}

		temp1->row = q->row + 2;
		temp1->col = q->col - 1;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);
		break;
		}
		case 5:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 5;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));
		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}


		temp1->row = q->row - 2;
		temp1->col = q->col + 1;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);
		break;
		}
		case 6:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 6;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));

		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}

		temp1->row = q->row + 2;
		temp1->col = q->col + 1;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);
		break;
		}
		case 7:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 7;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));
		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		temp1->row = q->row - 1;
		temp1->col = q->col + 2;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);
		break;
		}
		case 8:
		{	q = (INFO*)malloc(sizeof(INFO));
		if (!q)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		q = (INFO*)popStack(stack);
		q->wheretoback = 8;
		pushStack(stack, q);


		temp1 = (INFO*)malloc(sizeof(INFO));
		if (!temp1)
		{
			printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}
		temp1->row = q->row + 1;
		temp1->col = q->col + 2;
		temp1->count = q->count + 1;
		temp1->wheretoback = 0;
		ptr[temp1->row][temp1->col] = 1;
		pushStack(stack, temp1);

		break;
		}
		case 9:
		{
			q = (INFO*)malloc(sizeof(INFO));
			if (!q)
			{
				printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
				scanf_s("%d", &stop);
				return 0;
			}
			q = (INFO*)popStack(stack);
			q->wheretoback += 1 ;
			pushStack(stack, q);

			break;
		}

		}// switch

		if (temp1->count == boardsize*boardsize) // 만족하는 결과값 출력.
		{
			a = printBoard(stack, boardsize);
			printf("\n 프로그램을 종료합니다.\n");
			scanf_s("%d", &stop);
			return 0;
		}

		if (Wheretogo(stack, boardsize, ptr) == 9 || Wheretogo(stack, boardsize, ptr) == 0)
		{
				temp1 = (INFO*)malloc(sizeof(INFO));
				if (!temp1)
				{
					printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
					scanf_s("%d", &stop);
					return 0;
				}

				temp1 = (INFO*)popStack(stack);
				board[temp1->row][temp1->col] = 0;


				temp2 = (INFO*)malloc(sizeof(INFO));
				if (!temp2)
				{
					printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
					scanf_s("%d", &stop);
					return 0;
				}

				temp2 = (INFO*)popStack(stack);
				if (temp2 == NULL)
				{
					printf("만족하는 경로를 찾지 못했습니다. 값을 입력하시면 프로그램이 종료됩니다\n");
					scanf_s("%d", &stop);
				
					return 0;
				}

				b = stack->count;
				pushStack(stack, temp2);
			}


			q = (INFO*)stackTop(stack); // 최신화
		}// while 
		a = printBoard(stack, boardsize);
		printf("끝\n");
		scanf_s("%d", &stop);
		
		return 0;
}

int getBSize(void)
{
	int boardsize = 0;
	printf("NIght Tour..\n");
	printf("체스판에서 나이트가 모든 체스판을 다 지날 수 있는 경로가 있을 때,\n");
	printf("나이트가 지나는 그 경로를 출력합니다.\n");
	printf("nxn 보드 사이즈를 입력하세요\nn = ? ");

	scanf_s("%d", &boardsize);

	return boardsize;

} // boardsize

int Wheretogo(STACK* stack, int boardsize, int(*ptr)[30])
{
	INFO* info = NULL;
	int stop = 0;
	info = (INFO*)malloc(sizeof(INFO));
	if (!info)
	{
		printf("동적 할당 실패! 시스템 메모리가 부족합니다. 프로그램을 종료합니다.\n");
		scanf_s("%d", &stop);
		return 0;
	}
	
	if (!info)
	{
		printf("동적 할당 실패!");
		scanf_s("%d", &stop);
		return false;
	}

	info = stackTop(stack);  // info -> 이전 위치에 대한 정보
	if (stackTop == NULL)
		return false;

	int x = info->row; // ( x, y) 현재 위치
	int y = info->col;


	
	if (((boardsize >= (x - 1)) && ((x - 1) >= 1)) && ((boardsize >= (y - 2)) && ((y - 2) >= 1)))  //1
	{
		if ((info->wheretoback < 1) && (ptr[x - 1][y - 2] == 0))
		{
			
			return 1;
		}
	}
	if ((1 <= (x + 1)) && ((x + 1) <= boardsize) && (boardsize >= (y - 2)) && ((y - 2) >= 1))  //2
	{
		if ((info->wheretoback < 2) && (ptr[x + 1][y - 2] == 0))
		{
			
			return 2;

		}
	}
	if ((boardsize >= (x - 2)) && ((x - 2) >= 1) && (boardsize >= (y - 1)) && ((y - 1) >= 1))  //3
	{
		if ((info->wheretoback < 3) && (ptr[x - 2][y - 1] == 0))
		{
			
			return 3;
		}
	}
	if ((1 <= (x + 2)) && ((x + 2) <= boardsize) && (boardsize >= (y - 1)) && (1 <= y - 1))  //4
	{
		if ((info->wheretoback < 4) && (ptr[x + 2][y - 1] == 0))
		{
			
			return 4;
		}
	}
	if ((boardsize >= (x - 2)) && ((x - 2) >= 1) && (1 <= (y + 1)) && ((y + 1) <= boardsize))  //5
	{
		if ((info->wheretoback < 5) && (ptr[x - 2][y + 1] == 0))
		{
			
			return 5;
		}
	}
	if ((1 <= (x + 2)) && ((x + 2) <= boardsize) && (1 <= (y + 1)) && ((y + 1) <= boardsize))  //6
	{
		if ((info->wheretoback < 6) && (ptr[x + 2][y + 1] == 0))
		{
			
			return 6;
		}
	}
	if ((boardsize >= (x - 1)) && ((x - 1) >= 1) && (1 <= (y + 2)) && ((y + 2) <= boardsize))  //7
	{
		if ((info->wheretoback < 7) && (ptr[x - 1][y + 2] == 0))
		{
			
			return 7;
		}
	}
	if ((1 <= (x + 1)) && ((x + 1) <= boardsize) && (1 <= (y + 2)) && ((y + 2 <= boardsize))) //8
	{
		if ((info->wheretoback < 8) && (ptr[x + 1][y + 2] == 0))
		{
			
			return 8;
		}
	}
	else
	{
		
		return 9; // 갈 곳이 없어요
	}
	return 9;
}

bool printBoard(STACK* stack, int boardsize)
{
	int board[30][30] = { 0 }; // 보드 세팅
	int x = 0;
	int y = 0;//자리
	int i = 0;
	int p = 0;
	int stop = 0;

	INFO* dataPtr = NULL;
	

	while (!emptyStack(stack))
	{

		dataPtr = (INFO*)popStack(stack);
		

		x = dataPtr->row;
		y = dataPtr->col;

		board[x][y] = dataPtr->count;

	} 

	printf("만족하는 경로를 찾았습니다. 결과 값 출력입니다.\n\n");

	for (i = 1; i <= boardsize; i++)
	{
		for (p = 1; p <= boardsize; p++)
		{
			printf("%2d  |", board[i][p]);
		}
		printf("\n");
	
	}
	printf("\n");
	printf("값을 입력하시면 프로그램이 종료됩니다..\n\n ");
	scanf_s("%d", &stop);
	return true;
}
