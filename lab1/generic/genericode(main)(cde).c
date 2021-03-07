#include <stdio.h>
#include <malloc.h>
#include "a.h"

int main(void)
{
	void* newData1 = NULL;
	void* nodeData = NULL;

	NODE* node1 = NULL; // create node1 (c)
	NODE* node2 = NULL; // create node2 (d)

	newData1 = (int*)malloc(sizeof(int));
	*(int*)newData1 = 7;
		
	node1 = createNode(newData1); // input integer value

	newData1 = (float*)malloc(sizeof(float));
	*(float*)newData1 = 5.6;

	node2 = createNode(newData1); // input float value
	
	node1->link = node2; // link nodes c,d  ------------------------- Generic E

	/// Check the Result ///
		

	printf(" 历厘等 蔼 = %d\n", *(float*)node1->link);
	

	printf(" 历厘等 蔼 = %f\n", *(float*)node2->dataPtr);

	return 0;
}
