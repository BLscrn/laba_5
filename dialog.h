#ifndef DIALOG_H
#define DIALOG_H

typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct  Graf Graf;
typedef struct Find_v Find_v;

char* enter_str();
int getInt(int* a);
int dialog(int* x, int* y, int* name1, int* name2, int* name0);
void show_graf(Graf* graf);
char* enter_file(Graf** graf);
int print_find_weight(Find_v* show_el);
void prt_f_w(Find_v* show_el, Find_v* end);
void check_ans(int res, Graf* help);
void print_dfs(Find_v* mas, Graf* graf);
void DFS_Visit_show(int* time, Graf* graf, Find_v* mas_el, Find_v* mas);
Find_v* DFS_mod(Graf* graf1, Find_v* mas, Find_v* mas1);
int D_Timing_weight();
int D_Timing_kr();


#endif
