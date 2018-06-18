#include <stdio.h>
#include <stdlib.h>
#include "../include/HashTableAPI.h"
#include "../include/main.h"

int main()
{
  int key1 = 103;
  int key2 = 283;
  int key3 = 827;
  int key4 = 29;
  int key5 = 340;
  int key6 = 340;
  char data1[] = "Logan";
  char data2[] = "Bell";
  char data3[] = "Testing";
  char data4[] = "is";
  char data5[] = "hard";
  char data6[] = "tester";

  printf("Creating hash table of size 17\n\n");
  HTable *hTable = createTable(17,hashFunction,destroyData,NULL);

  //insert some test data into the hash table
  printf("Inserting key: %d(index: %d)\tdata: %s\n",key1,hashFunction(17,key1),(char*)data1);
  insertData(hTable,key1,(void*)data1);

  printf("Inserting key: %d(index: %d)\tdata: %s\n",key2,hashFunction(17,key2),(char*)data2);
  insertData(hTable,key2,(void*)data2);

  printf("Inserting key: %d(index: %d)\tdata: %s\n",key3,hashFunction(17,key3),(char*)data3);
  insertData(hTable,key3,(void*)data3);

  printf("Inserting key: %d(index: %d)\tdata: %s\n",key4,hashFunction(17,key4),(char*)data4);
  insertData(hTable,key4,(void*)data4);

  printf("Inserting key: %d(index: %d)\tdata: %s\n",key5,hashFunction(17,key5),data5);
  insertData(hTable,key5,(void*)data5);

  //look up the data
  printf("\nLooking for data of key: %d\t data returned: %s\n",key2,(char*)lookupData(hTable,key2));
  printf("Looking for data of key: %d\t data returned: %s\n",key3,(char*)lookupData(hTable,key3));

  //overwrite the data in a node
  printf("\nOverwrite data at key: %d(index: %d)\tdata: %s\n",key6,hashFunction(17,key6),(char*)data6);
  insertData(hTable,key6,(void*)data6);

  //look up the data
  printf("Looking for data of key: %d\t data returned: %s\n",key6,(char*)lookupData(hTable,key6));

  return 0;
}

int hashFunction(size_t tableSize, int key)
{
  return key%tableSize;
}

void destroyData(void* data){
free(data);
return;
}

