#include <stdio.h>
#include <errno.h>


int main (int argc , char** argv)
{


	int i,c1,c2;
	FILE* file1;
	FILE* file2;
	//char* buff1;
	//char* buff2;
	
	file1 = fopen(argv[1],"r");
	file2 = fopen(argv[2],"r");
	//readCount1 = fread(buff1,1, 50,argv[1]);
	//readCount2 = fread(buff2,1, 50,argv[2]);
	//fseek(copy_to, write_offset, SEEK_SET);
	//fseek(copy_from, read_offset, SEEK_SET);
	
	i = 1;
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	while((c1!=feof) ||(c2!=feof)){
	if(c1!=c2){
		printf("byte %d -%d +%d \n", i, c1,c2);
		break;
	}
	c1 = fgetc(file1);
	c2 = fgetc(file2);
	++i;
	}

	return 0;
}   
