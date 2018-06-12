#include <stdio.h>
#include <stdlib.h>
#include "../include/HashTableAPI.h"
#include "../include/main.h"

int main()
{
  int key1 = 103;
  int key2 = 283;
  int key3 = 827;
  char data1[] = "logan";
  char data2[] = "bell";
  char data3[] = "testing";

  HTable *hTable = createTable(17,hashFunction,free,NULL);
  insertData(hTable,key1,(void*)data1);
  printf("%s",lookupData(hTable,key1));
  return 0;
}

int hashFunction(size_t tableSize, int key)
{
  return key%tableSize;
}
