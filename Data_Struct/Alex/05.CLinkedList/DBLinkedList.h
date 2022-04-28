#ifndef __DBLINKEDLIST_H__
#define __DBLINKEDLIST_H__

#define TRUE  1
#define FALSE 0

typedef struct _Node{
  int data;
  struct _Node *next;
  struct _Node *prev;
}Node;

typedef struct _List{
  int numOfData;
  struct _Node *head;
  struct _Node *tail;
  struct _Node *cur;
}List;

void ListInit(List *plist);
void LInsert(List *plist, int data);
int LFirst(List *plist, int *pdata);
int LNext(List *plist, int *pdata);
int LRemove(List *plist);
int LCount(List *plist);

#endif
