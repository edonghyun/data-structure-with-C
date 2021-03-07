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
	int del = 0;
	int i = 0;

	printf("�� 8���� ���� �Է¹޽��ϴ�. -> Tree\n");

	printf("%d��° �Է� ��? \n", i+1);
	scanf_s("%d", &a);

	TreeNode* A = CreateTree(NULL, a, NULL);

	for (i = 1; i < 7 ; i++)
	{
		printf("%d��° �Է� ��? \n", i+1);
		scanf_s("%d", &a);
		A = BST_insertion(A, a);
	}

	printf("�������� ��..?\n");
	scanf_s("%d", &del);
	A = BST_deletion(A, del);

	printf("Preorder ��������� : ");
	traversal_preorder(A);
	printf("\n");

	printf("Inorder ��������� : ");
	traversal_inorder(A);
	printf("\n");

	printf("Postorder ��������� : ");
	traversal_postorder(A);
	printf("\n");

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