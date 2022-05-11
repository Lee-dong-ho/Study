#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#define TRUE  1
#define FALSE 0

typedef int BTData;
typedef void (*VisitFuncPtr)(int data);

typedef struct _btreenode {
  BTData data;
  struct _btreenode *left;
  struct _btreenode *right;
}BTreeNode;

BTreeNode *MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);
BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);
void BTInsert(BTreeNode **root, BTData data);
BTreeNode *BTSearch(BTreeNode *root, BTData target);
BTreeNode *BTSearchParent(BTreeNode *root, BTData target);
void ShowIntData(int data);

#endif /* ifndef __BINARYTREE_H__ */
