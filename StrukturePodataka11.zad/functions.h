#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256
#define SIZE_OF_TABLE 11
#define LAST_NAME_LENGTH 5

typedef struct listElement* position;
typedef struct hashTable* pointerHash;
typedef struct listElement {
	char firstName[MAX_STRING_LENGTH];
	char lastName[MAX_STRING_LENGTH];
	char registrationNumber[MAX_STRING_LENGTH];
	position next;
}ListElement;
typedef struct hashTable {
	int size;
	position* hashList;
}HashTable;

pointerHash InitializeHashTable(int);
int CountKey(char*);
int InputStudentsFromFile(char*, pointerHash);
position AllocateMemoryForStudent(char*, char*, char*);
int AddToHashTable(position, pointerHash);
int PrintHashTable(pointerHash);
int FindStudent(char*, char*, pointerHash);
#endif 