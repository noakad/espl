#include <stdio.h>

int main (/*int argc, char *argv[]*/){
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
     //while the char is not a letter  (it means im in state "not in a word") 
     while(isalpha(currChar=fgetc(f))==0){}
      //now im getting into the state "in a word" :
      //if the char is a letter or a digit
      while((isalpha(currChar)!=0) || (isdigit(currChar)!=0)){
      words[arrayIndex] = currChar;
	arrayIndex++;
	currChar=fgetc(f);
      }
      words[arrayIndex] = 0;
      printf("%s", words);
      words[0] = 0;      
    }
return 0;	
}


