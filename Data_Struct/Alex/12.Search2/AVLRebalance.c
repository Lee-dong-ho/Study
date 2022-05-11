#include <stdio.h>
#include "AVLRebalance.h"

#define DEBUG 0

static BTreeNode *RotateLL(BTreeNode *bt);
static BTreeNode *RotateRR(BTreeNode *bt);
static BTreeNode *RotateLR(BTreeNode *bt);
static BTreeNode *RotateRL(BTreeNode *bt);
static int GetHeight(BTreeNode *bt);
static int GetHeightDiff(BTreeNode *bt);

static BTreeNode *RotateLL(BTreeNode *bt)
{
    if (DEBUG) printf("[RotateLL] bt:%d\n", GetData(bt));
    BTreeNode* parent = bt;
    BTreeNode* child = GetLeftSubTree(bt);

    ChangeLeftSubTree(parent, GetRightSubTree(child));
    ChangeRightSubTree(child, parent);
    return child;
}

static BTreeNode *RotateRR(BTreeNode *bt)
{
    if (DEBUG) printf("[RotateRR] bt:%d\n", GetData(bt));
    BTreeNode* parent = bt;
    BTreeNode* child = GetRightSubTree(bt);

    ChangeRightSubTree(parent, GetLeftSubTree(child));
    ChangeLeftSubTree(child, parent);
    return child;
}

static BTreeNode *RotateLR(BTreeNode *bt)
{
    if (DEBUG) printf("[RotateLR] bt:%d\n", GetData(bt));
    BTreeNode* root = bt;
    ChangeLeftSubTree(root, RotateRR(GetLeftSubTree(root)));
    return RotateLL(root);
}

static BTreeNode *RotateRL(BTreeNode *bt)
{
    if (DEBUG) printf("[RotateRL] bt:%d\n", GetData(bt));
    BTreeNode* root = bt;
    ChangeRightSubTree(root, RotateLL(GetRightSubTree(root)));
    return RotateRR(root);
}

static int GetHeight(BTreeNode *bt)
{
    return 0;
}

static int GetHeightDiff(BTreeNode *bt)
{
    int left = 0;
    int right = 0;
    BTreeNode *pos = bt;

    while(pos->left != NULL) {
        left++;
        pos = pos->left;
    }

    pos = bt;
    while(pos->right != NULL) {
        right++;
        pos = pos->right;
    }

    return left-right;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
    //if (GetLeftSubTree(*pRoot) != NULL) ChangeLeftSubTree(*pRoot, Rebalance(&((*pRoot)->left)));
    //if (GetRightSubTree(*pRoot) != NULL) ChangeRightSubTree(*pRoot, Rebalance(&((*pRoot)->right)));

    int diff = GetHeightDiff(*pRoot);
    if (diff == 2) {
        if (DEBUG) printf("[Rebalance] root(%d)->ldiff:%d\n", GetData(*pRoot), GetHeightDiff((*pRoot)->left));
        if (GetHeightDiff((*pRoot)->left) > 0) return RotateLL(*pRoot);
        return RotateLR(*pRoot);
    }
    else if (diff == -2) {
        if (DEBUG) printf("[Rebalance] root(%d)->rdiff:%d\n", GetData(*pRoot), GetHeightDiff((*pRoot)->right));
        if (GetHeightDiff((*pRoot)->right) < 0) return RotateRR(*pRoot);
        return RotateRL(*pRoot);
    }
    return *pRoot;
}
