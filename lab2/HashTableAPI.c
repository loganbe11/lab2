#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printData)(void *toBePrinted))
{
  HTable *hTable[size] = malloc(sizeof(hTable)*size);

  hTable->destroyData=destroyData;
  hTable->hashFunction=hashFunction;
  hTable->printData=printData;

  return hTable;
}

Node *createNode(int key, void *data)
{
//creating new node and allocating space for node
  Node * newNode = malloc(sizeof(Node)*1);

  //initializing node elements
  newNode->key = key;
  newNode->data = data;
  newNode->next = NULL;

  //returning new node
  return newNode;
}
