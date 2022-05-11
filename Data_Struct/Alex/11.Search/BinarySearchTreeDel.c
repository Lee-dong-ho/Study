#include <stdio.h>
#include "BinaryTree.h"

#define DEBUG 0

void InsertSubTree(BTreeNode *pos, BTreeNode* newNode)
{
    if (GetData(newNode) > GetData(pos)) {
        if (GetRightSubTree(pos) == NULL) {
            if (DEBUG) printf("BTInsert: %d->%d\n", GetData(pos), GetData(newNode));
            MakeRightSubTree(pos, newNode);
            return;
        }
        InsertSubTree(GetRightSubTree(pos), newNode);
    }
    else {
        if (GetLeftSubTree(pos) == NULL) {
            if (DEBUG) printf("BTInsert: %d->%d\n", GetData(pos), GetData(newNode));
            MakeLeftSubTree(pos, newNode);
            return;
        }
        InsertSubTree(GetLeftSubTree(pos), newNode);
    }
}

void BTInsert(BTreeNode **root, BTData data)
{
    BTreeNode *newNode = MakeBTreeNode();
    SetData(newNode, data);

    if (*root == NULL) {
        if (DEBUG) printf("BTInsert: root=%d\n", data);
        *root = newNode;
        return;
    }

    InsertSubTree(*root, newNode);
}

BTreeNode *BTSearch(BTreeNode *root, BTData target)
{
    if (root == NULL)
        return NULL;

    if (target == GetData(root))
        return root;

    else if (target < GetData(root)) {
        if (DEBUG) printf("BTSearch: %d->left\n", GetData(root));
        return BTSearch(GetLeftSubTree(root), target);
    }
    else {
        if (DEBUG) printf("BTSearch: %d->right\n", GetData(root));
        return BTSearch(GetRightSubTree(root), target);
    }

}

BTreeNode *BTSearchParent(BTreeNode *root, BTData target)
{
    if (target == GetData(root))
        return NULL;

    else if (target < GetData(root)) {
        if (target == GetData(GetLeftSubTree(root)))
            return root;
        if (DEBUG) printf("BTSearchParent: %d->left\n", GetData(root));
        return BTSearchParent(GetLeftSubTree(root), target);
    }
    else {
        if (target == GetData(GetRightSubTree(root)))
            return root;
        if (DEBUG) printf("BTSearchParent: %d->right\n", GetData(root));
        return BTSearchParent(GetRightSubTree(root), target);
    }

}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void BTRemove(BTreeNode **root, BTData data)
{
    BTreeNode *sNode = BTSearch(*root, data);
    if (sNode == NULL) {
        printf("[Error] There is no this data in tree!\n");
        return;
    }
    BTreeNode *pNode = BTSearchParent(*root, data);
    BTreeNode *ChgNode = NULL;

    if (sNode->left != NULL && sNode->right != NULL) {
        ChgNode = sNode->left;
        BTreeNode *pChgNode = sNode;
        if (ChgNode->right != NULL) {
            while (ChgNode->right != NULL) {
                pChgNode = ChgNode;
                ChgNode = ChgNode->right;
            }
            pChgNode->right = NULL;
            ChgNode->left = sNode->left;
        }
        ChgNode->right = sNode->right;
    }
    else if (sNode->left != NULL && sNode->right == NULL)
        ChgNode = GetLeftSubTree(sNode);
    else if (sNode->left == NULL && sNode->right != NULL)
        ChgNode = GetRightSubTree(sNode);

    if (pNode == NULL) {
        *root = ChgNode;
        (*root)->right = sNode->right;
    }
    else if (GetLeftSubTree(pNode) == sNode) pNode->left = ChgNode;
    else pNode->right = ChgNode;
    free(sNode);
}

int main(void)
{
    BTreeNode *btRoot = NULL;

    BTInsert(&btRoot, 5);    BTInsert(&btRoot, 8);
    BTInsert(&btRoot, 1);    BTInsert(&btRoot, 6);
    BTInsert(&btRoot, 4);    BTInsert(&btRoot, 9);
    BTInsert(&btRoot, 3);    BTInsert(&btRoot, 2);
    BTInsert(&btRoot, 7);

    InorderTraverse(btRoot, ShowIntData); printf("\n");
    BTRemove(&btRoot, 3);

    InorderTraverse(btRoot, ShowIntData); printf("\n");
    BTRemove(&btRoot, 8);

    InorderTraverse(btRoot, ShowIntData); printf("\n");
    BTRemove(&btRoot, 1);

    InorderTraverse(btRoot, ShowIntData); printf("\n");
    BTRemove(&btRoot, 6);

    InorderTraverse(btRoot, ShowIntData); printf("\n");
    BTRemove(&btRoot, 5);

    InorderTraverse(btRoot, ShowIntData); printf("\n");

    return 0;
}
