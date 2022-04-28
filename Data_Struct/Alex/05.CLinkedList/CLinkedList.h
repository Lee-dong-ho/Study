#ifndef __CLINKEDLIST_H__
#define __CLINKEDLIST_H__

#define TRUE  1
#define FALSE 0

typedef struct _Node{
  int data;
  struct _Node *next;
}Node;

typedef struct _List{
  int numOfData;
  struct _Node *tail;
  struct _Node *before;
  struct _Node *cur;
}List;

void ListInit(List *plist);
void LInsert(List *plist, int data);
void LInsertFront(List *plist, int data);
int LFirst(List *plist, int *pdata);
int LNext(List *plist, int *pdata);
int LRemove(List *plist);
int LCount(List *plist);

#endif
