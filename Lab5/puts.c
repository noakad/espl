void puts(char *c){
  int size;
  size = length(c);
  return write(1,c,size);
}
