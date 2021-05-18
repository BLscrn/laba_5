#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "vertex.h"
#include "dialog.h"
#include "algo.h"

char* enter_str() {
	int q = 1, size = 10;
	char vsp_str[11];
	int n = 1;
	char* osn_str;
	osn_str = (char*)calloc(1, sizeof(char));
	while (1) {

		n = scanf("%10[^\n]s", &vsp_str);
		if (n == 0) { return osn_str; }
		osn_str = (char*)realloc(osn_str, (size + q) * sizeof(char));
		strcpy((osn_str)+(q - 1), vsp_str);

		q += 10;

	}
}

int getInt(int* a) {
	int n;
	do {
		n = scanf("%d", a, sizeof(int));
		if (n < 0)
			return 0;
		if (n == 0) {
			printf("%s\n", "Error, try again:");
			scanf("%*s", 0);
		}
	} while (n == 0);
	return 1;
}

int dialog(int* x, int* y,int* name1, int* name2,int* name0) {
	int flag, ch;
	char* chouse[] = { "1. Enter new vertex", "2. Enter new edge"
		,"3. dellete vertex","4. dellete edge","5. show graf","6. Exite","7. random generation","8. find in weight","9. find short way"};
	printf("Choose one of this variants:\n");
	for (int i = 0; i < 9; i++) {
		printf("%s\n", chouse[i]);
	}
	flag = 0;
	do {
		if (flag == 1) {
			printf("\nPlease enter number more than 0 and less than 7:");
		}
		getInt(&ch);
		while (getchar() != '\n');
		flag = 1;
	} while (ch <= 0 || ch >= 10);
	if (ch == 1) {
		printf("Enter name: ");
		scanf("%d", name0);
		printf("Enter x: ");
		scanf("%d", x);
		while (getchar() != '\n');
		printf("Enter y: ");
		scanf("%d", y);
		while (getchar() != '\n');
		return 1;
	}
	if (ch == 2) {
		printf("Enter name1: ");
		scanf("%d", name1);
		while (getchar() != '\n');
		printf("Enter name2: ");
		scanf("%d", name2);
		while (getchar() != '\n');
		return 2;
	}
	if (ch == 3) {
		printf("Enter name1: ");
		scanf("%d", name1);
		while (getchar() != '\n');
		return 3;
		
	}
	if (ch == 4) {
		printf("Enter name1: ");
		scanf("%d", name1);
		while (getchar() != '\n');
		printf("Enter name2: ");
		scanf("%d", name2);
		while (getchar() != '\n');
		return 4;
	}
	if (ch == 5) {
		return 5;
	}
	if (ch == 6) {
		return 6;
	}
	if (ch == 7) {
		printf("number of elements");
		scanf("%d", name1);
		while (getchar() != '\n');
		return 7;
	}
	if (ch == 8) {
		printf("Enter name1: ");
		scanf("%d", name1);
		while (getchar() != '\n');
		printf("Enter name2: ");
		scanf("%d", name2);
		while (getchar() != '\n');
		return 8;
	}
	if (ch == 9) {
		printf("Enter name1: ");
		scanf("%d", name1);
		while (getchar() != '\n');
		printf("Enter name2: ");
		scanf("%d", name2);
		while (getchar() != '\n');
		return 9;
	}
}

void show_graf(Graf* graf) {
	printf("\n<====show graf====>\n\n");
	Edge* help;
	for (int i = 0; i < graf->col_vertex; i++) {
		printf("\nname: %d\n", graf->graf_mas[i].name);
		printf("coordinates x: %d  y: %d \n", graf->graf_mas[i].x, graf->graf_mas[i].y);
		printf("edges:\n");
		help = graf->graf_mas[i].edge;
		while (help != NULL) {
			printf("%d ---> %d\n", help->from_el->name, help->to_el->name);
			printf("weight: %f\n", help->weight);
			help = help->next_edge;
		}
	}
}


char* enter_file(Graf** graf) {
	char* name;
	char qwer;
	int re = 1;
	printf("Enter name of the file: ");
	name = enter_str();
	while (getchar() != '\n');
	re = load(graf, name);
	return name;
}


int print_find_weight(Find_v* show_el) {
	if (show_el->pred != NULL) {
		printf("Path is:\n");
		prt_f_w(show_el, show_el);
		return 0;
	}
	else {
		return 1;
	}
}

void prt_f_w(Find_v* show_el,Find_v* end) {
	if (show_el->pred == NULL) {
		printf("%d(%d)--->",show_el->uk_vertex->name, show_el->d);
	}
	else{
		prt_f_w(show_el->pred,end);
		if (show_el != end) {
			printf("%d(%d)--->",show_el->uk_vertex->name, show_el->d);
		}
		else {
			printf("%d(%d)\n", show_el->uk_vertex->name, show_el->d);
		}
	}
}

void check_ans(int res, Graf* help) {
	if (res == 404) {
		printf("There are no such element in graf\n");
	}
	else if (res == 504) {
		printf("There is no way\n");
	}

}