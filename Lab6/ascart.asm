#include "font.h"


int asc2idx(int asc){
  int r = asc-32;
  return r;
}

void printAline(char *c , int iline){
  while(*c){
    puts(alphabet[asc2idx(*c)][iline]);
    ++c;
  }
}

void printAcharAtheight(int line , int a_c , char **a_v){
  int iarg;
  for(iarg = 1; iarg != a_c; ++iarg) {
      char *c = a_v[iarg];
      printAline(c , line);
      if(iarg!=a_c-1)
	puts(alphabet[asc2idx(' ')][line]);
  }
}  

void printArtS(int a_c , char **a_v){
  int iline;
  for(iline = 0; iline != SYMBOL_HEIGHT; ++iline){
    printAcharAtheight(iline, a_c, a_v);
    //remember to add a new line (printf("\n"));
  }
}



#define SCREEN_WIDTH 80
int main(int argc, char **argv){
  printArtS(argc, argv);
  return 0;
}
 
