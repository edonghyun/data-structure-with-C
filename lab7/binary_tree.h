#include "binary_tree.c"

TreeNode* CreateTree(TreeNode* bt1, Element item, TreeNode* bt2);
TreeNode* LeftTree(TreeNode* bt);
TreeNode* RightTree(TreeNode* bt);
TreeNode* BST_insertion(TreeNode* bst, Element item);
TreeNode* BST_search(TreeNode* bst, Element item);
TreeNode* BST_deletion(TreeNode* bst, Element item);
TreeNode* _insertion(Element item);

bool IsEmpty(TreeNode* bt);
void DestroyTree(TreeNode* bt);

TreeNode* CreateTree(TreeNode* bt1, Element item, TreeNode* bt2)
{
	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->data = item;

	pNewNode->left = bt1;
	pNewNode->right = bt2;
	return pNewNode;
}

TreeNode* LeftTree(TreeNode* bt)
{
	if (IsEmpty(bt) || IsEmpty(bt->left))
		return NULL;

	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;

	pNewNode = bt->left;

	return pNewNode;
}

TreeNode* RightTree(TreeNode* bt)
{
	if (IsEmpty(bt) || IsEmpty(bt->right))
		return NULL;

	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;

	pNewNode = bt->right;

	return pNewNode;
}
TreeNode* BST_insertion(TreeNode* bst, Element item)
{
	if (bst == NULL)
		return _insertion(item);

	if (item < bst->data)
		bst->left = BST_insertion(bst->left, item);
	else
		bst->right = BST_insertion(bst->right, item);

	return bst;

}
TreeNode* _insertion(Element item)
{
	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;

	pNewNode->left = NULL;
	pNewNode->right = NULL;
	pNewNode->data = item;

	return pNewNode;
}
TreeNode* BST_search(TreeNode* bst, Element item)
{
	if (!bst)
		return NULL;

	if (item < bst->data)
		return BST_search(bst->left, item);
	else if (item > bst->data)
		return BST_search(bst->right, item);
	else // 찾았을때
		return bst;
}
TreeNode* BST_deletion(TreeNode* bst, Element item)
{
	TreeNode* delPtr = NULL;

	if (bst == NULL)
	{
		return bst;
	}

	if (item < bst->data)
	{
		bst->left = BST_deletion(bst->left, item);
	}
	else if (item > bst->data)
		bst->right = BST_deletion(bst->right, item);
	else // root is the node to delete
	{
		if (!bst->right) // root has no child or only left subtree
		{
			delPtr = bst;
			bst = bst->left;
			free(delPtr);
			return bst;
		}else if (!bst->left) // root has only right subtree
		{
			delPtr = bst;
			bst = bst->right;
			free(delPtr);
			return bst;
		}
		else {
			//root has both left and right children
			//find the largest among the left subtree
			for (delPtr = bst->left; delPtr->right != NULL; delPtr = delPtr->right);
			
			bst->data = delPtr->data;
			bst->left = BST_deletion(bst->left, delPtr->data);
		}
	}
	return bst;
}

bool IsEmpty(TreeNode* bt)
{
	if (bt->left == NULL && bt->right == NULL)
		return true;
	else
		return false;
}

void DestroyTree(TreeNode* bt)
{
	if (bt == NULL)
		return;
	if (bt->left)
		DestroyTree(bt->left);
	if (bt->right)
		DestroyTree(bt->right);
	free(bt);
}