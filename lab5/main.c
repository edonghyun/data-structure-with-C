#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "listADT.h"


void Index(void);
void printElement(void* data);
void getElement(LIST* list);
int removeCondition(void* argu1);
int compareInt (void* argu1, void* argu2);
void printList(LIST* list);

int main(void)
{
	bool done = false;
	int i = 0;
	int b = 0;
	int a = 0;
	int c = 0;

	int* dataPtr = NULL;

	LIST* list = createList((*compareInt));
	LIST* list2 = createList((*compareInt));

	NODE* temp = NULL;
	int opt = 0;

	while (1)
	{
		Index();
		scanf_s("%d", &opt);
		
		switch (opt) {
				case 1: getElement(list); // List1 에 정수 입력
						system("PAUSE");
						break;
				case 2: getElement(list2); // List2 에 정수 입력
						system("PAUSE");
						break;
				case 3: if (!emptyList(list))  // Front 데이터 출력
							{
								dataPtr = front(list);
								printElement(dataPtr);
							}
						else
							{
								printf("리스트가 비어있습니다.\n");
							}
						system("PAUSE");
						break;
				case 4: if (!emptyList(list)) // Back 데이터 출력
							{
								dataPtr = back(list);
								printElement(dataPtr);
							}
						else
							{
								printf("리스트가 비어있습니다.\n");
							}
						system("PAUSE");
						break;
				case 5: printf("PushFront할 정수를 입력하세요\n"); // PushFront
						dataPtr = (int*)malloc(sizeof(int));
						scanf_s("%d", dataPtr);
						pushFront(list, dataPtr);
						printf("%d를 넣었습니다\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 6: printf("PushBack할 정수를 입력하세요\n"); // PushBack
						dataPtr = (int*)malloc(sizeof(int));
						scanf_s("%d", dataPtr);
						pushBack(list, dataPtr);
						printf("%d를 넣었습니다\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 7: if (emptyList(list))
						{
								printf("리스트가 비어있습니다.\n"); break;
						}
						dataPtr = popFront(list); // popFront
						printf("FrontPop한 데이터입니다. -> %d\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 8: if (emptyList(list))
						{
								printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						dataPtr = popBack(list); // popBack
						printf("FrontBack한 데이터입니다. -> %d\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 9: printf("현재 리스트 데이터 개수 -> %d\n", list->count); // listCount
						system("PAUSE");
						break;
				case 10:if (emptyList(list))
							{
								printf("리스트가 비어있습니다\n");
							}
						else
							{
								printf("리스트가 비어있지 않습니다\n");
							}
						system("PAUSE");
						break;
				case 11: printf("리스트에 추가할 정수를 입력하세요\n");
							dataPtr = (int*)malloc(sizeof(int));
							scanf_s("%d", dataPtr);
							printf("몇번째에 추가하시겠습니까?\n");
							scanf_s("%d", &c);
							if (c<1 || c> list->count)
							{
								printf("값을 잘못입력하셨습니다.\n");
							}
							else
							{
								insert(list, c, dataPtr);
							}
							system("PAUSE");
							break;
				case 12:if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						printf("리스트에서 몇번째 데이터를 지우시겠습니까?\n");
						scanf_s("%d", &c);
						if (c<1 || c> list->count)
						{
							printf("값을 잘못입력하셨습니다.\n");
						}
						else
						{
							erase(list, c);
						}
						system("PAUSE");
						break;
				case 13: if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						printf("지울 정수 값을 입력하세요.\n");
						scanf_s("%d", &a);
						removeElement(list, &a);
						system("PAUSE");
						break;
				case 14:if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						printf("데이터들 중 중복된 값들을 정리합니다.\n");
						list =Unique(list);
						system("PAUSE");
						break;
				case 15:if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						printf("리스트 속 데이터들의 순서를 뒤집습니다.\n");
						list = Reverse(list);
						system("PAUSE");
						break;
				case 16:if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						printf("몇번째와 몇번째 데이터들을 바꾸시겠습니까?\n");
						scanf_s("%d %d", &c, &a);
						ExchCont(list, c, a);
						system("PAUSE");
						break;
				case 17: if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						 printf("list1과 list2를 합칩니다.작업 후 list2는 비게됩니다.\n");
						MergeTwoList(list, list2);
						system("PAUSE");
						break;
				case 18: if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						 printf("데이타들 중 4를 지웁니다\n");
						Remove_If(list, removeCondition);
						system("PAUSE");
						break;
				case 19: if (emptyList(list))
						{
							printf("리스트가 비어있습니다.\n"); system("PAUSE"); break;
						}
						 printf("데이터를 정렬합니다.\n");
						list = Sortlist(list);
						system("PAUSE");
						break;
				case 20: printList(list);
						system("PAUSE");
						break;
				case 21: printList(list2);
						system("PAUSE");
						break;
		}
			

	}


	return 0;
}

int compareInt(void* argu1, void* argu2) // Function -> (a,b)   a > b return 1, a = b return 0 , a < b return -1
{

	if (*(int*)argu1 > *(int*)argu2)
	{
		return +1;
	}

	if (*(int*)argu1 == *(int*)argu2)
	{
		return 0;
	}
	if (*(int*)argu1 < *(int*)argu2)
	{
		return -1;
	}
	
}

int removeCondition(void* argu1)
{
	int temp = *(int*)argu1;

	if (temp == 4)
		return 0;
	else
		return 1;
}

void printList(LIST* list)
{
	if (emptyList(list))
	{
		printf("리스트가 비어있습니다.\n");
	}
	NODE* temp = list->head;

	int b = list->count;
	int i = 0;
	void* dataPtr = NULL;

	for (i = 0; i < b; i++)
	{
		dataPtr = (int*)temp->dataPtr;
		printf("선택된 리스트 데이터 값 %d번째 -> %d\n", i + 1, *(int*)dataPtr);
		temp = temp->link;
	}
	printf("\n");
	printf("\n");
}// printList

void getElement(LIST* list)
{
	bool done = false;
	void* dataPtr = NULL;

	while (!done)
	{
		dataPtr = (int*)malloc(sizeof(int));
		printf("Enter a number to List from front: <EOF> to stop :");
		if ((scanf_s("%d", dataPtr)) == EOF || fullList(list))
			done = true;
		else
			pushFront(list, dataPtr);
	}
	return;
}

void Index()
{
	printf("***********************List ADT**********************\n");
	printf("해당하는 번호를 입력하시면 프로그램이 실행됩니다.\n");
	printf("1.List1에 정수 입력\n");
	printf("2.List2에 정수 입력\n");
	printf("********아래는 List1에 해당하는 작업입니다.*********\n");
	printf("3. Front 데이터 출력\n");
	printf("4. Back 데이터 출력\n");
	printf("5. PushFront\n");
	printf("6. pushBack\n");
	printf("7. popFront\n");
	printf("8. popBack\n");
	printf("9. listCount\n");
	printf("10. isEmptyList\n");
	printf("11. insert with specific position\n");
	printf("12. erase in specific position\n");
	printf("13. erase elements with specific value\n");
	printf("14. unique\n");
	printf("15. reverse\n");
	printf("16. exchange\n");
	printf("17. merge\n");
	printf("18. remove_if\n");
	printf("19. sort\n");
	printf("20. print the list1 elements\n");
	printf("21. print the list2 elements\n");
	printf("******************************************************\n");
	
	return;
}

void printElement(void* data)
{
	printf("값을 출력합니다. -> %d\n", *(int*)data);
}