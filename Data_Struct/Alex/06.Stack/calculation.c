#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculation.h"
#include "ListBaseStack.h"

static void TransformEXP(char* exp_t);
static int IsNumber(char c);
static void CalInTray(Stack *tray, int num1);

static void TransformEXP(char* exp_t)
{
    char *res = exp_t;
    int index = 0;
    Stack tray;

    StackInit(&tray);
    for (int i=0; i < strlen(exp_t); i++) {
        switch(exp_t[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
                SPush(&tray, exp_t[i]);
                break;
            case ')':
                while(1) {
                    char op = (char)SPop(&tray);
                    if (op == '(') break;
                    *(res+(index++)) = op;
                }
                break;
            default:
                *(res+index++) = exp_t[i];
                break;
        }
    }
    while(!SIsEmpty(&tray)) *(res+index++) = (char)SPop(&tray);
    *(res+index++) = '\0';
}

static int IsNumber(char c)
{
    if (c != '+' && c != '-' && c != '*' && c != '/') return TRUE;
    return FALSE;
}

static void CalInTray(Stack *tray, int num1)
{
    int num2 = SPop(tray);
    char op;
    if (!SIsEmpty(tray)) op = (char)SPop(tray);
    else {
        printf("[Error] Invalid Equation!!!\n");
        exit(-1);
    }

    int res = 0;
    switch(op) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            res = num1 / num2;
            break;
    }
    if (!SIsEmpty(tray)) {
        if (IsNumber((char)SPeek(tray))) {
            CalInTray(tray, res);
            return;
        }
    }
    SPush(tray, res);
}

int calculation(char* exp)
{
    int res = 0;
    char* exp_t = malloc(strlen(exp));
    strcpy(exp_t, exp);
    TransformEXP(exp_t);
    printf("TransformEXP: %s\n", exp_t);

    Stack tray;
    StackInit(&tray);

    for (int i=strlen(exp_t)-1; i > -1; i--) {
        if (IsNumber(exp_t[i])) {
            if (!SIsEmpty(&tray)) {
                if (IsNumber((char)SPeek(&tray))) {
                    CalInTray(&tray, (int)(exp_t[i] - '0'));
                    continue;
                }
            }
            SPush(&tray, (int)(exp_t[i] - '0'));
        }
        else SPush(&tray, exp_t[i]);
    }
    while(!SIsEmpty(&tray)) res = SPop(&tray);
    free(exp_t);
    return res;
}
