#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

#define DEBUG 0

static void InsertSubTree(BTreeNode *pos, BTreeNode* newNode);

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *newNode = malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->left != NULL)
        free(main->left);
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        free(main->right);
    main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	  BTreeNode * delNode;

    if(bt != NULL) {
      delNode = bt->left;
      bt->left = NULL;
    }
    return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
    BTreeNode * delNode;

    if(bt != NULL) {
      delNode = bt->right;
      bt->right = NULL;
    }
    return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->right = sub;
}

static void InsertSubTree(BTreeNode *pos, BTreeNode* newNode)
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
    //*root = Rebalance(root);
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
    //*root = Rebalance(root);
    free(sNode);
}
