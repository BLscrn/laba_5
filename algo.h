#ifndef ALGO_H
#define ALGO_H

typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct  Graf Graf;


typedef struct Find_v {
	Vertex* uk_vertex;
	int color;  // 0 - white,  1 - gray, 2- black
	int d;
	Find_v* pred; 

}Find_v;

Find_v* find_ve_find_ma(Find_v* mas_find, int name, int kol);
Find_v** Q_move(Find_v** Q, int* len_q);
Find_v** Q_add_sm(Find_v** Q, int* len_q, Find_v* Q_el, Find_v* mas, int kol);
int find_weight(Graf* graf, int name, int name_to);
Find_v* go_on_edges(Graf* graf, Find_v* mas, Find_v* begin, int name1, int name2);
int short_way(Graf* graf, int name1, int name2);
int compare_el(float num1, float num2);


#endif