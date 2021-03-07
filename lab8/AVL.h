#define LH +1
#define EH 0
#define RH -1

typedef int Element;
//Structure Declarations 

typedef struct node
{
	void* dataPtr;
	struct node* left;
	int bal;
	struct node* right;
}NODE;

typedef struct
{
	int count;
	int(*compare)(void* argu1, void* argu2);
	NODE* root;
}AVL_TREE;


AVL_TREE* AVL_Create(int(*compare)(void* argu1, void* argu2));
AVL_TREE* AVL_Destroy(AVL_TREE* tree);

bool AVL_Insert(AVL_TREE* tree, void* dataInPtr);
bool AVL_Delete(AVL_TREE* tree, void* dltKey);

void* AVL_Search(AVL_TREE* tree, void* keyPtr);
void AVL_Traverse(AVL_TREE* tree, void(*process)(void* dataPtr));
int AVL_Count(AVL_TREE* tree);
bool AVL_Empty(AVL_TREE* tree);
bool AVL_Full(AVL_TREE* tree);
void AVL_Print(AVL_TREE* tree);
void _print(NODE* root);


static NODE* _insert(AVL_TREE* tree, NODE* root, NODE* newPtr, bool* taller);
static NODE* _delete(AVL_TREE* tree, NODE* root, void* dltKey, bool* shorter, bool* success);
static void* _search(AVL_TREE* tree, void* keyPtr, NODE* root);
static void _traversal(NODE* root, void*(*process)(void* dataPtr));
static void _destroy(NODE* root);

static NODE* rotateLeft(NODE* root);
static NODE* rotateRight(NODE* root);
static NODE* insLeftBal(NODE* root, bool* taller);
static NODE* insRightBal(NODE* root, bool* taller);
static NODE* dltLeftBal(NODE* root, bool* shorter);
static NODE* dltRightBal(NODE* root, bool* shorter);

AVL_TREE* AVL_Create(int(*compare)(void* argu1, void* argu2))
{
	//Local Definitions
	AVL_TREE* tree;

	//Statements
	tree = (AVL_TREE*)malloc(sizeof(AVL_TREE));
	if (tree)
	{
		tree->root = NULL;
		tree->count = 0;
		tree->compare = compare;
	}//if

	return tree;
}

bool AVL_Insert(AVL_TREE* tree, void* dataInPtr)
{
	//Local Definitions
	NODE* newPtr;
	bool forTaller;

	//Statements

	newPtr = (NODE*)malloc(sizeof(NODE));
	if (!newPtr)
		return false;

	newPtr->bal = EH;
	newPtr->right = NULL;
	newPtr->left = NULL;
	newPtr->dataPtr = dataInPtr;

	tree->root = _insert(tree, tree->root, newPtr, &forTaller);
	(tree->count)++;
	return true;
}//AVL_Insert

NODE* _insert(AVL_TREE* tree, NODE* root, NODE* newPtr, bool* taller)
{
	//Statements
	if (!root)
	{
		//Insert at root
		root = newPtr;
		*taller = true;
		return root;
	}// if NULL Tree

	if (tree->compare(newPtr->dataPtr, root->dataPtr) < 0)
	{
		// newData < root -- go left
		root->left = _insert(tree, root->left, newPtr, taller);
		if (*taller)
		{
			//Left subtree is taller
			switch (root->bal)
			{
			case LH: // Was left high - rotate
				root = insLeftBal(root, taller);
				break;
			case EH: // Was balanced -- now LH
				root->bal = LH;
				break;
			case RH: // was right high -- now EH
				root->bal = EH;
				*taller = false;
				break;
			}//switch
			return root;
		}
	}// new < node
	else
	{
		//new data >= root data
		{
			root->right = _insert(tree, root->right, newPtr, taller);
			if (*taller)
			{
				switch (root->bal)
				{
				case LH: // Was left high--now EH
					root->bal = EH;
					*taller = false;
					break;
				case EH:
					root->bal = RH;
					break;
				case RH:
					root = insRightBal(root, taller);
					break;
				} // switch
				return root;
			}
		}//else new data>= root data
	}
	return root;
}//_insert

NODE* insLeftBal(NODE* root, bool* taller)
{
	//Local Definitions
	NODE* rightTree;
	NODE* leftTree;

	//Statements

	leftTree = root->left;
	switch (leftTree->bal)
	{
	case LH: // Left High -- rotate Right
		root->bal = EH;
		leftTree->bal = EH;

		//Rotate Right

		root = rotateRight(root);
		*taller = false;
		break;

	case EH: // This is an Error
		printf("\n\aError in insLeftBal \n");

	case RH: // Right High-Requires double
			 //rotation : first left, then right
		rightTree = leftTree->right;
		switch (rightTree->bal)
		{
		case LH:
			root->bal = RH;
			leftTree->bal = EH;
			break;
		case EH:
			root->bal = EH;
			leftTree->bal = LH;
			break;
		case RH:
			root->bal = EH;
			leftTree->bal = LH;
		}//switch rightTree

		rightTree->bal = EH;
		//Rotate LEft
		root->left = rotateLeft(leftTree);

		//Rotate Right
		root = rotateRight(root);
		*taller = false;
	}//switch

	return root;
}

NODE* insRightBal(NODE* root, bool* taller)
{
	//Local Definitions
	NODE* rightTree;
	NODE* leftTree;

	//Statements
	rightTree = root->right;
	switch (rightTree->bal)
	{
	case LH: // Left High-requires double
			 //rotation : first right, then left
		leftTree = rightTree->left;
		switch (leftTree->bal)
		{
		case LH:
			root->bal = EH;
			rightTree->bal = RH;
			break;
		case EH:
			root->bal = EH;
			rightTree->bal = RH;////Understand
			break;
		case RH:
			root->bal = EH;
			rightTree->bal = LH;
			break;
		}//sitch leftTree1		

		leftTree->bal = EH;
		//Rotate Left
		root->left = rotateLeft(leftTree);
		root = rotateRight(root);
		*taller = false;
		break;

	case EH:
		printf("\n\aError in insRightBal\n");
		break;

	case RH:
		root->bal = EH;
		rightTree->bal = EH;

		//rotate left
		root = rotateLeft(root);
		*taller = false;
		break;
	}//switch 
	return root;
}

NODE* rotateLeft(NODE* root)
{
	//Local Definitions
	NODE* tempPtr;

	//Statements
	tempPtr = root->right;
	root->right = tempPtr->left;
	tempPtr->left = root;

	return tempPtr;
}

NODE* rotateRight(NODE* root)
{
	//Local Definitions
	NODE* tempPtr;

	//Statements
	tempPtr = root->left;
	root->left = tempPtr->right;
	tempPtr->right = root;

	return tempPtr;
}

bool AVL_Delete(AVL_TREE* tree, void* dltKey)
{
	//Local Definitions
	bool shorter;
	bool success;
	NODE* newRoot;

	//Statements
	newRoot = _delete(tree, tree->root, dltKey, &shorter, &success);

	if (success)
	{
		tree->root = newRoot;
		(tree->count)--;
		return true;
	}
	//if

	else
		return false;
}

NODE* _delete(AVL_TREE* tree, NODE* root, void* dltKey, bool* shorter, bool* success)
{
	//Local Definitions
	NODE* dltPtr;
	NODE* exchPtr;
	NODE* newRoot;

	//Statements
	if (!root)
	{
		*shorter = false;
		*success = false;
		return NULL;
	}

	if (tree->compare(dltKey, root->dataPtr) < 0)
	{
		root->left = _delete(tree, root->left, dltKey, shorter, success);
		if (*shorter)
			root = dltRightBal(root, shorter);
	}//if less

	else if (tree->compare(dltKey, root->dataPtr) > 0)
	{
		root->right = _delete(tree, root->right, dltKey, shorter, success);
		if (*shorter)
			root = dltLeftBal(root, shorter);
	}// if greater

	else
		//Found equal node
	{
		dltPtr = root;
		if (!root->right) // Only left subtree
		{
			newRoot = root->left;
			*success = true;
			*shorter = true;
			free(dltPtr);
			return newRoot; //base case
		}// if true
		else
			if (!root->left) // Only right subtree
			{
				newRoot = root->right;
				*success = true;
				*shorter = true;
				free(dltPtr);
				return newRoot; // base case
			}// if
			else//Delete Node has two subtree
			{
				exchPtr = root->left;
				while (exchPtr->right)
				{
					exchPtr = exchPtr->right;
				}
				root->dataPtr = exchPtr->dataPtr;
				root->left = _delete(tree, root->left, exchPtr->dataPtr, shorter, success);
				if (*shorter)
					root = dltRightBal(root, shorter);
			}//else
	}//equal node
	return root;
}

NODE* dltRightBal(NODE* root, bool* shorter)
{
	//Local Definitions
	NODE* rightTree;
	NODE* leftTree;

	//Statements
	switch (root->bal)
	{
	case LH:
		root->bal = EH;
		break;
	case EH:
		root->bal = RH;
		*shorter = false;
		break;
	case RH: // Right High - Rotate Left
		rightTree = root->right;
		if (rightTree->bal == LH) // Double rotation required
		{
			leftTree = rightTree->left;
			switch (leftTree->bal)
			{
			case LH: rightTree->bal = RH;
				root->bal = EH;
				break;
			case EH: rightTree->bal = EH;
				root->bal = EH;
			case RH: root->bal = LH;
				rightTree->bal = EH;
				break;
			}//switch

			leftTree->bal = EH;
			//Rotate Right then Left
			root->right = rotateRight(rightTree);
			root = rotateLeft(root);
		}// if rightTree->bal == LH
		else
		{
			//Single Rotation Only
			switch (rightTree->bal)
			{
			case LH:
			case RH: root->bal = EH;
				rightTree->bal = EH;
				break;
			case EH: root->bal = RH;
				rightTree->bal = LH;
				*shorter = false;
				break;
			}//switch rightTree->bal
			root = rotateLeft(root);
		}//else
	}//switch
	return root;
}


NODE* dltLeftBal(NODE* root, bool* shorter)
{
	//Local Definitions
	NODE* rightTree;
	NODE* leftTree;

	//Statements

	switch (root->bal)
	{
	case LH: // Left High - Rotate Right
		leftTree = root->left;
		if (leftTree->bal == RH) // Double rotation required
		{
			rightTree = leftTree->right;
			switch (rightTree->bal)
			{
			case LH: leftTree->bal = LH;
				root->bal = EH;
				break;
			case EH:leftTree->bal = EH;
				root->bal = EH;
			case RH: root->bal = RH;
				leftTree->bal = EH;
			}//switch

			rightTree->bal = EH;
			//Rotate Right then Left
			root->left = rotateLeft(leftTree);
			root = rotateRight(root);
		}// if leftTree->bal = RH
		else
		{
			//Single Rotation Only
			switch (leftTree->bal)
			{
			case RH:
			case LH: root->bal = EH;
				leftTree->bal = EH;
				break;
			case EH:root->bal = LH;
				leftTree->bal = RH;
				*shorter = false;
				break;
			}//siwtch rightTree->bal
			root = rotateRight(root);
		}
	case EH:
		root->bal = RH;
		*shorter = false;
		break;
	case RH:
		root->bal = EH;
		break;
	}//switch
	return root;
}

void* AVL_Search(AVL_TREE* tree, void* keyPtr)
{
	//Statements 
	if (tree->root)
		return _search(tree, keyPtr, tree->root);
	else
		return NULL;
}

void* _search(AVL_TREE* tree, void* keyPtr, NODE* root)
{
	//Statements
	if (root)
	{
		if (tree->compare(keyPtr, root->dataPtr) < 0)
			return _search(tree, keyPtr, root->left);
		else if (tree->compare(keyPtr, root->dataPtr) > 0)
			return _search(tree, keyPtr, root->right);
		else

			//Found equal key
			return root->dataPtr;
	}
	else
		// Data not in tree

		return NULL;
}


void AVL_Traverse(AVL_TREE* tree, void(*process)(void* dataPtr))
{
	//Statements
	_traversal(tree->root, process);
	return;
}

void _traversal(NODE* root, void(*process)(void* dataPtr))
{
	//Statements

	if (root)
	{
		_traversal(root->left, process);
		process(root->dataPtr);
		_traversal(root->right, process);
	} // if
	return;
}

bool AVL_Empty(AVL_TREE* tree)
{
	//Statements
	return (tree->count == 0);
}

bool AVL_FULL(AVL_TREE* tree)
{
	//Local Definitions 
	NODE* newPtr;

	//Statements
	newPtr = (NODE*)malloc(sizeof(*(tree->root)));
	if (newPtr)
	{
		free(newPtr);
		return false;
	}//if
	else
		return true;
}

int AVL_Count(AVL_TREE* tree)
{
	//Statements
	return (tree->count);
}

AVL_TREE* AVL_Destroy(AVL_TREE* tree)
{
	//Statements
	if (tree)
	{
		_destroy(tree->root);
	}
	free(tree);
	return NULL;
}

void _destroy(NODE* root)
{
	//Statemnts

	if (root)
	{
		_destroy(root->left);
		free(root->dataPtr);
		_destroy(root->right);
		free(root);
	}// if 
	return;
}
void AVL_Print(AVL_TREE* root)
{
	if (!root)
		return;
	else
	{
		AVL_Traverse(root, _print);
	}
	return;
}

void _print(void* dataPtr)
{
	printf("°ª : %d\n", (int) dataPtr);
	return;
}




