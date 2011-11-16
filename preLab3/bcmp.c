#include <stdio.h>
#include <errno.h>


int main (int argc , char** argv , char ** envp)
{


	int i,readCount1,readCount2;
	char c1,c2;
	int size=35;
	FILE* file1;
	FILE* file2;
	char* buff1;
	char* buff2;
	
	readCount1 = fread(buff1,1, 50,argv[1]);
	readCount2 = fread(buff2,1, 50,argv[2]);
	//fseek(copy_to, write_offset, SEEK_SET);
	//fseek(copy_from, read_offset, SEEK_SET);
	
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	while((c1!=feof) ||(c2!=feof)){
	if(c1!=c2){
		printf("%d %c %c \n", i, c1,c2);
		break;
	}
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	++i;
	}

	return 0;
}   
