#include <stdio.h>
typedef struct node{

	void* dataPtr;
	struct node*link;
}NODE; // node structure with void pointer

NODE* createNode (void* itemPtr);