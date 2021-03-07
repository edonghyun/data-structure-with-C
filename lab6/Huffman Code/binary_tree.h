#include "binary_tree.c"

TreeNode* CreateTree(TreeNode* bt1, Element item, TreeNode* bt2);
TreeNode* LeftTree(TreeNode* bt);
TreeNode* RightTree(TreeNode* bt);
bool IsEmpty(TreeNode* bt);
void DestroyTree(TreeNode* bt);

TreeNode* CreateTree(TreeNode* bt1, Element item, TreeNode* bt2)
{
	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;
	pNewNode-> data= item;

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