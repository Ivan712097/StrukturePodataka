#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int X;
	int Y;
	struct Node* next;
}Node;

int ReadFromFile( Node** root0, Node** root1)
{
	int i = 0, n = 0, rowCount = 0;
	Node Polinom = {
	   .X = 0,
	   .Y = 0,
	   .next = NULL
	};
	char buffer[1000] = { 0 };
	char* pBuffer = buffer;

	FILE* file = fopen("t.txt", "r");;
	if (file == NULL) {
		printf("File not opened\n");
		return 0;
	} 

	while ( !feof(file))
	{
		fgets(pBuffer, 1000, file);
		while (strlen(pBuffer) > 0)
		{

			sscanf (pBuffer, "%d %d %n", &Polinom.X, &Polinom.Y, &n);

			if(rowCount == 0)
			{
				insertSorted(root0, Polinom.X, Polinom.Y);
			}
			else if (rowCount == 1)
			{
				insertSorted(root1, Polinom.X, Polinom.Y);
			}
			pBuffer = pBuffer + n;
		}
		rowCount++;
	}
//while( fscanf(file, "%d %d", &Polinom.X, &Polinom.Y)  >= 2 && 2 );
//
//		if (Polinom.X > 0 && Polinom.Y >= 0)
//			insertSorted(root, Polinom.X, Polinom.Y);
//	
	/*while ((fscanf(file, "%d %d", &Polinom.X, &Polinom.Y)) >= 2) {
		if (Polinom.X > 0 && Polinom.Y >= 0)
		{
			insertSorted(root, Polinom.X, Polinom.Y);
		}
	}*/
	return 0;
}
int insertAfter(Node* curr, int x, int y)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL) return 5;
	newNode->X = x;
	newNode->Y = y;

	newNode->next = curr->next;
	curr->next = newNode;

	return 0;
}
int insertSorted(Node** root, int x, int y)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL) return 5;
	newNode->X = x;
	newNode->Y = y;

	Node* curr = *root;
	while (curr->next != NULL)
	{
		if (y < curr->next->Y)
			break;

		curr = curr->next;
	}
	insertAfter(curr, x, y);

	return 0;
}
int PrintList(Node* root)
{
	Node* currentEl = root->next;
	while (currentEl != NULL)
	{
		printf("%dx^%d\n", currentEl->X, currentEl->Y);
		currentEl = currentEl->next;
	}
	return 0;
}
int AddPolynoms(Node* root, Node** rootZ) {
	int zbrojPolinomaX;
	int zbrojPolinomaY;
	Node* curr = root->next;;
	Node* curr2 = curr;

	while ((curr) != NULL) {
		zbrojPolinomaX = 0;
		zbrojPolinomaY = 0;
		while (curr2 != NULL && curr->Y == curr2->Y)
		{
			zbrojPolinomaX = zbrojPolinomaX + curr2->X;
			zbrojPolinomaY = curr->Y;

			curr2 = curr2->next;
		}
		insertSorted(rootZ, zbrojPolinomaX, zbrojPolinomaY);
		curr = curr2;
	}
	return 0;
}
int mulitplyPolynoms(Node* root0, Node* root1, Node** root01M){
	Node* curr0 = root0->next;
	Node* curr1 = root1->next;

	while (curr0 != NULL)
	{
		while (curr1 != NULL)
		{
			int umnozakX = 1;
			int zbrojY = 0;

			umnozakX = curr0->X * curr1->X;
			zbrojY = curr0->Y + curr1->Y;

			insertSorted(root01M, umnozakX, zbrojY);
			curr1 = curr1->next;
		}
		curr0 = curr0->next;
		curr1 = root1->next;
	}
	return 0;
}
int Deallocation(Node** root)
{
	Node* toRemove = NULL;
	Node* curr = *root;

	while (curr != NULL) {
		toRemove = curr;
		curr = curr->next;
		free(toRemove);
	}
	//free(*root);
	return 0;
}

int AddTwoPolynoms(Node* root0, Node* root1, Node** root01, Node** root01Z)
{
	Node* curr0 = root0->next;
	Node* curr1 = root1->next;

	while (curr0 != NULL)
	{
		
		insertSorted(root01, curr0->X, curr0->Y);
		curr0 = curr0->next;
	}

	while (curr1 != NULL)
	{
		insertSorted(root01, curr1->X, curr1->Y);
		curr1 = curr1->next;
	}
	AddPolynoms(*root01, root01Z);

	//int zbrojPolinomaX = 0;
	//int zbrojPolinomaY = 0;
	/*while (curr0 != NULL && curr1 != NULL)
	{
		zbrojPolinomaX = 0;
		zbrojPolinomaY = 0;

		if (curr0->Y == curr1->Y)
		{
			zbrojPolinomaX = curr0->X + curr1->X;
			zbrojPolinomaY = curr1->Y;
			insertSorted(root01, zbrojPolinomaX, zbrojPolinomaY);
			curr0 = curr0->next;
			curr1 = curr1->next;
		}
		else if ( curr0->Y < curr1->Y )
		{
			insertSorted(root01, curr0->X, curr0->Y);
			curr0 = curr0->next;
		}
		else if (curr0->Y > curr1->Y)
		{
			insertSorted(root01, curr1->X, curr1->Y);
			curr1 = curr1->next;
		}
	}*/

	return 0;

}
int main() {

	Node* root0 = malloc(sizeof(Node));
	if (root0 == NULL)
		return 5;
	root0->next = NULL;

	Node* root0Z = malloc(sizeof(Node));
	if (root0Z == NULL)
		return 2;
	root0Z->next = NULL;

	Node* root1 = (Node*)malloc(sizeof(Node));
	if (root1 == NULL)
		return 5;
	root1->next = NULL;

	Node* root1Z = malloc(sizeof(Node));
	if (root1Z == NULL)
		return 2;
	root1Z->next = NULL;


	Node* root01M = malloc(sizeof(Node));
	if (root01M == NULL)
		return 2;
	root01M->next = NULL;


	Node* root01 = malloc(sizeof(Node));
	if (root01== NULL)
		return 2;
	root01->next = NULL;

	Node* root01Z = malloc(sizeof(Node));
	if (root01Z == NULL)
		return 2;
	root01Z->next = NULL;


	ReadFromFile( &root0 , &root1);

	printf("Prva lista\n");
	PrintList(root0);
	printf("Druga lista\n");
	PrintList(root1);

	AddPolynoms(root0, &root0Z);
	printf("Prva lista zbrojena \n");
	PrintList(root0Z);

	AddPolynoms(root1, &root1Z);
	printf("Druga lista zbrojena \n");
	PrintList(root1Z);

	//AddTwoPolynoms(root0Z, root1Z, &root01, &root01Z);

	//printf("Lista od dvi liste spojena \n");
	//PrintList(root01);

	//printf("zbrojene liste zbrojene \n");
	//PrintList(root01Z);

	mulitplyPolynoms(root0, root1, &root01M);
	printf("Pomnozene liste 1 i 2 \n");

	PrintList(root01M);



	Deallocation(&root0);
	Deallocation(&root1);

	return 0;
}
