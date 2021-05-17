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
	graf = (Graf*)calloc(1,sizeof(Graf));
	ret = 0;
	while (ret != 6) {
		ch = dialog(&x,&y,&name1,&name2,&name0);
		ret = rasp(ch, x, y, name0,name1, name2,&graf);
	}
	free_graf(graf);
	//_CrtDumpMemoryLeaks();
	return 0;
}