#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "vertex.h"
#include "dialog.h"
#include "algo.h"

Find_v* find_ve_find_ma(Find_v* mas_find,int name,int kol) {
	//int kol = sizeof(mas_find) / sizeof(Find_v*);
	for (int i = 0; i < kol; i++) {
		if (mas_find[i].uk_vertex->name == name) {
			return &(mas_find[i]);
		}
	}
	return NULL;
}

Find_v** Q_move(Find_v** Q,int* len_q) {
	*len_q -= 1;
	if (*len_q > 0) {
		for (int i = 0; i < *len_q; i++) {
			Q[i] = Q[i + 1];
		}
		return Q;
	}
	else {
		return NULL;
	}
}

Find_v** Q_add_sm(Find_v** Q, int* len_q, Find_v* Q_el,Find_v* mas,int kol) {
	if (Q_el->uk_vertex->edge == NULL) {
		Q_el->color = 2;
		Q = Q_move(Q, len_q);
	}
	else {
		Edge* help;
		Find_v* help_add;
		help = Q_el->uk_vertex->edge;
		while (help != NULL) {
			help_add = find_ve_find_ma(mas, help->to_el->name,kol);
			if (help_add->color == 0) {
				help_add->color = 1;
				help_add->d = Q_el->d + 1;
				help_add->pred = Q_el;
				*len_q += 1;
				Q = (Find_v**)realloc(Q, (*len_q) * sizeof(Find_v*));
				Q[*len_q - 1] = help_add;

			}
			help = help->next_edge;
		}
		Q_el->color = 2;
		Q = Q_move(Q, len_q);
	}
	return Q;
}

int find_weight(Graf* graf, int name, int name_to) {
	int len_q = 0;
	Find_v** Q;
	Find_v* mas_find;
	Find_v* begin;
	Find_v* end;
	Q = NULL;
	mas_find = (Find_v*)calloc(graf->col_vertex, sizeof(Find_v));
	for (int i = 0; i < graf->col_vertex; i++) {
		mas_find[i].d = -1;
		mas_find[i].uk_vertex = &(graf->graf_mas[i]);
	}
	begin = find_ve_find_ma(mas_find, name, graf->col_vertex,graf->col_vertex);
	end = find_ve_find_ma(mas_find, name_to, graf->col_vertex,graf->col_vertex);
	if (begin == NULL || end == NULL) {
		return -1;
	}
	else {
		begin->color = 1;
		begin->d = 0;
		Q = (Find_v**)calloc(1, sizeof(Find_v*));
		Q[0] = begin;
		len_q = 1;
		while (Q != NULL) {
			Q = Q_add_sm(Q, &len_q, Q[0], mas_find,graf->col_vertex);
		}
		return print_find_weight(end);
	}

}