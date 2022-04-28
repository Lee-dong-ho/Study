#ifndef __USEFULHEAP_H__
#define __USEFULHEAP_H__

#define TRUE  1
#define FALSE 0
#define HEAP_LEN  100

typedef int HData;

typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap {
  PriorityComp comp;
  HData heapArr[HEAP_LEN];
  int idx;
}Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);
void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif /* ifndef __USEFULHEAP_H__ */
