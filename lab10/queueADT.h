typedef struct node2
{
	void* dataPtr;
	struct node2* next;

}QUEUE_NODE;

typedef struct
{
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
}QUEUE;



QUEUE* createQueue(void);
QUEUE* destroyQueue(QUEUE* queue);

bool dequeue(QUEUE* queue, void ** itemPtr);
bool enqueue(QUEUE* queue, void* itemPtr);
bool queueFront(QUEUE* queue, void** itemPtr);
bool queueRear(QUEUE* queue, void** itemPtr);
int queueCount(QUEUE* queue);

bool emptyQueue(QUEUE* queue);
bool fullQueue(QUEUE* queue);

QUEUE* createQueue(void)
{
	QUEUE* queue;

	queue = (QUEUE*)malloc(sizeof(QUEUE));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;

	}// if
	return queue;
} // createQueue


bool enqueue(QUEUE* queue, void* itemPtr)
{
	QUEUE_NODE* newPtr;

	if (!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))))
		return false;

	newPtr->dataPtr = itemPtr;
	newPtr->next = NULL;

	if (queue->count == 0)
		//Inserting into null queue
		queue->front = newPtr;
	else
		queue->rear->next = newPtr;

	(queue->count)++;
	queue->rear = newPtr;
	return true;
} // enqueue

bool dequeue(QUEUE* queue, void** itemPtr)
{
	QUEUE_NODE* deleteLoc;

	if (!queue->count)
		return false;

	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;
	if (queue->count == 1)
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->next;
	(queue->count)--;
	free(deleteLoc);

	return true;
} // dequeue

bool queueFront(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return true;
	} // else
}//queueFront

bool queueRear(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)
		return false;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return false;
	}//else
}//queueRear

bool emptyQueue(QUEUE* queue)
{
	return (queue->count == 0);
}//emptyQueue

bool fullQueue(QUEUE* queue)
{
	QUEUE_NODE* temp;

	temp = (QUEUE_NODE*)malloc(sizeof(*(queue->rear)));
	if (temp)
	{
		free(temp);
		return true;
	}//if
	 // Heap full
	return false;

}//fullQueue

int queueCount(QUEUE* queue)
{
	return queue->count;
}//queueCount

QUEUE* destroyQueue(QUEUE* queue)
{
	QUEUE_NODE* deletePtr;

	if (queue)
	{
		while (queue->front != NULL)
		{
			free(queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->next;
			free(deletePtr);

		}// while
		free(queue);
	}//if
	return NULL;

}//destroyQueue