#include "Person.h"
#include <stdio.h>
#include <string.h>

int GetSSN(Person *p)
{
    return p->ssn;
}

void ShowPerInfo(Person *p)
{
    printf("[ShowPerInfo]\n");
    printf("SSN: %d\nName: %s\nAddr: %s\n\n", p->ssn, p->name, p->addr);
}

Person *MakePersonData(int ssn, char *name, char *addr)
{
    Person *np = (Person*)malloc(sizeof(Person));
    np->ssn = ssn;
    strcpy(np->name, name);
    strcpy(np->addr, addr);
    return np;
}
