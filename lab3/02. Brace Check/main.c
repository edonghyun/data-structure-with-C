#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "STACK_ADT.h"
#pragma warning(disable: 4996) 


const char closMiss[] = "Close paren missing at line";
const char openMiss[] = "Open paren missing at line";

int main(void)
{
	//Local Definitions

	STACK* stack1;
	STACK* stack2;
	STACK* stack3;

	char token;
	char* dataPtr;
	char fileID[25];
	FILE* fpIn;
	int lineCount = 1;

	//Statements
		//Create Stack

	stack1 = createSTack();
	stack2 = createSTack();
	stack3 = createSTack();

	printf("Enter file ID for file to be parsed: ");
	
	scanf_s("%s", fileID, sizeof(fileID));

	fpIn = fopen(fileID,"r");

	if (!fpIn )
		printf("Error opening %s\n", fileID);


	//read characters from the source code and parse

	while ((token = fgetc(fpIn)) != EOF)
	{
		if (token == '\n')
			lineCount++;
		if (token == '(')
		{
			dataPtr = (char*)malloc(sizeof(char));
			pushStack(stack1, dataPtr);
		}//if
		
		if (token == '[')
		{
			dataPtr = (char*)malloc(sizeof(char));
			pushStack(stack2, dataPtr);
		}//if
		
		if (token == '{')
		{
			dataPtr = (char*)malloc(sizeof(char));
			pushStack(stack3, dataPtr);
		}//if
		
		else
		{
			if (token == ')')
			{
				if (emptyStack(stack1))
				{
					printf("%s %d\n", openMiss, lineCount);
					system("pause");
					return 1;
				} // if true

				else
					popStack(stack1);
			} // token ==

			if (token == ']')
			{
				if (emptyStack(stack2))
				{
					printf("%s %d\n", openMiss, lineCount);
					system("pause");
					return 1;
				} // if true

				else
					popStack(stack2);
			} // token ==
			if (token == '}')
			{
				if (emptyStack(stack3))
				{
					printf("%s %d\n", openMiss, lineCount);
					system("pause");
					return 1;
				} // if true

				else
					popStack(stack3);
			} // token ==
		}//else
	}//while

	if (!emptyStack(stack1))
	{
		printf(" %s %d\n", closMiss, lineCount);
		system("pause");
		return 1;
	} //if
	if (!emptyStack(stack2))
	{
		printf(" %s %d\n", closMiss, lineCount);
		system("pause");
		return 1;
	} //if
	if (!emptyStack(stack3))
	{
		printf(" %s %d\n", closMiss, lineCount);
		system("pause");
		return 1;
	} //if


	//Now destroy the stack

	destroyStack(stack1);
	destroyStack(stack2);
	destroyStack(stack3);

	fclose(fpIn);

	printf("Parsing is OK: %d Lines parsed.\n", lineCount);

	system("pause");
	return 0;

}