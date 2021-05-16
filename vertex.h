#ifndef VERTEX_H
#define VERTEX_H

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
int x, y, name1, name2,ch,ret;

int rasp(int ch, int x, int y, int name1, int name2, Graf** graf);
void add_ver(Graf** graf, int x, int y);
Vertex* find_ver(Graf* graf, int num);
Edge* find_edge(Edge* edge, int num2);
Edge* go_to_end(Edge* edge);
float weight(Vertex* first, Vertex* second);
int add_edge(Graf** graf, int num1, int num2);

#endif

