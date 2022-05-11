#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;  // Address
typedef Person* Value;

typedef struct _slot {
  Key key;
  Value val;
}Slot;

#endif /* ifndef __SLOT_H__ */
