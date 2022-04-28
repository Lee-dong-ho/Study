#include <stdio.h>
#include <string.h>
#include "ExpressionTree.h"
#include "ListBaseStack.h"

void ShowNodeData(int data)
{
    if (data >= 0 && data <= 9)
        printf("%d", data);
    else
        printf("%c", data);
}

BTreeNode *MakeExpTree(char exp[])
{
    Stack s;
    StackInit(&s);

    for (int i=0; i < strlen(exp); i++) {
        BTreeNode *bt = MakeBTreeNode();
        if (exp[i] >= '0' && exp[i] <= '9') {
            SetData(bt, (int)(exp[i] - '0'));
            SPush(&s, bt);
        }
        else {
            SetData(bt, exp[i]);
            MakeRightSubTree(bt, SPop(&s));
            MakeLeftSubTree(bt, SPop(&s));
            SPush(&s, bt);
        }
    }
    return SPop(&s);
}

int EvaluateExpTree(BTreeNode *bt)
{
    if (bt->left == NULL) {
        return bt->data;
    }
    int num1 = EvaluateExpTree(bt->left);
    int num2 = EvaluateExpTree(bt->right);
    switch(bt->data) {
        case '+':
          return num1 + num2;
          break;
        case '-':
          return num1 - num2;
          break;
        case '*':
          return num1 * num2;
          break;
        case '/':
          return num1 / num2;
          break;
    }
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
