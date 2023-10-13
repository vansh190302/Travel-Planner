#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Structure
typedef struct mynode {
	char name[20];
	char gen[6];
	int age;
	struct mynode* link;
} Node;
Node* start = NULL;

void heading();
void details();
void international();
void india();
void receipt();

int k, amount;
char type[60], place[30], date[20];

void main()
{
	int a;

	heading();

	printf("\t\t1. International "
		"Tour Packages\n");
	printf("\t\t2. India Tour Packages\n");
	printf("\t\tEnter Choice: ");
	scanf("%d", &a);
	switch (a) {
	case 1:
		international();
		break;
	case 2:
		india();
		break;

	default:
		printf("The choice doesn't match with the given options...");
		break;
	}

	details();

	receipt();
}

void india()
{
	int a;
	system("cls");

	heading();
	strcpy(type, "India Tour Package");
	printf("\t\t\t\t1. Odisha Tour Packages "
		"3 Days Package (20000/-)\n");
	printf("\t\t\t\t2. Kashmir Tour Packages "
		"5 Days Package (40000/-)\n");
	printf("\t\t\t\t3. Jaipur Tour Packages "
		"11 Days Package (100000/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(place, "Odisha Tour");
		amount = 20000;
	}
	else if (a == 2) {
		strcpy(place, "Kashmir Tour");
		amount = 40000;
	}
	else if (a == 3) {
		strcpy(place, "Jaipur Tour");
		amount = 100000;
	}
	else
		printf("The choice doesn't match with the given options...");
}

void international()
{
	int a;

	system("cls");

	heading();
	strcpy(type, "International Tour Package");
	printf("\t\t1. England Tour Packages "
		"6 Days Package (30000/-)\n");
	printf("\t\t2. Thailand Tour Packages "
		"5 Days Package (20000/-)\n");
	printf("\t\t3. New York Tour Packages "
		"11 Days Package (600000/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(place, "England Tour");
		amount = 30000;
	}
	else if (a == 2) {
		strcpy(place, "Thailand Tour");
		amount = 20000;
	}
	else if (a == 3) {
		strcpy(place, "New York Tour");
		amount = 600000;
	}
	else
		printf("The choice doesn't match with the given options...");
}

void details()
{
	int i, a;
	char val[20], gen[6];

	system("cls");

	heading();
	printf("\t\t\t\tEnter Number Of "
		"Passengers: ");
	scanf("%d", &k);
	printf("\t\t\t\tEnter Date "
		"(DD/MM/YY): ");
	fflush(stdin);
	gets(date);
	for (i = 1; i <= k; i++) {
		system("cls");
		heading();
		printf("\t\t\t\tEnter The %dth "
			"Passenger Name: ",
			i);
		fflush(stdin);
		gets(val);
		printf("\t\t\t\tEnter The %dth "
			"Passenger Gender: ",
			i);
		fflush(stdin);
		gets(gen);
		printf("\t\t\t\tEnter The %dth "
			"Passenger Age: ",
			i);
		fflush(stdin);
		scanf("%d", &a);
		add_node(val, gen, a);
	}
}

void add_node(char lol[20],
			char der[6], int b)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, lol);
	strcpy(newptr->gen, der);
	newptr->age = b;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

void receipt()
{
	int i, b;
	Node* ptr = start;
	system("cls");
	heading();
	printf("\n\t\t\t\t**Take Screenshot "
		"For Further Use**\n");
	for (i = 1; i <= k; i++) {
		printf("\t\t\t\t%dst Passenger "
			"Name: ",
			i);
		puts(ptr->name);
		printf("\t\t\t\t%dst Passenger "
			"Gender: ",
			i);
		puts(ptr->gen);
		printf("\t\t\t\t%dst Passenger "
			"Age: %d\n\n",
			i, ptr->age);
		ptr = ptr->link;
	}
	printf("\t\t\t\tSelected Type: ");
	puts(type);
	printf("\t\t\t\tPackage: ");
	puts(place);
	printf("\t\t\t\tDate: ");
	puts(date);
	b = amount * k;
	printf("\t\t\t\tTotal Amount: %d", b);
	printf("\n\t\t\t\t**Thank You For "
		"registration**");
}

void heading()
{
	printf("\t\t\t\t***Travel Planner "
		"Management System***\n");
}
