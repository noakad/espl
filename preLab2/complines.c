#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(/*int argc, char **argv*/){
//string firstTxt = argv[1];
//string secondTxt = argv[2];

FILE *first;
FILE *second;

char *firstBuff[120];
char *secondBuff[120];
int rowCounter = 1;


first = fopen("a.txt" , "r");

/*if(!first)
{
  printf("couldn't open the file\n");
  //return 0;
}*/


second = fopen("b.txt" , "r");
/*if(!second)
{
  printf("couldn't open the file\n");
  //return 0;
}*/

while(!feof(first)){//while there are more lines to read
	fgets(firstBuff, 120, first);
	fgets(secondBuff, 120, second);
	if(strcmp(firstBuff,secondBuff)!=0){//if the lines are diff
		printf("-%d: %s \n" , rowCounter, firstBuff);
		printf("+%d: %s \n" , rowCounter, secondBuff);
	}

	rowCounter++;
}
return 0;
}



