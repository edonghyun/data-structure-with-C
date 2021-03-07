#include "queueADT.h"
#include "stackADT.h"

typedef struct
{
	int count;
	struct vertex* first;
	int(*compare)(void* argu1, void* argu2);
}GRAPH;

typedef struct vertex
{
	struct vertex* pNextVertex;
	void* dataPtr;
	int inDegree;
	int outDegree;
	short processed;
	struct arc* pArc;
}VERTEX;

typedef struct arc
{
	struct vertex* destination;
	int weight;
	struct arc* pNextArc;
}ARC;



GRAPH* graphCreate(int(*compare)(void* argu1, void* argu2));
GRAPH* graphDestroy(GRAPH* graph);

void graphInsVrtx(GRAPH* graph, void* dataInPtr);
int graphDltVrtx(GRAPH* graph, void* dltKey);

int graphInsArc(GRAPH* graph, void* pFromKey, void* pToKey, int weight);
int graphDltArc(GRAPH* graph, void* pFromKey, void* pToKey);

int graphRetrVrtx(GRAPH* graph, void* pKey, void** dDataOut);
int graphFrstArc(GRAPH* graph, void* pKey, void** pDataOut);

void graphDpthFrst(GRAPH* graph, void(*process)(void* dataPtr));
void graphBrdFrst(GRAPH* graph, void(*process)(void* dataPtr));

bool graphEmpty(GRAPH* graph);
bool graphFull(GRAPH* graph);
int graphCount(GRAPH* graph);

GRAPH* graphCreate(int(*compare)(void* argu1, void* argu2))
{
	GRAPH* pNew = (GRAPH*)malloc(sizeof(GRAPH));
	if (pNew)
	{
		pNew->compare = compare;
		pNew->count = 0;
		pNew->first = NULL;
		return pNew;
	}
	else
		return NULL;
}

void graphInsVrtx(GRAPH* graph, void* dataInPtr)
{
	//Local Definitions
	VERTEX* newPtr;
	VERTEX* locPtr;
	VERTEX* predPtr;

	newPtr = (VERTEX*)malloc(sizeof(VERTEX));
	if (newPtr)
	{
		newPtr->pNextVertex = NULL;
		newPtr->dataPtr = dataInPtr;
		newPtr->inDegree = 0;
		newPtr->outDegree = 0;
		newPtr->processed = 0;
		newPtr->pArc = NULL;
		(graph->count)++;
	}//if malloc
	else
		printf("overflow error 100 \a\n");

	//Now find insertion point

	locPtr = graph->first;
	if (!locPtr)//empty graph. Insert at beginning
	{
		graph->first = newPtr;
	}
	else
	{
		predPtr = NULL;
		while (locPtr && (graph->compare(dataInPtr, locPtr->dataPtr) > 0)) // 
		{
			predPtr = locPtr;
			locPtr = locPtr->pNextVertex;
		}//while
		if (!predPtr) // insert before first vertex
			graph->first = newPtr;
		else
			predPtr->pNextVertex = newPtr;
		newPtr->pNextVertex = locPtr;
	} // else
	return;
}// graphInsVtrx


int graphDltVrtx(GRAPH* graph, void* dltKey)
{
	//Local Definitions
	VERTEX* predPtr;
	VERTEX* walkPtr;

	//Statements

	if (!graph->first)
		return -2;

	//locate Vertex to be dl

	predPtr = NULL;
	walkPtr = graph->first;
	while (walkPtr && (graph->compare(dltKey, walkPtr->dataPtr) > 0))
	{
		predPtr = walkPtr;
		walkPtr = walkPtr->pNextVertex;
	}//walkPtr &&

	if (!walkPtr || graph->compare(dltKey, walkPtr->dataPtr) != 0)
	{
		return -2;
	}

	//Found vertex. Test degree
	if ((walkPtr->inDegree > 0) || (walkPtr->outDegree > 0))
	{
		return -1;
	}

	//OK to delete
	if (!predPtr)
	{
		graph->first = walkPtr->pNextVertex;
	}
	else
	{
		predPtr->pNextVertex = walkPtr->pNextVertex;
	}
	--graph->count;
	free(walkPtr);
	return 1;
}// graphDltVrtx


int graphInsArc(GRAPH* graph, void* pFromKey, void* pToKey, int weight)
{
	//Local Definitions
	ARC* newPtr;
	ARC* arcPredPtr;
	ARC* arcWalkPtr;
	VERTEX* vertFromPtr;
	VERTEX* vertToPtr;

	//Statements

	newPtr = (ARC*)malloc(sizeof(ARC));

	if (!newPtr)
		return -1;

	//Locate source vertex
	vertFromPtr = graph->first;
	while (vertFromPtr && (graph->compare(pFromKey, vertFromPtr->dataPtr) > 0))
	{
		vertFromPtr = vertFromPtr->pNextVertex;
	}

	if (!vertFromPtr || (graph->compare(pFromKey, vertFromPtr->dataPtr) != 0))
	{
		return (-2);
	}

	vertToPtr = graph->first;

	while (vertToPtr && graph->compare(pToKey, vertToPtr->dataPtr) > 0)
	{
		vertToPtr = vertToPtr->pNextVertex;
	}//while verToPtr &&

	if (!vertToPtr || (graph->compare(pToKey, vertToPtr->dataPtr) != 0))
	{
		return (-3);
	}

	//From and to vertices located. Insert new arc
	
	++(vertFromPtr->outDegree);
	++(vertToPtr->inDegree);
	newPtr->destination = vertToPtr;
	newPtr->weight;

	if (!vertFromPtr->pArc)
	{
		//Inserting first arc for this vertex
		vertFromPtr->pArc = newPtr;
		newPtr->pNextArc = NULL;
		return 1;
	}
	//find insertion point in adjacency arc list
	arcPredPtr = NULL;
	arcWalkPtr = vertFromPtr->pArc;
	while (arcWalkPtr || graph->compare(pToKey, arcWalkPtr->destination->dataPtr) >= 0)
	{
		arcPredPtr = arcWalkPtr;
		arcWalkPtr = arcWalkPtr->pNextArc;
	}//arcWalkPtr &&

	if (!arcPredPtr)
		vertFromPtr->pArc = newPtr;
	else
		arcPredPtr->pNextArc = newPtr;
	newPtr->pNextArc = arcWalkPtr;
	return 1;
}

int graphDltArc(GRAPH* graph, void* fromKey, void* toKey)
{
	//Local Definitions

	VERTEX* fromVertexPtr;
	VERTEX* toVertexPtr;
	ARC* preArcPtr;
	ARC* arcWalkPtr;

	//Statements
	if (!graph->first)
		return -2;

	//Locate source vertex
	fromVertexPtr = graph->first;
	while (fromVertexPtr && (graph->compare(fromKey, fromVertexPtr->dataPtr) > 0))
		fromVertexPtr = fromVertexPtr->pNextVertex;

	if (!fromVertexPtr || graph->compare(fromKey, fromVertexPtr->dataPtr) != 0)
		return -2;

	//Locate destination vertex in adjacency list

	if (!fromVertexPtr->pArc)
		return -3;

	preArcPtr = NULL;
	arcWalkPtr = fromVertexPtr->pArc;
	while (arcWalkPtr && (graph->compare(toKey, arcWalkPtr->destination) > 0))
	{
		preArcPtr = arcWalkPtr;
		arcWalkPtr = arcWalkPtr->pNextArc;
	}
	if (!arcWalkPtr || (graph->compare(toKey, arcWalkPtr->destination->dataPtr) != 0))
		return -3;
	toVertexPtr = arcWalkPtr->destination;

	--(fromVertexPtr->outDegree);
	--(toVertexPtr->inDegree);
	if (!preArcPtr)
		//Deleting first arc
		fromVertexPtr->pArc = arcWalkPtr->pNextArc;
	else
		preArcPtr->pNextArc = arcWalkPtr->pNextArc;
	free(arcWalkPtr);
	return 1;
}

bool graphEmpty(GRAPH* graph)
{
	if (graph->count == 0)
		return true;
	else
		return false;
}

bool graphFull(GRAPH* graph)
{
	GRAPH* test;

	test = (GRAPH*)malloc(sizeof(*(graph->first)));
	if (test)
	{
		free(test);
		return false;
	}
	else
		return true;
}

int graphCount(GRAPH* graph)
{
	if (!graph)
		return -1;
	else
		return graph->count;
}

int graphRetrVrtx(GRAPH* graph, void* pKey, void** dDataOut)
{
	VERTEX* predPtr;
	VERTEX* walkPtr;

	if (!graph->first)
		return -1;
	
	//locate Vertex to be dl

	predPtr = NULL;
	walkPtr = graph->first;
	
	while (walkPtr && (graph->compare(pKey, walkPtr->dataPtr) > 0))
	{
		predPtr = walkPtr;
		walkPtr = walkPtr->pNextVertex;
	}//walkPtr &&

	if (!walkPtr || graph->compare(pKey, walkPtr->dataPtr) != 0)
	{
		return -2;
	}

	//Found vertex. Test degree
	
	dDataOut = predPtr->dataPtr;

	return 1;
}

void graphDpthFrst(GRAPH* graph, void(*process)(void* dataPtr))
{
	bool success;
	VERTEX* walkPtr;
	VERTEX* vertexPtr;
	VERTEX* vertToPtr;
	STACK* stack;
	ARC* arcWalkPtr;

	//Statements
	if (!graph->first)
		return;

	//Set processed flags to not processed
	walkPtr = graph->first;
	while (walkPtr)
	{
		walkPtr->processed = 0;
		walkPtr = walkPtr->pNextVertex;
	}

	//Process each vertex in list
	stack = createSTack();
	walkPtr = graph->first;
	while (walkPtr)
	{
		if (walkPtr->processed < 2)
		{
			if (walkPtr->processed < 1)
			{
				//Push & set flag to pushed
				success = pushStack(stack, walkPtr);
				if (!success)
					printf("\aStack overflow 100\a\n");
				walkPtr->processed = 1;
			} // if processed <1
		} // if processed < 2
		//Process descendents of vertex at stacktop

		while (!emptyStack(stack))
		{
			vertexPtr = popStack(stack);
			process(vertexPtr->dataPtr);
			vertexPtr->processed = 2;

			//push all vertices from adjacency list
			arcWalkPtr = vertexPtr->pArc;
			while (arcWalkPtr)
			{
				vertToPtr = arcWalkPtr->destination;
				if (vertToPtr->processed == 0)
				{
					success = pushStack(stack, vertToPtr);
					if (!success)
						printf("\aStack overflow 101\n");
					vertToPtr->processed = 1;
				}//if vertToPtr
				arcWalkPtr = arcWalkPtr->pNextArc;
			}//while pWalkArc
		}//while !emptyStack
		walkPtr = walkPtr->pNextVertex;
	}//while walkPtr
	destroyStack(stack);
	return;
}//graphDpthFrst

void graphBrdFrst(GRAPH* graph, void(*process)(void* dataPtr))
{
	//Local Definitions
	bool success;
	VERTEX* walkPtr;
	VERTEX* vertexPtr;
	VERTEX* vertToPtr;
	QUEUE* queue;
	ARC* arcWalkPtr;

	//Statemnets
	if (!graph->first)
		return;

	//Set processed flags to not processed
	walkPtr = graph->first;
	while (walkPtr)
	{
		walkPtr->processed = 0;
		walkPtr = walkPtr->pNextVertex;
	}//while

	//Process each vertex in list
	queue = createQueue();
	walkPtr = graph->first;
	while (walkPtr)
	{
		if (walkPtr->processed < 2)
		{
			if (walkPtr->processed < 1)
			{
				//Enqueue & set flag to queue
				success = enqueue(queue, walkPtr);
				if (!success)
					printf("\aQueue overflow 100\n");
				walkPtr->processed = 1;
			}//if processed <1
		}//if processed < 2

		//process descendents of vertex at que front
		while (!emptyQueue(queue))
		{
			dequeue(queue, (void**)&vertexPtr);
			process(vertexPtr->dataPtr);
			vertexPtr->processed = 2;

			//Enqueue vertices form adjacency list
			arcWalkPtr = vertexPtr->pArc;
			while (arcWalkPtr)
			{
				vertToPtr = arcWalkPtr->destination;
				if (vertToPtr->processed == 0)
				{
					success = enqueue(queue, vertToPtr);
					if (!success)
						printf("\aQueue overflow 101\a\n");
					vertToPtr->processed = 1;
				}// if vertToPtr
				arcWalkPtr = arcWalkPtr->pNextArc;
			}//while pWalkArc
		}//while !emptyQueue
		walkPtr = walkPtr->pNextVertex;
	}//while walkPtr
	destroyQueue(queue);
	return;
}
