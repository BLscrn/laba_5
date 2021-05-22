#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dialog.h"
#include "vertex.h"
#include "algo.h"



int rasp(int ch,int x,int y,int name0 ,int name1,int name2,Graf** graf) {
	if (ch == 1) {
		add_ver(graf, x, y,name0);
		return 0;
	}
	if (ch == 2) {
		add_edge(graf, name1, name2);
		return 0;
	}
	if (ch == 3) {

		del_ver(graf, name1);
		return 0;
	}
	if (ch == 4) {
		
		del_edge(graf, name1, name2);
		return 0;
		
	}
	if (ch == 5) {
		show_graf(*graf);
		return 0;
	}
	if (ch == 6) {
		return 6;
	}
	if (ch == 7) {
		random(graf, name1);
		return 7;
	}
	if (ch == 8) {
		int re;
		Find_v* mas = NULL;
		re = find_weight(*graf, name1, name2,&mas);
		if (re == -1) {
			return 404;
		}
		else {
			re = print_find_weight(find_ve_find_ma(mas, name2, (*graf)->col_vertex));
			if (re == 1) {
				free(mas);
				return 504;
			}
			else {
				free(mas);
				return 0;
			}
			return 0;
		}
	}
	if (ch == 9) {
		int re;
		Find_v* mas = NULL;
		re = short_way(*graf, name1, name2,&mas);
		
		if (re == -1) {
			return 404;
		}
		else {
			prt_f_w(find_ve_find_ma(mas, name2, (*graf)->col_vertex), find_ve_find_ma(mas, name2, (*graf)->col_vertex));
			free(mas);
			return 0;
		}
	}
	if (ch == 10) {
		Find_v* mas;
		Graf* graf1;
		Find_v* mas1;
		mas = max_svaz(*graf);
		//print_dfs(mas, *graf);
		graf1 = trnsp_graf(*graf);
		//show_graf(graf1);
		mas1 = mas_fill(graf1);
		//print_dfs(mas1, graf1);
		mas1 = DFS_mod(graf1, mas, mas1);
		//mas1 = max_svaz(graf1);
		//print_dfs(mas1, graf1);
		free_graf(graf1);
		free(mas);
		free(mas1);
	}
	if (ch == 11) {
		D_Timing_weight();
		return 0;
	}
	if (ch == 12) {
		D_Timing_kr();
		return 0;
	}
}


void add_ver(Graf** graf, int x, int y,int name0) {
	if (find_ver(*graf, name0) == NULL) {
		if ((*graf)->graf_mas == NULL) {
			(*graf)->graf_mas = (Vertex*)calloc(1, sizeof(Vertex));
			(*graf)->graf_mas->name = name0;
			(*graf)->graf_mas->x = x;
			(*graf)->graf_mas->y = y;
			((*graf)->col_vertex)++;
		}
		else if ((*graf)->graf_mas != NULL) {
			(*graf)->graf_mas = (Vertex*)realloc(((*graf)->graf_mas), ((*graf)->col_vertex + 1) * sizeof(Vertex));
			(*graf)->graf_mas[(*graf)->col_vertex].name = name0;
			(*graf)->graf_mas[(*graf)->col_vertex].x = x;
			(*graf)->graf_mas[(*graf)->col_vertex].y = y;
			(*graf)->graf_mas[(*graf)->col_vertex].edge = NULL;
			((*graf)->col_vertex)++;

		}
	}
}

Vertex* find_ver(Graf* graf, int num) {
	for (int i = 0; i < graf->col_vertex; i++) {
		if (graf->graf_mas[i].name == num) {
			return &(graf->graf_mas[i]);
		}
	}
	return NULL;
}
Edge* find_edge(Edge* edge, int num2) {
	while (edge != NULL && edge->to_el->name != num2) {
		edge = edge->next_edge;
	}
	return edge;
}

Edge* go_to_end(Edge* edge) {
	if (edge == NULL) {
		return edge;
	}
	else {
		while (edge->next_edge != NULL) {
			edge = edge->next_edge;
		}
		return edge;
	}
}

float weight(Vertex* first, Vertex* second) {
	return sqrt((first->x - second->x) * (first->x - second->x) + (first->y - second->y) * (first->y - second->y));
}

int add_edge(Graf** graf, int num1, int num2) {
	Edge* help_edge;
	Vertex* first;
	Vertex* second;
	first = find_ver(*graf, num1);
	second = find_ver(*graf, num2);
	if (first != NULL && second != NULL && find_edge(first->edge, num2) == NULL) {
		help_edge = go_to_end(first->edge);
		if (help_edge == NULL) {
			first->edge = (Edge*)calloc(1, sizeof(Edge));
			first->edge->from_el = first;
			first->edge->to_el = second;
			first->edge->weight = weight(first, second);
			((*graf)->col_edge)++;

		}
		else {
			help_edge->next_edge = (Edge*)calloc(1, sizeof(Edge)); // here
			help_edge = help_edge->next_edge;
			help_edge->from_el = first;
			help_edge->to_el = second;
			help_edge->weight = weight(first, second);
			((*graf)->col_edge)++;
		}

	}

}

void del_edge(Graf** graf, int name1, int name2) {
	Vertex* first;
	Vertex* second;
	first = find_ver(*graf, name1);
	second = find_ver(*graf, name2);
	Edge* help_edge = find_edge(first->edge, name2);
	Edge* help_del;
	if (help_edge != NULL) {
		help_del = first->edge;
		if (help_del == help_edge) {
			first->edge = help_edge->next_edge;
			free(help_del);
			((*graf)->col_edge)--;
		}
		else if (help_del != help_edge) {
			while (help_del->next_edge != help_edge) {
				help_del = help_del->next_edge;
			}
			help_del->next_edge = help_edge->next_edge;
			free(help_edge);
			((*graf)->col_edge)--;
		}
	}
}

void change_uk(Vertex* el, Vertex* change, Edge** edge) {
	Edge* help;
	help = *edge;
	while (help != NULL) {
		if (help->from_el == el) {
			help->from_el = change;
		}
		if (help->to_el == el) {
			help->to_el = change;
		}
		help = help->next_edge;
	}
}

void del_ver(Graf** graf, int name1) {
	Vertex* help_del;
	Vertex* new_mas;
	Vertex* old_mas;
	help_del = find_ver(*graf, name1);
	if (help_del != NULL) {
		while (help_del->edge != NULL) {
			del_edge(graf, help_del->edge->from_el->name, help_del->edge->to_el->name);
		}
		Edge* help_d_edge;
		for (int i = 0; i < (*graf)->col_vertex; i++) {
			if (&((*graf)->graf_mas[i]) != help_del) {
				while (find_edge((*graf)->graf_mas[i].edge, name1) != NULL) {
					help_d_edge = find_edge((*graf)->graf_mas[i].edge, name1);
					del_edge(graf, help_d_edge->from_el->name, help_d_edge->to_el->name);
				}
			}
		}

		for (int i = 0; i < (*graf)->col_vertex; i++) {
			if (&((*graf)->graf_mas[i]) == help_del) {
				(*graf)->graf_mas[i].edge = (*graf)->graf_mas[(*graf)->col_vertex - 1].edge;
				(*graf)->graf_mas[i].name = (*graf)->graf_mas[(*graf)->col_vertex - 1].name;
				(*graf)->graf_mas[i].x = (*graf)->graf_mas[(*graf)->col_vertex - 1].x;
				(*graf)->graf_mas[i].y = (*graf)->graf_mas[(*graf)->col_vertex - 1].y;
			}
			else {
				change_uk(&((*graf)->graf_mas[(*graf)->col_vertex - 1]), help_del, &((*graf)->graf_mas[i]).edge);
			}
		}
		(*graf)->graf_mas = (Vertex*)realloc((*graf)->graf_mas, ((*graf)->col_vertex - 1) * sizeof(Vertex));
		((*graf)->col_vertex)--;
		
	}
}

void free_edges(Edge* edge) {
	Edge* help;
	Edge* help_h;
	help = edge;
	while (help != NULL) {
		help_h = help;
		help = help->next_edge;
		free(help_h);
	}
}

void free_graf(Graf* graf) {
	for (int i = 0; i < graf->col_vertex; i++) {
		free_edges(graf->graf_mas[i].edge);
	}
	free(graf->graf_mas);
	free(graf);
}

int load(Graf** graf, char* name) {
	FILE* f = NULL;
	int x, y, name0;
	int kol;
	f = fopen(name, "r+b");
	if (f == NULL) {
		return 1;
	}
	fread(&kol, sizeof(int), 1, f);
	for (int i = 0; i < kol; i++) {
		fread(&x, sizeof(int), 1, f);
		fread(&y, sizeof(int), 1, f);
		fread(&name0, sizeof(int), 1, f);
		add_ver(graf, x, y, name0);
	}
	fread(&kol, sizeof(int), 1, f);
	for (int i = 0; i < kol; i++) {
		fread(&x, sizeof(int), 1, f);
		fread(&y, sizeof(int), 1, f);
		add_edge(graf, x, y);
	}
	fclose(f);
	return 0;
}

void save(Graf* graf,char* name) {
	FILE* f;

	f = fopen(name, "w+b");
	fwrite(&(graf->col_vertex), sizeof(int), 1, f);
	for (int i = 0; i < graf->col_vertex; i++) {
		fwrite(&(graf->graf_mas[i].x), sizeof(int), 1, f);
		fwrite(&(graf->graf_mas[i].y), sizeof(int), 1, f);
		fwrite(&(graf->graf_mas[i].name), sizeof(int), 1, f);
	}
	fwrite(&(graf->col_edge), sizeof(int), 1, f);
	Edge* help;
	for (int i = 0; i < graf->col_vertex; i++) {
		help = graf->graf_mas[i].edge;
		while (help != NULL) {
			fwrite(&(help->from_el->name), sizeof(int), 1, f);
			fwrite(&(help->to_el->name), sizeof(int), 1, f);
			help = help->next_edge;
		}
	}
	free(name);
	fclose(f);
}

void random(Graf** graf, int kol) {
	int rand_x;
	int rand_y;
	int rand_nm;
	for (int i = 0; i < kol; i++) {
		rand_x = rand() % 5000;
		rand_y = rand() % 5000;
		rand_nm = rand()% 5000;
		add_ver(graf, rand_x, rand_y, rand_nm);
	}
	//rand_nm = rand() % (kol*(kol-1));
	rand_nm = 2* kol; // change to get more edges
	for (int i = 0; i < rand_nm; i++) {
		rand_x = rand() % ((*graf)->col_vertex);
		rand_y = rand() % ((*graf)->col_vertex);
		add_edge(graf, (*graf)->graf_mas[rand_x].name, (*graf)->graf_mas[rand_y].name);
	}
}

