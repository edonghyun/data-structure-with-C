#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "binary_tree.h"

void traversal_preorder(TreeNode* root);
void traversal_inorder(TreeNode* root);
void traversal_postorder(TreeNode* root);

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;

	printf("a�� �� �� : ?\n");
	scanf_s("%d", &a);
	printf("b�� �� �� : ?\n");
	scanf_s("%d", &b);
	printf("c�� �� �� : ?\n");
	scanf_s("%d", &c);
	printf("d�� �� �� : ?\n");
	scanf_s("%d", &d);
	printf("e�� �� �� : ?\n");
	scanf_s("%d", &e);


	TreeNode* A = CreateTree(NULL, a, NULL);
	TreeNode* B = CreateTree(NULL, b, NULL);
	TreeNode* C = CreateTree(NULL, c, NULL);
	TreeNode* D = CreateTree(NULL, d, NULL);
	TreeNode* E = CreateTree(NULL, e, NULL);

	A->left = B;
	B->left = C;
	B->right = D;
	A->right = E;

	printf("Preorder ��������� : ");
	traversal_preorder(A);
	printf("\n");

	printf("Inorder ��������� : ");
	traversal_inorder(A);
	printf("\n");

	printf("Postorder ��������� : ");
	traversal_postorder(A);
	printf("\n");

	system("PAUSE");

	return 0;
}

void traversal_preorder(TreeNode* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	traversal_preorder(root->left);
	traversal_preorder(root->right);
}
void traversal_inorder(TreeNode* root)
{
	if (root == NULL)
		return;

	traversal_inorder(root->left);
	printf("%d ", root->data);
	traversal_inorder(root->right);
}
void traversal_postorder(TreeNode* root)
{
	if (root == NULL)
		return;

	traversal_postorder(root->left);
	traversal_postorder(root->right);
	printf("%d ", root->data);
}