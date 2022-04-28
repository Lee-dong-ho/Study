#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
    Stack s;
    StackInit(&s);

    SPush(&s, 1);
    SPush(&s, 2);
    SPush(&s, 3);
    SPush(&s, 4);
    SPush(&s, 5);

    while(!SIsEmpty(&s)) SPop(&s);
    printf("\n");

    return 0;
}
