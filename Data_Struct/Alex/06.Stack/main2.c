#include <stdio.h>
#include "calculation.h"

int main(int argc, char *argv[])
{
    if (argc == 2) {
        char *exp = argv[1];
        printf("%s = %d\n", exp, calculation(exp));
    }
    else if (argc == 1) {
        char exp1[] = "1+2*3";
        char exp2[] = "(1+2)*3";
        char exp3[] = "((1-2)+3)*(5-2)";

        printf("%s = %d\n", exp1, calculation(exp1));
        printf("%s = %d\n", exp2, calculation(exp2));
        printf("%s = %d\n", exp3, calculation(exp3));
    }
    else {
        printf("[Error] Invalid number of argments\n");
    }

    return 0;
}
