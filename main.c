#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dialog.h"
#include "vertex.h"



int main(){ 
	graf = (Graf*)calloc(1,sizeof(Graf));
	ret = 0;
	while (ret != 7) {
		ch = dialog(&x,&y,&name1,&name2);
		ret = rasp(ch, x, y, name1, name2,&graf);
	}
	
	return 0;
}