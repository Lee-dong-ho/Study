#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Slot.h"

#define TRUE  1
#define FALSE 0

typedef Slot LData;

typedef struct _Node{
  LData data;
  struct _Node *next;
}Node;

typedef struct _List{
  int numOfData;
  struct _Node *head;
  struct _Node *tail;
  struct _Node *before;
  struct _Node *cur;
}List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List *plist);

#endif
