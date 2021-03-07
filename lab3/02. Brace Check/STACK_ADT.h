//Stack ADT Type Definitions
typedef struct node
{
	void* dataPtr;
	struct node* link;

}STACK_NODE;

typedef struct
{
	int count;
	STACK_NODE* top;
}STACK;




STACK* createSTack(void)
{
	// Local Definitions
	STACK* stack;

	//Statements

	stack = (STACK*)malloc(sizeof(STACK));
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	} // if 

	return stack;

} // createStack




// stackCount
int stackCount(STACK* stack)
{
	return stack->count;
} // stackCount




bool fullStack(STACK* stack)
{
	STACK_NODE* temp;

	//Statements
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top)))))
	{
		free(temp);
		return false;
	}//if

	 //malloc failled

	return true;
}  // Full Stack





void* stackTop(STACK* stack)
{
	//Statemnets

	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;

} //stackTop






bool CatStack(STACK* stack1, STACK* stack2)
{
	STACK_NODE* temp = stack1->top;

	int a = 0;

	for (a = stackCount(stack1) - 1; a>0; a--)
	{
		temp = temp->link;
	}

	temp->link = stack2->top;

	stack1->count = stackCount(stack1) + stackCount(stack2);

	free(stack2); // stack2 헤드 해제	

	return true;

} // concarternate two Stacks





STACK* destroyStack(STACK* stack)
{

	//Local Definitions
	STACK_NODE* temp;

	// STtatements
	if (stack)
	{
		// Delete all nodes in stack
		while ((stack->top) != NULL)
		{
			//Delete data entry

			free(stack->top->dataPtr);

			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}//while

		 //Stack now empty. Destroy stack head node.
		free(stack);
	} //if stack

	return NULL;
}





void* popStack(STACK* stack)
{
	//Local Definitions
	void* dataOutPtr;
	STACK_NODE* temp;

	//Statements
	if (stack->count == 0)
		dataOutPtr = NULL;
	else
	{
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;

	} //else
	return dataOutPtr;
}







bool pushStack(STACK* stack, void* dataInPtr)
{

	// Local Definitions 
	STACK_NODE* newPtr;

	// Statements

	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newPtr)
	{
		return false;
	}
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;
	return true;

} // pushStack


bool emptyStack(STACK* stack)
{
	return (stack->count == 0);

} // Empty Stack