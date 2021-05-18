#ifndef VERTEX_H
#define VERTEX_H

typedef struct Find_v Find_v;

typedef struct Edge {
	struct Vertex* from_el;
	struct Vertex* to_el;
	struct Edge* next_edge;
	float weight;
}Edge;

typedef struct Vertex {
	int name;
	int x;
	int y;
	struct Edge* edge;
}Vertex;

typedef struct  Graf {
	struct Vertex* graf_mas;
	int col_vertex;
	int col_edge;
}Graf;

Graf* graf;
int x, y,name0,name1, name2,ch,ret;
char* name;

int rasp(int ch, int x, int y, int name0, int name1, int name2, Graf** graf);
void add_ver(Graf** graf, int x, int y,int name0);
Vertex* find_ver(Graf* graf, int num);
Edge* find_edge(Edge* edge, int num2);
Edge* go_to_end(Edge* edge);
float weight(Vertex* first, Vertex* second);
int add_edge(Graf** graf, int num1, int num2);
void del_edge(Graf** graf, int name1, int name2);
void del_ver(Graf** graf, int name1);
void change_uk(Vertex* el, Vertex* change, Edge** edge);
void free_edges(Edge* edge);
void free_graf(Graf* graf);
int load(Graf** graf, char* name);
void save(Graf* graf, char* name);
void random(Graf** graf, int kol);

#endif

