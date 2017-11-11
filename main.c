#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct school {
	char *name;
	struct school * next;
} school;

school *getLast (school *start){ //Поиск последнего элемента
	if (start==NULL) {
		return NULL;
	}
	while (start->next) {
		start=start->next;
	}
	return start;
}

void end (school *start, char *name) { //Добавление в конец
	school *last=getLast(start);
	school *i=malloc(sizeof(school));
	i->name=strdup(name);
	i->next=NULL;
	last->next=i;
}

void display(school *start) { //Вывод списка
	school *i = start;
	if (i==NULL) {
		printf("NULL elements\n");
	}
	for ( ; i != NULL; i=i->next) {
		printf("%s\n", i->name);
	}
}

void release(school *start) { //Очистка памяти
	school *i = start;
	school *next = NULL;
	for ( ; i != NULL ; i = next) {
		next = i->next;
		free(i->name);
		free(i);
	}
}

school *create1 (char *name, school *start) { //Создание первого
	school *i = malloc(sizeof(school));
	i->name = strdup(name);
	i->next = start;
	return i;
}

school *deleteLast(school *start) { //Удаление последнего
	int k=0;
	school *last=getLast(start);
	school *i=start;
	school *next=NULL;
	for (;i->next->next;i=i->next);
		i->next=NULL;
}

int counter (school *start) { //Счетчик
	int k=0;
	school *last=getLast(start);
	school *i=start;
	school *next=NULL;
	while (start->next) {
		start=start->next;
		k++;
	}
	return k;
}

void findStruct (char *p, school *start){ //Поиск элемента
	int j = 0;
	school *i = start;
	for ( ; i != NULL; i=i->next) {
		j=j+1;
		if (strcmp(p,(i->name))==0) {
			printf("%d place\n", j);
			return;
		}
	}
	printf("No information\n");
}

int main(){
	school *start = NULL;
	school *i = NULL;
	school *next = NULL;
	school *b = NULL;
	char name[80];
	int j;
	char l;
	char f[80];
	int m = 0;

	while(l != 7){
		printf("\n1. Create first element\n");
		printf("2. Create last element\n");
		printf("3. Delete last element\n");
		printf("4. Display\n");
		printf("5. Delete all elements\n");
		printf("6. Search element\n");
		printf("7. Exit\n");
		scanf("%s", &l);
		getchar();
		switch(l) {
			case '1':
				scanf("%79s", &name);
				start = create1(name, start);
				break;

			case '2':
				if (start==NULL) {
					scanf("%79s", &name);
					start = create1(name, start);
				}
				else {
					scanf("%79s", name);
					end(start, name);
				}
				break;

			case '3':
				if (start==NULL)
					printf("NULL elements\n");
				else {
					m=counter(start);
					if (m==0) {
						release(start);
						start = NULL;
					}
					else {
						printf("Delete success\n");
						deleteLast(start);
					}
				}
				break;

			case '4':
				display(start);
				break;

			case '5':
				if (start == NULL) {
					printf("Null elements\n");
				}
				else {
					release(start);
					start = NULL;
				}
				break;

			case '6':
				scanf("%79s", &f);
				findStruct(f, start);
				break;

			case '7':
				exit(0);
				break;

			default:
			printf ("Wrong input\n");
			break;
		}
	}

	return 0;
}
