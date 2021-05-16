#ifndef DIALOG_H
#define DIALOG_H

typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct  Graf Graf;

char* enter_str();
int getInt(int* a);
int dialog(int* x, int* y, int* name1, int* name2);
void show_graf(Graf* graf);

#endif
