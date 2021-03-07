#define MAX_ITEMS    100
typedef struct circularQueue_s
{
	int     first;
	int     last;
	int     validItems;
	int     data[MAX_ITEMS];

} circularQueue_t;

void initializeQueue(circularQueue_t *theQueue);

int isEmpty(circularQueue_t *theQueue);

int putItem(circularQueue_t *theQueue, void** theItemValue);

void* getItem(circularQueue_t *theQueue);

void printQueue(circularQueue_t *theQueue);

bool destoryqueue(circularQueue_t *theQueue);

void* QueueFront(circularQueue_t *theQueue);

void initializeQueue(circularQueue_t *theQueue)
{
	int i;
	theQueue->validItems = 0;
	theQueue->first = 0;
	theQueue->last = 0;
	for (i = 0; i<MAX_ITEMS; i++)
	{
		theQueue->data[i] = 0;
	}
	return;
}
int isEmpty(circularQueue_t *theQueue)
{
	if (theQueue->validItems == 0)
		return(1);
	else
		return(0);
}

int putItem(circularQueue_t *theQueue, void** theItemValue)
{
	if (theQueue->validItems >= MAX_ITEMS)
	{
		printf("The queue is full\n");
		printf("You cannot add items\n");
		return(-1);
	}
	else
	{
		theQueue->validItems++;
		theQueue->data[theQueue->last] = *theItemValue;
		theQueue->last = (theQueue->last + 1) % MAX_ITEMS;
	}


}

void* getItem(circularQueue_t *theQueue)
{
	void* temp = NULL;

	if (isEmpty(theQueue))
	{
		printf("isempty\n");
		return(-1);
	}
	else
	{
		temp = theQueue->data[theQueue->first];
		theQueue->first = (theQueue->first + 1) % MAX_ITEMS;
		theQueue->validItems--;
		return temp;
	}
}


void printQueue(circularQueue_t *theQueue)
{
	int aux, aux1;
	aux = theQueue->first;
	aux1 = theQueue->validItems;
	while (aux1>0)
	{
		printf("Element #%d = %d\n", aux, (int*)theQueue->data[aux]);
		aux = (aux + 1) % MAX_ITEMS;
		aux1--;
	}
	return;
}

bool destoryqueue(circularQueue_t *theQueue)
{
	void* temp = NULL;
	void* temp2 = NULL;

	int count = theQueue->validItems;
	int i = 0;
	int number = theQueue->first;

	if (isEmpty(theQueue))
	{
		printf("isempty\n");
		return(-1);
	}

	else
	{
		for (i = 0; i < count; i++)
		{
			temp = theQueue->data[number++ % MAX_ITEMS];
			theQueue->validItems--;
			free(temp);

		}
		if (theQueue->validItems == 0)
		{
			free(theQueue);
			return true;
		}
	
	}
}

void* QueueFront(circularQueue_t *theQueue)
{
	void* temp = NULL;

	if (isEmpty(theQueue))
	{
		return false;
	}
	else
	{
		temp = theQueue->data[theQueue->first];
		return temp;
	}
}