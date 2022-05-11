#include <stdio.h>
#include "Table.h"

#define DEBUG 0

void TBLInit(Table *pt, HashFunc f)
{
    if (DEBUG) printf("[TBLInit]\n");
    for (int i=0; i < MAX_TBL; i++)
      ListInit(&(pt->tbl[i]));
    pt->hf = f;
}

void TBLInsert(Table *pt, Key k, Value v)
{
    if (DEBUG) printf("[TBLInsert]\n");
    int key = pt->hf(k);
    Slot s;
    s.key = k;
    s.val = v;
    LInsert(&(pt->tbl[key]), s);
}

Value TBLDelete(Table *pt, Key k)
{
    if (DEBUG) printf("[TBLDelete]\n");
    int key = pt->hf(k);

    Slot s;
    if (LFirst(&(pt->tbl[key]), &s)) {
        LRemove(&(pt->tbl[key]));
        return s.val;
    }

    return NULL;
}

Value TBLSearch(Table *pt, Key k)
{
    if (DEBUG) printf("[TBLSearch]\n");
    int key = pt->hf(k);

    Slot s;
    if (LFirst(&(pt->tbl[key]), &s))
        return s.val;
    return NULL;
}
