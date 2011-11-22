#include <stdio.h>
#include <errno.h>


int main (int argc , char** argv)
{


	long i;
	int c1,c2;
	FILE* file1;
	FILE* file2;
	
	file1 = fopen(argv[1],"r");
	file2 = fopen(argv[2],"r");
	
	i = 1;
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	while((c1!=EOF) && (c2!=EOF)){
	if(c1!=c2){
		printf("byte %lu -%u +%u \n", i, c1,c2);
	}
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	++i;
	}

	return 0;
}   

