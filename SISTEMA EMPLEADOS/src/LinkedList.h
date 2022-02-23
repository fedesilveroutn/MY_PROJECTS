#ifndef LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

#define LINKEDLIST_H_


/*--------------------------------STRUCTS--------------------------------*/
struct Node
{
	void* pElement;
	struct Node* pNextNode;

}typedef Node;

typedef struct
{
	int size;
	Node* pFirstNode;

}LinkedList;


/*--------------------------------NODE--------------------------------*/
Node* getNode(LinkedList* this , int nodeIndex);
int addNode(LinkedList* this , int nodeIndex , void* pElement);


/*--------------------------------CONSTRUCTORS--------------------------------*/
LinkedList* linkedlist_new();


/*--------------------------------UTILITIES--------------------------------*/
int linkedlist_len(LinkedList* this);
int linkedlist_add(LinkedList* this, void* pElement);
void* linkedlist_get(LinkedList* this, int index);
int linkedlist_remove(LinkedList* this, int index);
int linkedlist_set(LinkedList* this, int index, void* pElement);
int linkedlist_clear(LinkedList* this);
int linkedlist_delete(LinkedList* this);
int linkedlist_sort(LinkedList* this, int (*pointerToFunction)(void* ,void*), int order );

#endif
