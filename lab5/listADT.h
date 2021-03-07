//List ADT Type Definitions
typedef struct node
{
	void* dataPtr;
	struct node* link;
}NODE;

typedef struct
{
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
	int(*compare)(void* argul, void* argu2);
}LIST;


//Prototype Declarations

LIST* createList(int(*compare)(void* argu1, void* argu2));
LIST* destroyList(LIST* list);
/*
int addNode(LIST* pList, void* dataPtr);

bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr);

static bool _insert(LIST* pList, NODE* pPre, void* dataInPtr);
*/
bool searchList(LIST* pList, void* pArgu, void** pDataOut);

bool retrieveNode(LIST* pList, void* pArgu, void** dataOutrPtr);

bool traverse(LIST* pList, int fromWhere, void**dataOutPtr);

int listCount(LIST* pList);
bool emptyList(LIST* pList);
bool fullList(LIST* pList);

void* front(LIST* pList); // return front value
void* back(LIST* pList); // return back value
bool pushFront(LIST* pList, void* dataPtr); // push the value into the front
bool pushBack(LIST* pList, void* dataPtr); // push the value into the back
void* popFront(LIST* pList); // show the value of the front and delete it
void* popBack(LIST* pList); // show the value of the back and delete it
bool insert(LIST* pList, int where, void* dataPtr); // insert the value into the specific position
bool erase(LIST* pList, int where); // delete the value of the specific position
int searchValue(LIST* pList, void* dataPtr); // search the specific value and return where it is
bool removeElement (LIST* pList, void* dataPtr); // delete all the data which is given
LIST* Unique(LIST* pList); // delete all the duplcate values
LIST* Reverse(LIST* pList); // turn around the order of data
bool ExchCont(LIST* pList, int cont1, int cont2); // exchange the value by each specific position
bool MergeTwoList(LIST* pList1, LIST* pList2); // merge two lists into one list
void* ShowCont(LIST* pList, int number); // return the value of specific position
bool Remove_If(LIST* pList, int(*ptr)(void* data)); // if ptr represent 0 then it satisfy the condition
LIST* Sortlist(LIST* list);
static void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr);

static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu);

//Create List

LIST* createList(int(*compare)(void* argu1, void* argu2))
{
	//Local Definitions
	LIST* list;

	//Statements
	list = (LIST*)malloc(sizeof(LIST));
	if (list)
	{
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->count = 0;
		list->compare = compare;
	}//if
	return list;

}// createList
/*		//////////////////////////////////////// sources from the textbook
int addNode(LIST* pList, void* dataInPtr)
{
	//Local Definitions
	bool found;
	bool success;

	NODE* pPre;
	NODE* pLoc;

	//Statements

	found = _search(pList, &pPre, &pLoc, dataInPtr);
	if (found)
		//Duplicate kes not allowed
		return (+1);

	success = _insert(pList, pPre, dataInPtr);
	if (!success)
		//overflow
		return (-1);

	return (0);
}

static bool _insert(LIST* pList, NODE* pPre, void* dataInPtr)
{
	//Local Definitions 
	NODE* pNew;
	//Statements
	if (!(pNew = (NODE*)malloc(sizeof(NODE))))
		return false;

	pNew->dataPtr = dataInPtr;
	pNew->link = NULL;

	if (pPre == NULL)
	{
		// Adding before first node or to empty list.
		pNew->link = pList->head;
		pList->head = pNew;
		if (pList->count == 0)
			//Adding to empty list. Set rear
			pList->rear = pNew;
	} // if pPre
	else
	{
		// Adding in middle or at end
		pNew->link = pPre->link;
		pPre->link = pNew;

		// Now check for add at end of list
		if (pNew->link == NULL)
			pList->rear = pNew;
	}// if else
	(pList->count)++;
	return true;

}// _insert
*/
/*
bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr)
{
	//Local Definitions
	bool found;
	NODE* pPre;
	NODE* pLoc;

	//Satatements
	found = _serach(pList, &pPre, &pLoc, keyPtr);
	if (found)
		_delete(pList, pPre, pLoc, dataOutPtr);

	return found;
}//removeNode
*/
void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr)
{
	//Satatements
	*dataOutPtr = pLoc->dataPtr;
	if (pPre == NULL)
		//Deleting first node
		pList->head = pLoc->link;
	else
		//Deleting any other node
		pPre->link = pLoc->link;

	//Test for deleting last node
	if (pLoc->link == NULL)
		pList->rear = pPre;

	(pList->count)--;
	free(pLoc);

	return;
}// _delete

bool searchList(LIST* pList, void* pArgu, void** pDataOut)
{
	//Local Definitions

	bool found;

	NODE* pPre;
	NODE* pLoc;

	//Statemetns
	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
		*pDataOut = pLoc->dataPtr;
	else
		*pDataOut = NULL;
	return found;
}// serachList

bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu)
{
#define COMPARE |( ((*pList->compare)(pArgu, (*pLoc)->dataPtr)) )
#define COMPARE_LAST |((*pList->compare)(pArgu, pList->rear->dataPtr))

	//Local Definitions 
	int result;

	//Statements 
	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->count == 0)
		return false;

	//Test for argument > last node in list

	if (((*pList->compare)(pArgu, pList->rear->dataPtr)) > 0) // COMPARE_LAST
	{
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}// if

	while ((result = (*pList->compare)(pArgu, (*pLoc)->dataPtr)) > 0) // COMPARE
	{
		// Have not ofund search argument location
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	} // while

	if (result == 0)
		//argument found--success
		return true;
	else
		return false;
}// _search


static bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr)
{

	//Local Definitions
	bool found;

	NODE* pPre;
	NODE* pLoc;

	// Statemnets

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
	{
		*dataOutPtr = pLoc->dataPtr;
		return true;
	} //if

	*dataOutPtr = NULL;
	return false;
}// retrieveNode

bool emptyList(LIST* pList)
{
	//Statements
	return (pList->count == 0);

}//emptyList

bool fullList(LIST* pList)
{
	//Local Definitions
	NODE* temp;

	//Statements

	if ((temp = (NODE*)malloc(sizeof(*(pList->head)))))
	{
		free(temp);
		return false;
	}//if

	//Dynamic memory full
	return true;
	
}//fullList

int listCount(LIST* pList)
{
	//Statements

	return pList->count;
}//listCount

bool traverse(LIST* pList, int fromWhere, void** dataPtrOut)
{
	//Statements
	if (pList->count == 0)
		return false;

	if (fromWhere == 0)
	{
		// Start from first node
		pList->pos = pList->head;
		*dataPtrOut = pList->pos->dataPtr;
		return true;
	}// if fromwhere

	else
	{
		// Start rom current position
		if (pList->pos->link == NULL)
			return false;
		else
		{
			pList->pos = pList->pos->link;
			*dataPtrOut = pList->pos->dataPtr;
			return true;
		} //if else
	}//if fromwhere else
}// traverse

LIST* destroyList(LIST* pList)
{
	//Local Definitions

	NODE* deletePtr;

	//Statements

	if (pList)
	{
		while (pList->count > 0)
		{

			//First delete data
			free(pList->head->dataPtr);

			//Now deltete node

			deletePtr = pList->head;
			pList->head = pList->head->link;
			pList->count--;
			free(deletePtr);
		}//while
		free(pList);
	}//if
	return NULL;
}//destroyList



void* front(LIST* pList)
{
	if (!emptyList(pList))
	{
		NODE* temp = NULL;
		temp = pList->head;

		//statements
		void* ptr = temp->dataPtr;

		return ptr;
	}//if
	else
	{
		return NULL;
	}//else
	
}//front

void* back(LIST* pList)
{
	if (!emptyList(pList))
	{
		NODE* temp = NULL;
		temp = pList->rear;

		//statements
		void* ptr = temp->dataPtr;

		return ptr;
	}// if
	else 
	{
		return NULL;
	}//else

}// back


bool pushFront(LIST* pList, void* dataPtr)
{
	//Local Definitions
	NODE* temp = NULL;
	temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return false;
	}
	//statements
	
	temp->dataPtr = dataPtr;
	temp->link = NULL;
	
	if (!emptyList(pList)) 
	{
		temp->link = pList->head;
		pList->head = temp;
		pList->count++;

		return true;
	}
	else
	{
		pList->head = temp;
		pList->rear = temp;
		(pList->count)++;

		return true;
	}
	
}


bool pushBack(LIST* pList, void* dataPtr)
{
	//Local Definitions
	NODE* temp = NULL;
	temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return false;
	}
	//statements

	temp->dataPtr = dataPtr;
	temp->link = NULL;

	if (!emptyList(pList))
	{
		pList->rear->link = temp;
		pList->rear = temp;
		pList->count++;

		return true;
	}
	else
	{
		pList->head = temp;
		pList->rear = temp;
		(pList->count)++;

		return true;
	}
}

void* popFront(LIST* pList)
{
	NODE* temp = NULL;
	void* dataOutPtr =NULL;

	if (emptyList(pList))
		return NULL;

	else
	{
		if (pList->count > 1)
		{
			temp = pList->head;
			dataOutPtr = pList->head->dataPtr;
			pList->head = pList->head->link;
			free(temp);
			(pList->count)--;
		}
		else if (pList->count == 1)
		{
			temp = pList->head;
			dataOutPtr = pList->head->dataPtr;
			pList->head = NULL;
			pList->rear = NULL;
			free(temp);
			(pList->count)--;
		}
	}// else
	return dataOutPtr;
}

void* popBack(LIST* pList)
{
	NODE** temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return NULL;
	}
	NODE** temp2 = (NODE*)malloc(sizeof(NODE));
	if (!temp2)
	{
		return NULL;
	}
	

	void* dataOutPtr = NULL;
	int i = 0;
	int count = pList->count;

	if (emptyList(pList))
		return NULL;

	else
	{
		if (count > 1)
		{
			
			*temp = pList->rear;
			dataOutPtr = pList->rear->dataPtr;
			*temp2 = pList->head;

			for (i = 0; i < count - 2; i++)
			{
				*temp2 = (*temp2)->link;
			}
			
			pList->rear = (*temp2);
			(*temp2)->link = NULL;
		
			free(temp);
	
			(pList->count)--;
		}
		else if(count == 1)
		{
			*temp = pList->rear;
			dataOutPtr = pList->rear->dataPtr;

			pList->head = NULL;
			pList->rear = NULL;
			
			free(temp);
	

			(pList->count)--;
		}
	}// else

	return dataOutPtr;
}


bool insert(LIST* pList, int where, void* dataPtr)
{
	if (where <= 0)
	{
		return false;
	}

	NODE** temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return NULL;
	}
	NODE* temp2 = (NODE*)malloc(sizeof(NODE));
	if (!temp2)
	{
		return NULL;
	}

	int i = 0;
	int count = pList->count;

	temp2->dataPtr = dataPtr;
	temp2->link = NULL;

	if (fullList(pList))
	{
		return false;
	}

	if (where > count+1) //
	{
		return false;
	}

	else if (where == 1) // insert at first
	{
		pushFront(pList, dataPtr);
		return true;

	}
	else if (where == (count + 1)) // insert at last
	{
		pushBack(pList, dataPtr);
		return true;
	}
	else if (where <= count) // insert in the middle of the list
	{
		*temp = pList->head;

		for (i = 0; i < where - 2; i++)
		{
			*temp = (*temp)->link;
		}

		temp2->link = (*temp)->link;
		(*temp)->link = temp2;
		(pList->count)++;
		
		return true;
	}
	
}
bool erase(LIST* pList, int where)
{
	if (where <= 0)
	{
		return false;
	}
	NODE** temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return NULL;
	}
	NODE* temp2 = NULL;

	int i = 0;
	int count = pList->count;

	if (emptyList(pList))
	{
		return false;
	}

	if (where > count) //
	{
		return false;
	}

	else if (where == 1) // insert at first
	{
		popFront(pList);
		return true;
	}
	else if (where == (count)) // insert at last
	{
		popBack(pList);
		return true;
	}
	else if (where <= count) // insert in the middle of the list
	{
		*temp = pList->head;

		for (i = 0; i < where - 2; i++)
		{
			*temp = (*temp)->link;
		}

		temp2 = (*temp)->link;

		(*temp)->link = (*temp)->link->link;
		free(temp2);
		(pList->count)--;
		
		return true;
	}
}

int searchValue(LIST* pList, void* dataPtr)
{
	if (emptyList(pList))
	{
		return false;
	}
	int where = 0;
	int i = 0;
	int(*ptr)(void* argu1, void* argu2) = pList->compare; //argu1 = 찾고자하는 value , argu2 = 리스트 정보

	void* ptr2 = NULL;

	NODE* temp = pList->head;
	ptr2 = temp->dataPtr;

	if ((*ptr)(dataPtr, ptr2) == 0)
	{
		return 1;
	}
	for (i = 1; i <= pList->count; i++)
	{
		if (temp->link != NULL)
		{
			temp = temp->link;
			ptr2 = temp->dataPtr;
			
			if ((*ptr)(dataPtr, ptr2) == 0)
			{
				return i+1;
			}
		}
		else
		{
			if ((*ptr)(dataPtr, ptr2) == 0)
			{
				return i;
			}
			else
			{
				return 0;
			}
		}
		
	}//for
	return 0;

}
bool removeElement(LIST* pList, void* dataPtr)
{
	if(emptyList(pList))
	{
		return false;
	}
	int where = 0;
	int i = 0;
	int b = 0;
	int(*ptr)(void* argu1, void* argu2) = pList->compare;   //argu1 = 찾고자하는 정보  ,  argu2 = 리스트 정보

	void* ptr2 = NULL;

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	if (!temp)
	{
		return NULL;
	}


	while (searchValue(pList, dataPtr) != 0)
	{
		where = searchValue(pList, dataPtr);
		erase(pList, where);
	}
		
	if (searchValue(pList, dataPtr) == 0)
	{
		return true;
	}

	
	return false;
}
void* ShowCont(LIST* pList, int number) // number 번째 리스트 내용 출력
{
	if (number <= 0)
	{
		return false;
	}
	int count = pList->count;

	if (emptyList(pList) || number > count)
	{
		return false;
	}

	int i = 0;
	NODE* temp = pList->head;
	void* DataOut = temp->dataPtr;

	for (i = 1; i < number; i++)
	{
		temp = temp->link;
	}

	DataOut = temp->dataPtr;

	return DataOut;
}

LIST* Unique(LIST* pList)
{
	if (emptyList(pList))
	{
		return NULL;
	}
	LIST* New = (LIST*)malloc(sizeof(LIST));
	if (!New)
	{
		return NULL;
	}
	int(*ptr)(void* argu1, void* argu2) = pList->compare;

	New = createList(pList->compare);
	New->count = 0;

	NODE* temp = pList->head;
	

	void* dataComp = NULL;
	void* dataPtr = NULL;

	int count = pList->count;
	int i = 0;
	int a = 0;

	while (!emptyList(pList))
	{
		for (i = 0; i < count; i++)
		{
			
			
			dataComp = popFront(pList);
			a = searchValue(New, dataComp);

			if (a == 0) // There is no duplicate data in New
			{
				pushFront(New, dataComp);
			}
		}//for
	}//while

	return New;
}

LIST* Reverse(LIST* pList)
{
	if (emptyList(pList))
	{
		return NULL;
	}
	LIST* New = (LIST*)malloc(sizeof(LIST));
	if (!New)
	{
		return NULL;
	}
	New = createList(pList->compare);

	int i = 0;
	int count = pList->count;
	int* dataCir = NULL;

	for (i = 0; i < count; i++)
	{
		dataCir = popFront(pList);
		pushFront(New, dataCir);
	}

	return New;
}

bool ExchCont(LIST* pList, int cont1, int cont2)
{
	if (cont1 <= 0 || cont2 <= 0 || emptyList(pList))
	{
		return false;
	}
	int temp = 0;

	if (cont1 == cont2)
	{
		return true;
	}
	if (cont2 < cont1) // keep cont1 less than cont2
	{
		temp = cont1;
		cont1 = cont2;
		cont2 = cont1;
	}

	int Bool = 0;

	void* ptr1 = NULL;
	void* ptr2 = NULL;

	ptr1 = ShowCont(pList, cont1);
	ptr2 = ShowCont(pList, cont2);
	
	Bool = insert(pList, cont1, ptr2);
	if (Bool == false)
	{
		return false;
	}

	Bool = erase(pList, cont1+1);
	if (Bool == false)
	{
		return false;
	}

	Bool = insert(pList, cont2, ptr1);
	if (Bool == false)
	{
		return false;
	}
	Bool = erase(pList, cont2+1);
	if (Bool == false)
	{
		return false;
	}

	return true;

}

bool MergeTwoList(LIST* pList1, LIST* pList2)
{
	if (emptyList(pList1) || emptyList(pList2))
	{
		return false;
	}

	if (pList1->compare != pList2->compare)  // 함수가 다를경우
	{
		return false;
	}

	int i = 0;
	void* ptr = NULL;

	while(!emptyList(pList2))
	{

		ptr = popBack(pList2);
		pushFront(pList1, ptr);
	}

	return true;

}

bool Remove_If(LIST* pList, int(*ptr)(void* data)) // Representation of whether the condition is satisfied or not is 0
{
	if (emptyList(pList))
	{
		return true;
	}

	//Local Definitions
	int(*Condition)(void* Data) = ptr;
	int i = 0;
	int a = 0;
	void* data = NULL;

	//Statesments

	for (i = 0; i < pList->count; i++)
	{
		data = ShowCont(pList, i + 1);
		a = Condition(data);

		if (a == 0) // the case satisfying the given condition.
		{
			a = erase(pList, i+1);

			if (a == false)
			{
				return false;
			}
		}//if
	}//for
}

LIST* Sortlist(LIST* list) // Function -> (a,b)   a > b return 1, a = b return 0 , a < b return -1
{
	if (emptyList(list))
	{
		return false;
	}
	LIST* New = (LIST*)malloc(sizeof(LIST));
	LIST* temp = (LIST*)malloc(sizeof(LIST));

	if (!New || !temp)
	{
		return NULL;
	}
	New = createList(list->compare);
	temp = createList(list->compare);

	int(*ptr)(void* argu1, void* argu2) = list->compare;
	int count = 0;
	int i = 0;
	int a = 0;
	int which = 1;
	void* Min = NULL;
	void* dataCom = NULL;
	
	temp = list;

	count = temp->count;

	while (!emptyList(temp))
	{
		which = 1;
		Min = ShowCont(temp, 1); // 첫번째 데이터
		
		for (i = 1; i <= count; i++)
		{
			dataCom = ShowCont(temp, i); // 비교 데이터

			a = ptr(Min, dataCom);

			if (a == 1) // Min < dataCom
			{
				Min = dataCom;
				which = i;
			}
		}//for
		erase(temp, which); 
		pushBack(New, Min);
		count = temp->count;
	}//while


	return New;
}