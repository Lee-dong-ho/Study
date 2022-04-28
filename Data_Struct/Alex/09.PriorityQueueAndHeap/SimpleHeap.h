#ifndef __SIMPLEHEAP_H__
#define __SIMPLEHEAP_H__

#define TRUE  1
#define FALSE 0
#define HEAP_LEN  100

typedef struct _eheap {
  char data;
  int pr;
}EHeap;

typedef struct _heap {
  EHeap heapArr[HEAP_LEN];
  int idx;
}Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, char data, int pr);
char HDelete(Heap *ph);

#endif /* ifndef __SIMPLEHEAP_H__ */
