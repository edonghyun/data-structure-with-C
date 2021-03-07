typedef struct
{
	void** heapAry;
	int last;
	int size;
	int(*compare)(void* argu1, void* argu2);
	int maxSize;
}HEAP;

//Prototype Definitions

HEAP* heapCreate(int maxsize, int(*compare)(void* argu1, void* argu2));
bool heapInsert(HEAP* heap, void* dataPtr);
bool heapDelete(HEAP* heap, void** dataOutPtr);
int heapCount(HEAP* heap);
bool heapFull(HEAP* heap);
bool heapEmpty(HEAP* heap);
void heapDestroy(HEAP* heap);
void heapPrint(HEAP* heap);

static void _reheapUp(HEAP* heap, int childLoc);
static void _reheapDown(HEAP* heap, int root);


HEAP* heapCreate(int maxSize, int(*compare)(void* argu1, void* argu2))
{
	//Local Definitions
	HEAP* heap;

	//Statements
	heap = (HEAP*)malloc(sizeof(HEAP));
	if (!heap)
		return NULL;

	heap->last = -1;
	heap->compare = compare;
	heap->size = 0;

	//Force heap size to power of 2 -1
	heap->maxSize = (int) pow (2, ceil(log2(maxSize))) - 1;
	heap->heapAry = (void*)calloc(heap->maxSize, sizeof(void*));
	return heap;
}

bool heapInsert(HEAP* heap, void* dataPtr)
{
	//Statements
	
	if (heap->size >= heap->maxSize)
	{
		return false;
	}
		
	
	++(heap->last);
	++(heap->size);
	printf("SIze °ª %d\n", heap->size);
	printf("Last °ª %d\n", heap->last);
	heap->heapAry[heap->last] = dataPtr;
	_reheapUp(heap, heap->last);
	return true;
}

void _reheapUp(HEAP* heap, int childLoc)
{
	//Local Definitions
	int parent;
	void** heapAry;
	void* hold;

	//Statements
	//if not at root of heap -- index 0 
	if (childLoc)
	{
		heapAry = heap->heapAry;
		parent = (childLoc - 1) / 2;
		if (heap->compare(heapAry[childLoc], heapAry[parent]) > 0)
			//child is greater than parent -- swap
		{
			hold = heapAry[parent];
			heapAry[parent] = heapAry[childLoc];
			heapAry[childLoc] = hold;
			_reheapUp(heap, parent);
		}//if heap[]
	}//if newNode
	return;
}

bool heapDelete(HEAP* heap, void** dataOutPtr)
{
	//Statemnts
	if (heap->size == 0) // heap empty
		return false;

	*dataOutPtr = heap->heapAry[0];
	heap->heapAry[0] = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	_reheapDown(heap, 0);
	return true;
}

void _reheapDown(HEAP* heap, int root)
{
	//Local Definitions
	void* hold;
	void* leftData;
	void* rightData;
	int largeLoc;
	int last;

	//Statements

	last = heap->last;
	if ((root * 2 + 1) <= last) // left subtree
		//There is at least one child
	{
		leftData = heap->heapAry[root * 2 + 1];
		if ((root * 2 + 2) <= last) // right subtree
			rightData = heap->heapAry[root * 2 + 1];
		else
			rightData = NULL;

		if ((!rightData) || heap->compare(leftData, rightData) > 0)
		{
			largeLoc = root * 2 + 1; // if no right Key or leftKey greater
		}
		else
		{
			largeLoc = root * 2 + 2;
		}
		if (heap->compare(heap->heapAry[root], heap->heapAry[largeLoc]) < 0)
		{
			//parent < childeren 
			hold = heap->heapAry[root];
			heap->heapAry[root] = heap->heapAry[largeLoc];
			heap->heapAry[largeLoc] = hold;
			_reheapDown(heap, largeLoc);
		}
	}
	return;
}

void heapDestroy(HEAP* heap)
{
	void** Ptr;

	if (!heap)
		return;
	else
	{
		Ptr = heap->heapAry;
		free(Ptr);
		free(heap);
		return;
	}
		
}

void heapPrint(HEAP* heap)
{
	// Local Declarations
	int i = 0;
	
	for (i = 0; i <= heap->last; i++)
	{
		printf("%d\n", (int*) heap->heapAry[i]);
	}

	return;
}

int heapCount(HEAP* heap)
{
	if (!heap)
		return 0;
	else
		return heap->size;
}
bool heapFull(HEAP* heap)
{
	if (!heap)
		return false;
	else if (heap->size == heap->maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool heapEmpty(HEAP* heap)
{
	if (!heap)
	{
		return false;
	}
	if (heap->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}