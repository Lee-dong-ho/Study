#include <stdio.h>
#include "Table.h"

#define DEBUG 0

void TBLInit(Table *pt, HashFunc f)
{
    if (DEBUG) printf("[TBLInit]\n");
    for (int i=0; i < MAX_TBL; i++)
      pt->tbl[i].status = EMPTY;
    pt->hf = f;
}

void TBLInsert(Table *pt, Key k, Value v)
{
    if (DEBUG) printf("[TBLInsert]\n");
    int key = pt->hf(k);
    pt->tbl[key].key = k;
    pt->tbl[key].val = v;
    pt->tbl[key].status = INUSE;
}

Value TBLDelete(Table *pt, Key k)
{
    if (DEBUG) printf("[TBLDelete]\n");
    int key = pt->hf(k);

    if (pt->tbl[key].status != INUSE)
      return NULL;
    else {
      pt->tbl[key].status = DELETED;
      return pt->tbl[key].val;
    }
}

Value TBLSearch(Table *pt, Key k)
{
    if (DEBUG) printf("[TBLSearch]\n");
    int key = pt->hf(k);

    if (pt->tbl[key].status == INUSE)
      return pt->tbl[key].val;
    return NULL;
}
