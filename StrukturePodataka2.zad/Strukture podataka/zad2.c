#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct osoba* pozicija;
struct osoba{
	char ime[30];
	char prezime[30];
	int god;
	pozicija next;
};

int unosP(pozicija p);
int ispis(pozicija p);
int unosK(pozicija p);
int traziPrez(pozicija p);
int brisi(pozicija p);


int main()
{
	struct osoba Head;
	Head.next = NULL;
	char izbor;
	while(1){
		printf("Unesi P(unos na pocetak), K(unos na kraj), I(ispis), T(trazi po prezimenu), B(brisi), X(izlaz)\n");
		scanf(" %c", &izbor);
		if (izbor == 'P')
			unosP(&Head);
		else if (izbor == 'I')
			ispis(Head.next);
		else if (izbor == 'K')
			unosK(&Head);
		else if (izbor == 'T')
			traziPrez(Head.next);
		else if (izbor == 'B')
			brisi(&Head);
		else if (izbor == 'X')
			break;
		else
			printf("Nisi unio ispravno slovo!\n");
	}
	return 0;
}
int unosP(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct osoba));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}

	printf("Unesi ime osobe:");
	scanf("%s", q->ime);
	printf("Unesi prezime osobe:");
	scanf("%s", q->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &q->god);

	q->next = p->next;
	p->next = q;
	return 0;
}
int ispis(pozicija p)
{
	while (p != NULL)
	{
		printf("%s %s %d \n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	return 0;
}
int unosK(pozicija p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct osoba));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	printf("Unesi ime osobe:");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe:");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &q->god);

	q->next = p->next;
	p->next = q;
	return 0;
}
int traziPrez(pozicija p)
{
	char prez[30];
	printf("Unesi prezime osobe koju zelis pronaci:\n");
	scanf(" %s", &prez);
	while (p != NULL && strcmp(prez, p->prezime) != 0)
	{
		p = p->next;
	}
	if (p == NULL)
		printf("Ne postoji osoba pod tim prezimenom\n");
	else
		printf("Adresa trazene osobe je: %p\n", p);
	return 0;
}

int brisi(pozicija p)
{
	pozicija pret = NULL;
	char prez[30];
	printf("Unesi prezime osobe koju zelis izbrisati:\n");
	scanf(" %s", &prez);
	while (p->next != NULL && strcmp(prez, p->prezime) != 0)
	{
		pret = p;
		p = p->next;
	}
	if (pret != NULL && strcmp(prez, p->prezime) == 0)
	{
		p = pret->next;
		pret->next = p->next;
		free(p);
	}
	return 0;
}
