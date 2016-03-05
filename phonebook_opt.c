#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    int i=0;
    while (pHead != NULL) {
        for(i=0; i<ENTRY_SIZE; i++)
            if (strcasecmp(lastname, pHead->lastName[i]) == 0) {
                pHead->ans=pHead->lastName[i];
                return pHead;
            }
        pHead = pHead->pNext;
    }
    return NULL;
}
/*
inline entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    //e->pDetail = (detail *) malloc(sizeof(detail));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}
*/
inline entry *append(FILE *fp, entry *e)
{
    int i=0,j=0;
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    for(i=0; i<ENTRY_SIZE && fgets(e->lastName[i], sizeof(char)*MAX_LAST_NAME_SIZE, fp); i++) {
        while(e->lastName[i][j]!='\0')
            j++;
        e->lastName[i][j-1] = '\0';
        j=0;
    }

    e->pNext = NULL;

    if(i!=ENTRY_SIZE)
        return NULL;

    return e;
}
