#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dialog.h"
#include "vertex.h"




int rasp(int ch,int x,int y, int name1,int name2,Graf** graf) {
	if (ch == 1) {
		add_ver(graf, x, y);
		return 0;
	}
	if (ch == 2) {
		add_edge(graf, name1, name2);
		return 0;
	}
	if (ch == 3) {

		/**help = seach(*knot1, key);
		if (*help != NULL) { return 2; }
		else { return 404; }
		*/
	}
	if (ch == 4) {
		/*
		show_tree(*knot1);
		return 0;
		*/
	}
	if (ch == 5) {
		show_graf(*graf);
	}
	if (ch == 6) {
		/*
		print_tree(*knot1, 0);
		return 0;
		*/
	}
	if (ch == 7) {
		//return 7;
	}
	if (ch == 8) {
		//D_Timing();
	}
}


void add_ver(Graf** graf, int x, int y) {
	if ((*graf)->graf_mas == NULL) {
		(*graf)->graf_mas = (Vertex*)calloc(1, sizeof(Vertex));
		(*graf)->graf_mas->name = 0;
		(*graf)->graf_mas->x = x;
		(*graf)->graf_mas->y = y;
		((*graf)->col_vertex)++;
	}
	else if ((*graf)->graf_mas != NULL) {
		(*graf)->graf_mas = (Vertex*)realloc(((*graf)->graf_mas), ((*graf)->col_vertex + 1) * sizeof(Vertex));
		(*graf)->graf_mas[(*graf)->col_vertex].name = (*graf)->col_vertex;
		(*graf)->graf_mas[(*graf)->col_vertex].x = x;
		(*graf)->graf_mas[(*graf)->col_vertex].y = y;
		(*graf)->graf_mas[(*graf)->col_vertex].edge = NULL;
		((*graf)->col_vertex)++;
		
	}
}

Vertex* find_ver(Graf* graf, int num) {
	if (num < graf->col_vertex) {
		return &(graf->graf_mas[num]);
	}
	else{
		return NULL;
	}
}
Edge* find_edge(Edge* edge,int num2) {
	while (edge != NULL && edge->from_el->name != num2) {
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
	if (find_ver(*graf, num1) != NULL && find_ver(*graf, num2) != NULL && find_edge((*graf)->graf_mas[num1].edge, num2) == NULL) {
		help_edge = go_to_end((*graf)->graf_mas[num1].edge);
		if (help_edge == NULL) {
			(*graf)->graf_mas[num1].edge = (Edge*)calloc(1, sizeof(Edge));
			(*graf)->graf_mas[num1].edge->from_el = &((*graf)->graf_mas[num1]);
			(*graf)->graf_mas[num1].edge->to_el = &((*graf)->graf_mas[num2]);
			(*graf)->graf_mas[num1].edge->weight = weight(&((*graf)->graf_mas[num1]), &((*graf)->graf_mas[num2]));
			((*graf)->col_edge)++;
			
		}
		else {
			help_edge->next_edge = (Edge*)calloc(1, sizeof(Edge));
			help_edge = help_edge->next_edge;
			help_edge->from_el = &((*graf)->graf_mas[num1]);
			help_edge->to_el = &((*graf)->graf_mas[num2]);
			help_edge->weight = weight(&((*graf)->graf_mas[num1]), &((*graf)->graf_mas[num2]));
			((*graf)->col_edge)++;
		}

	}

}

