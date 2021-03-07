#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"


#define BUF_SZ 100
#define NUM_ASCII 256

int charFreq[NUM_ASCII]; // charFreq[97] = 10 the frequency of a
char *symCode[NUM_ASCII];

TreeNode **heap;
int lastHeapIdx = 0;
char codeBuf[100];
int codeBufIdx = -1;

/*--------------------------------------------------------------------------------*/

//
//Function Forward Declarations
//

int countNonZeroCharacters();
void performEncoding(char *fName);
void showCharFrequency(void);
void addToHeap(TreeNode* cur);
TreeNode* deleteFromHeap(void);
void traverse(TreeNode* cur, char c);

// argc : argument count
// ex, Huff.exe -e allice.txt -> argc==> 3 
// argv : argument varialbe
// argv[0] = "huff.exe", argv[1]="-e", argv[2]="alice.txt"

int main(int argc, char* argv[])
{
	char* fName = "Huffman.txt";
		//hoffman coding
		printf("Start Huffman Encoding\n");
		performEncoding(fName);

	system("PAUSE");

	return 0;	
}

void performEncoding(char *fName)
{
	// fopen, fread, fclose
	FILE *fin;
	char buf[BUF_SZ];

	fopen_s(&fin,fName, "rt");
	if (fin == 0)
	{
		printf("Unable to open %s, Program terminated.\n", fName);
		return;
	}

	// file read

	memset(charFreq, 0, NUM_ASCII * sizeof(int));

	while (fgets(buf, BUF_SZ, fin) != 0)
	{
		int len = strlen(buf);
		for (int i = 0; i < len; i++)
		{
			charFreq[(int)buf[i]] ++;
		}
	}

	fclose(fin);


	//showCharFrequency();

	//빈도수가 1이상인 것의 개수를 센다.
	int cnt = countNonZeroCharacters();
	
	heap = (TreeNode**)malloc((cnt + 1) * sizeof(TreeNode *));
	if (!heap)
	{
		printf("Fail to allocate memory, program terminated..\n");
	}
	memset(heap,0, (cnt + 1) * sizeof(TreeNode*));

	// Min heap을 구성한다.
	for (int i = 0; i < NUM_ASCII; i++)
	{
		if (charFreq[i] > 0)
		{
			TreeNode *cur = (TreeNode *) malloc(sizeof(TreeNode));
			if (!cur)
			{
				{
					printf("Fail to allocate memory, program terminated..\n");
				}
			}
			cur->data = (char)i;
			cur->frequency = charFreq[i];
			cur->left = cur->right = 0;
			addToHeap(cur);
		}
	}

	//TreeNode *temp = deleteFromHeap();
	//printf("previous root %d (%c) : %d\n", (int)temp->c, (char)temp->c, temp->frequency);
	//printf("root %d (%c) : %d\n", (int)heap[1]->c, (char)heap[1]->c, heap[1]->frequency);

	//Huffman tree를 구성
	
	TreeNode * first = 0;
	TreeNode * second = 0;

	while (1)
	{
		first = deleteFromHeap();
		second = deleteFromHeap();

		if (second == 0)
		{
			break;
		}

		TreeNode* newOne = (TreeNode*)malloc(sizeof(TreeNode));
		newOne->data = 0;
		newOne->frequency = (first->frequency) + (second->frequency);
		newOne->left = first;
		newOne->right = second;

		addToHeap(newOne);
	}
	// symCode 초기화
	memset(symCode, 0, sizeof(symCode));

	//first는 Huffman tree의 root노드를 가리킨다.
	traverse(first->left, '0');
	traverse(first->right, '1');

	int numOfSym = 0;

	for (int i = 0; i < NUM_ASCII; i++)
	{
		if (symCode[i] != 0)
		{
			numOfSym++;
			printf("Symbol %c --> %s\n", (char)i, symCode[i]);
		}
	}
	
	printf("Number of Symbols is %d\n", numOfSym);


	// 파일에 기록


	//1. 기록할 파일이름 만들기 alice.txt --> alice.encoded. 
	char outputFilename[100];
	char* period = strchr(fName, (int)'.'); // .을 가리킴
	strncpy(outputFilename, fName, (int)(period - fName)); // outputFilename = "alice" + result
	outputFilename[(int)(period - fName)] = 0; // 
	strcat(outputFilename,"_result.txt");

	printf("Output file name is : %s\n", outputFilename);

	printf("Start Encoding...\n");

	FILE* fout;
	fopen_s(&fout, outputFilename, "wt+");

	if (fout == 0)
	{
		printf(" Faile to encode\n");
	}

	fopen_s(&fin, fName, "rt");

	if (fin != 0)
	{
		while (fgets(buf, BUF_SZ, fin) != 0)
		{
			int len = strlen(buf);
			for (int i = 0; i < len; i++)
			{
				char* huffmanCode = symCode[(int)buf[i]];
				fputs(huffmanCode, fout);
				fputs(" ", fout);
			}
		}

		fclose(fin);
		fclose(fout);
	}
	else
	{
		printf("Unable to open the file %s\n", fName);
	}
	printf("Success!\n");
}

void traverse(TreeNode* cur, char c)
{
	codeBufIdx++;
	codeBuf[codeBufIdx] = c;
	codeBuf[codeBufIdx + 1] = 0;

	if (cur->left == 0 && cur->right == 0)
	{
		//printf("character %d (%c) : %s\n", (int)cur->c, cur->c, codeBuf);

		// symCode (cur->c) 허프만 코드 (codeBuf) 저장 

		char* hufCode = (char *)malloc(strlen(codeBuf) + 1); // null 때문에 +1
		strcpy_s(hufCode, strlen(codeBuf)+1, codeBuf); // 버프에서 허프코드로
		symCode[(int)cur->data] = hufCode;
	}
	else
	{
		traverse(cur->left, '0');
		traverse(cur->right, '1');
	}

	codeBuf[codeBufIdx] = 0;
	codeBufIdx--;
	return;
}

//
//heap의 root를 꺼낸다
//

TreeNode* deleteFromHeap(void)
{
	if (lastHeapIdx <= 0)
	{
		return 0;
	}
	TreeNode* retVal = heap[1];

	heap[1] = heap[lastHeapIdx];
	lastHeapIdx--;

	int parent = 1;
	int left = 2 * parent;
	int right = left + 1;

	while (1)
	{
		if (left > lastHeapIdx) // 자식 없음.
		{
			break;
		}
		else if (right > lastHeapIdx) // 왼쪽 자식만 가지고 있다.
		{
			if (heap[left]->frequency < heap[parent]->frequency)
			{
				TreeNode* temp = heap[left];
				heap[left] = heap[parent];
				heap[parent] = temp;

				parent = left;
				left = 2 * parent;
				right = left + 1;
			}
			else
			{
				break;
			}
		}
		else // 자식 둘
		{
			int smaller;
			if (heap[left]->frequency <= heap[right]->frequency)
			{
				smaller = left;
			}
			else
			{
				smaller = right;
			}
			
			if (heap[smaller]->frequency < heap[parent]->frequency)
			{
				TreeNode* temp = heap[smaller];
				heap[smaller] = heap[parent];
				heap[parent] = temp;

				parent = smaller;
				left = 2 * parent;
				right = left + 1;
			}
			else
			{
				break;
			}
		}
	}
	
	return retVal;

}

//
// heap에 새로운 노드 추가
//

void addToHeap(TreeNode* cur)
{
	lastHeapIdx++;
	heap[lastHeapIdx] = cur;

	int currentIdx = lastHeapIdx;
	int parentIdx = lastHeapIdx / 2;
	

	while (parentIdx >= 1)
	{
		if (heap[parentIdx]->frequency > heap[currentIdx]->frequency)
		{
			//부모와 나를 바꾼다.
			TreeNode* temp = heap[parentIdx];
			heap[parentIdx] = heap[currentIdx];
			heap[currentIdx] = temp;

			currentIdx = parentIdx;
			parentIdx = currentIdx / 2;
		}
		else
		{
			break;
		}
	}
}


//
// 출현 빈도수가 1 이상인 문자들의 총 개수를 센다.
//

int countNonZeroCharacters()
{
	int cnt = 0;
	for (int i = 0; i < NUM_ASCII; i++)
	{
		if (charFreq[i] > 0)
		{
			cnt++;
		}
	}
	return cnt;
}


void showCharFrequency(void)
{
	// charFreq
	for (int i = 0; i < NUM_ASCII; i++)
	{
		// 빈도수 1이상인 것만 출력
		if (charFreq[i] > 0)
		{
			printf("ASCII code %d ( %c ) : %d \n", i, (char)i, charFreq[i]);
		}
	}
}