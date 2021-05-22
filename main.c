#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dialog.h"
#include "vertex.h"

/*
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
*/


int main(){ 
	//_crtBreakAlloc = 86;
	graf = (Graf*)calloc(1,sizeof(Graf));
	ret = 0;
	name = enter_file(&graf);
	while (ret != 6) {
		ch = dialog(&x,&y,&name1,&name2,&name0);
		ret = rasp(ch, x, y, name0,name1, name2,&graf);
		check_ans(ret, graf);
	}
	//printf("\n\n\n%d    %d", graf->col_vertex, graf->col_edge);
	save(graf, name);
	free_graf(graf);
	//_CrtDumpMemoryLeaks();
	return 0;
}