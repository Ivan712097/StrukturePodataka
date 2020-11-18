#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MIN 10
#define MAX 100
typedef struct stog* pozicija;
struct stog {
	int el;
	pozicija next;
};
int stog(pozicija);
int push(pozicija);
int pop(pozicija);
int ispis(pozicija);
int main()
{
	srand(time(NULL));
	struct stog Head;
	Head.next = NULL;
	stog(&Head);
	
	return 0;
}
int stog(pozicija p)
{
	char c;
	while (1) {
		printf("Unesi N za unos novog elementa, M za micanje postojeceg elementa, I za ispis elemenata stoga, X za izlaz\n");
		scanf(" %c", &c);
		if (c == 'N')
			push(p);
		else if (c == 'M')
			pop(p);
		else if(c == 'I')
			ispis(p->next);
		else if (c == 'X')
			break;
		else
			printf("Nisi unio ispravno slovo!\n");
	}
	return 0;
}
int ispis(pozicija p)
{
	while (p != NULL)
	{
		printf("Element je: %d\n", p->el);
		p = p->next;
	}
	return 0;
}
int push(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct stog));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	int broj = (rand() % (MAX - MIN + 1)) + MIN;
	q->el = broj;
	q->next = p->next;
	p->next = q;
	
	return 0;
}
int pop(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct stog));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	if (p->next == NULL)
		printf("Stog je prazan!\n");
	else
	{
		printf("Skidamo element:%d\n", p->next->el);
		q = p->next;
		p->next = q->next;
		free(q);
	}
	return 0;
}