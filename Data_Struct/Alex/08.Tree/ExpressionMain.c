#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
    char exp[] = "12+7*";
    BTreeNode *eTree = MakeExpTree(exp);

    printf("Pre-Type Expression : ");
    ShowPrefixTypeExp(eTree);
    printf("\nIn-Type Expression : ");
    ShowInfixTypeExp(eTree);
    printf("\nPost-Type Expression : ");
    ShowPostfixTypeExp(eTree);

    printf("\nExpression Result : %d\n", EvaluateExpTree(eTree));
    return 0;
}
