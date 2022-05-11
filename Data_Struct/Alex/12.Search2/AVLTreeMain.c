#include <stdio.h>
#include "BinaryTree.h"
#include "AVLRebalance.h"

BTreeNode *BSTInsert(BTreeNode **root, int data)
{
	BTInsert(root, data);
    return Rebalance(root);
}

int main(void)
{
	BTreeNode * avlRoot = NULL;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node

	avlRoot=BSTInsert(&avlRoot, 1);
	avlRoot=BSTInsert(&avlRoot, 2);
	avlRoot=BSTInsert(&avlRoot, 3);
	avlRoot=BSTInsert(&avlRoot, 4);
	avlRoot=BSTInsert(&avlRoot, 5);
	avlRoot=BSTInsert(&avlRoot, 6);
	avlRoot=BSTInsert(&avlRoot, 7);
	avlRoot=BSTInsert(&avlRoot, 8);
	avlRoot=BSTInsert(&avlRoot, 9);

	printf("Root Node : %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("Left1: %d, Right1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("Left2: %d, Right2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("Left3: %d, Right3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("Left4: %d, Right4: %d \n", GetData(clNode), GetData(crNode));
	return 0;
}
