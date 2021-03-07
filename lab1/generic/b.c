#include "a.h"

NODE* createNode(void* itemPtr)
{

	NODE* nodePtr= NULL;
	nodePtr= (NODE*)malloc(sizeof(NODE));
	nodePtr->dataPtr=itemPtr;
	nodePtr->link = NULL;
	return nodePtr;
} // createNode function with void pointer

