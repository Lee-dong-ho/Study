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
    if (root == NULL) {
        printf("Search Fail!!\n");
        return NULL;
    }
    if (target == GetData(root)) {
        printf("Search Success ^_^ : %d\n", target);
        return root;
    }
    else if (target < GetData(root)) {
        if (DEBUG) printf("BTSearch: %d->left\n", GetData(root));
        return BTSearch(GetLeftSubTree(root), target);
    }
    else {
        if (DEBUG) printf("BTSearch: %d->right\n", GetData(root));
        return BTSearch(GetRightSubTree(root), target);
    }

}

int main(void)
{
    BTreeNode *btRoot = NULL;

    BTInsert(&btRoot, 9);
    BTInsert(&btRoot, 1);
    BTInsert(&btRoot, 6);
    BTInsert(&btRoot, 2);
    BTInsert(&btRoot, 8);
    BTInsert(&btRoot, 3);
    BTInsert(&btRoot, 5);

    BTSearch(btRoot, 1);
    BTSearch(btRoot, 4);
    BTSearch(btRoot, 6);
    BTSearch(btRoot, 7);

    return 0;
}
