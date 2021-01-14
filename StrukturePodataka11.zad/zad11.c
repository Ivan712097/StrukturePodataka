#include "functions.h"
int main()
{
	pointerHash hashTable = InitializeHashTable(SIZE_OF_TABLE);
	InputStudentsFromFile("students.txt", hashTable);
	PrintHashTable(hashTable);
	char choice;
	printf("If you want to find registration number of specific student please type y:\n");
	scanf(" %c",&choice);
	if (choice == 'y')
	{
		printf("Please enter last name and first name of that student:\n");
		char inputedLastName[MAX_STRING_LENGTH];
		char inputedFirstName[MAX_STRING_LENGTH];
		scanf(" %s %s", inputedLastName, inputedFirstName);
		FindStudent(inputedLastName, inputedFirstName, hashTable);
	}

	return 0;
}