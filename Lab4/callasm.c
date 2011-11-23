
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){
  int isEq;
  
  if (argc != 3){
    printf("usage: callsam <word> <word>\n");
    return 0;
  }
  
  isEq = hsvmhr(argv[1], argv[2]);
  printf("%d",isEq);
  
  return 0;
}