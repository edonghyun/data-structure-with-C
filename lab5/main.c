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
				case 1: getElement(list); // List1 �� ���� �Է�
						system("PAUSE");
						break;
				case 2: getElement(list2); // List2 �� ���� �Է�
						system("PAUSE");
						break;
				case 3: if (!emptyList(list))  // Front ������ ���
							{
								dataPtr = front(list);
								printElement(dataPtr);
							}
						else
							{
								printf("����Ʈ�� ����ֽ��ϴ�.\n");
							}
						system("PAUSE");
						break;
				case 4: if (!emptyList(list)) // Back ������ ���
							{
								dataPtr = back(list);
								printElement(dataPtr);
							}
						else
							{
								printf("����Ʈ�� ����ֽ��ϴ�.\n");
							}
						system("PAUSE");
						break;
				case 5: printf("PushFront�� ������ �Է��ϼ���\n"); // PushFront
						dataPtr = (int*)malloc(sizeof(int));
						scanf_s("%d", dataPtr);
						pushFront(list, dataPtr);
						printf("%d�� �־����ϴ�\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 6: printf("PushBack�� ������ �Է��ϼ���\n"); // PushBack
						dataPtr = (int*)malloc(sizeof(int));
						scanf_s("%d", dataPtr);
						pushBack(list, dataPtr);
						printf("%d�� �־����ϴ�\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 7: if (emptyList(list))
						{
								printf("����Ʈ�� ����ֽ��ϴ�.\n"); break;
						}
						dataPtr = popFront(list); // popFront
						printf("FrontPop�� �������Դϴ�. -> %d\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 8: if (emptyList(list))
						{
								printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						dataPtr = popBack(list); // popBack
						printf("FrontBack�� �������Դϴ�. -> %d\n", *(int*)dataPtr);
						system("PAUSE");
						break;
				case 9: printf("���� ����Ʈ ������ ���� -> %d\n", list->count); // listCount
						system("PAUSE");
						break;
				case 10:if (emptyList(list))
							{
								printf("����Ʈ�� ����ֽ��ϴ�\n");
							}
						else
							{
								printf("����Ʈ�� ������� �ʽ��ϴ�\n");
							}
						system("PAUSE");
						break;
				case 11: printf("����Ʈ�� �߰��� ������ �Է��ϼ���\n");
							dataPtr = (int*)malloc(sizeof(int));
							scanf_s("%d", dataPtr);
							printf("���°�� �߰��Ͻðڽ��ϱ�?\n");
							scanf_s("%d", &c);
							if (c<1 || c> list->count)
							{
								printf("���� �߸��Է��ϼ̽��ϴ�.\n");
							}
							else
							{
								insert(list, c, dataPtr);
							}
							system("PAUSE");
							break;
				case 12:if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						printf("����Ʈ���� ���° �����͸� ����ðڽ��ϱ�?\n");
						scanf_s("%d", &c);
						if (c<1 || c> list->count)
						{
							printf("���� �߸��Է��ϼ̽��ϴ�.\n");
						}
						else
						{
							erase(list, c);
						}
						system("PAUSE");
						break;
				case 13: if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						printf("���� ���� ���� �Է��ϼ���.\n");
						scanf_s("%d", &a);
						removeElement(list, &a);
						system("PAUSE");
						break;
				case 14:if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						printf("�����͵� �� �ߺ��� ������ �����մϴ�.\n");
						list =Unique(list);
						system("PAUSE");
						break;
				case 15:if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						printf("����Ʈ �� �����͵��� ������ �������ϴ�.\n");
						list = Reverse(list);
						system("PAUSE");
						break;
				case 16:if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						printf("���°�� ���° �����͵��� �ٲٽðڽ��ϱ�?\n");
						scanf_s("%d %d", &c, &a);
						ExchCont(list, c, a);
						system("PAUSE");
						break;
				case 17: if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						 printf("list1�� list2�� ��Ĩ�ϴ�.�۾� �� list2�� ��Ե˴ϴ�.\n");
						MergeTwoList(list, list2);
						system("PAUSE");
						break;
				case 18: if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						 printf("����Ÿ�� �� 4�� ����ϴ�\n");
						Remove_If(list, removeCondition);
						system("PAUSE");
						break;
				case 19: if (emptyList(list))
						{
							printf("����Ʈ�� ����ֽ��ϴ�.\n"); system("PAUSE"); break;
						}
						 printf("�����͸� �����մϴ�.\n");
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
	}
	NODE* temp = list->head;

	int b = list->count;
	int i = 0;
	void* dataPtr = NULL;

	for (i = 0; i < b; i++)
	{
		dataPtr = (int*)temp->dataPtr;
		printf("���õ� ����Ʈ ������ �� %d��° -> %d\n", i + 1, *(int*)dataPtr);
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
	printf("�ش��ϴ� ��ȣ�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	printf("1.List1�� ���� �Է�\n");
	printf("2.List2�� ���� �Է�\n");
	printf("********�Ʒ��� List1�� �ش��ϴ� �۾��Դϴ�.*********\n");
	printf("3. Front ������ ���\n");
	printf("4. Back ������ ���\n");
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
	printf("���� ����մϴ�. -> %d\n", *(int*)data);
}