#include <stdio.h>

void main (/*int argc, char *argv[]*/){
  int i = 0;
  char words[256];
  int arrayIndex = 0;
  int currChar;
 // for (i;i<1/*argc*/;++i){
    FILE *f = fopen("txtFile.txt"/*argv[i]*/ , "rt");
    /*if(!f)
    {
      printf("couldn't open the file");
      return;
    }*/
    printf("WORDS OF FILE NAME:txtFile"/* %s",argv[i]*/);
    while((currChar = fgetc(f)) != EOF){
    //if the char is not a letter and not a digit
      if((isalpha(currChar)!=0) || (isdigit(currChar)!=0))
      {
	printf("%c",currChar);
      }
      else
	printf("\n");
     //++currChar;  
    }
  //}
  /*return;*/
}


