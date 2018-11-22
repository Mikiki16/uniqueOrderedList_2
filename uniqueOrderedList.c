#include "uniqueOrderedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



typedef struct node {
    Element data;
    struct node* next;
}*Node;


struct uniqueOrderedList_t {
    Node nextNode;
    Node iterator;
    int* size;
    copyElements copyElementsFunc;
    freeElements freeElementsFunc;
    elementsEquals elementsEqualFunc;
    elementGreaterThan elementGreaterThan;
};

UniqueOrderedList uniqueOrderedListCreate(Element copyElements,
        Element freeElements, Element elementsEquals,
        Element elementGreaterThan){
    if ( !copyElements || !freeElements || !elementsEquals ||
            !elementGreaterThan) {
        return NULL;}
    UniqueOrderedList uol = malloc(sizeof(*uol));
    if(uol == NULL){      //No success Of allocation of memory
        return NULL;
    }
    uol -> copyElementsFunc = copyElements;
    uol -> freeElementsFunc = freeElements;
    uol -> elementsEqualFunc = elementsEquals;
    uol -> elementGreaterThan = elementGreaterThan;

    Node nextNode = malloc(sizeof(*nextNode));
    if(nextNode == NULL){
        free(uol);
        return  NULL;
    }
    /* nextNode = NULL ; // Point to the end of the list */
    uol -> nextNode = nextNode;

    Node iteratorN = malloc(sizeof(*iteratorN));
    if(iteratorN == NULL) {
        free(uol);
        return NULL;
    }

    uol -> iterator = iteratorN ;

    int* size = malloc(sizeof(*int));
    uol -> size = size;
    return  uol;
}

void uniqueOrderedListDestroy(UniqueOrderedList uol){
    free(uol -> nextNode);
    free(uol -> iterator);
    free(uol -> size);
    free(uol);
}

int uniqueOrderedListSize(UniqueOrderedList uol){
    if(uol == NULL) return -1; //Uol = Null
    return *(uol-> size);
}
bool uniqueOrderedListContains(UniqueOrderedList uol, Element element){
    if(uol == NULL) return NULL;
    for(Node ptr = uol->nextNode ; ptr != NULL ; ptr = uol->nextNode->next){
        if(((uol-> elementsEqualFunc)(element, (ptr->data)))){
            return true;
        }
    }
    return false;
}

UniqueOrderedListResult uniqueOrderedListInsert(UniqueOrderedList uol,
        Element element){
    if(element == NULL) return UNIQUE_ORDERED_LIST_NULL_ARGUMENT;
    if(!(uniqueOrderedListContains(uol,element))){
        return UNIQUE_ORDERED_LIST_ITEM_ALREADY_EXISTS;
    }
    // Element does not exist in the list
    Node newNode = malloc(sizeof(*newNode));
    if(newNode == NULL) return NULL;

}

